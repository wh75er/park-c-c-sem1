#include <fcntl.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>
#include <unistd.h>

#include "mean.h"

#define SEM_MUTEX_NAME "/sum-mutex"

int get_processes_number(const size_t size) {
  int n = get_nprocs();

  if (n && !(size / n)) {
    n = size;
  }

  return n;
}

int
get_sum(const struct pos * const arr, const size_t left_border, const size_t right_border, struct pos * const sum) {
  if(left_border > right_border) {
    return SUM_BORDERS_ERR;
  }

  if(!arr || !sum) {
    return SUM_PARAMS_ERR;
  }

  sum->x = 0;
  sum->y = 0;
  sum->z = 0;

  for(size_t i = left_border; i < right_border; i++) {
    sum->x += arr[i].x;
    sum->y += arr[i].y;
    sum->z += arr[i].z;
  }

  return SUCCESS;
}

int
find_mean(struct pos ** const arr, const size_t size, struct pos * const mean) {
  if(!arr || !(*arr) || !size || !mean) {
    return PARALLEL_PARAMS_ERR;
  }

  int n = 0;
  if(!(n = get_processes_number(size))) {
    return PARALLEL_PROC_BUSY_ERR;
  }

#ifdef DEBUG
  printf("Number of processes: %d\n", n);
#endif

  struct pos* shared_sum = mmap(NULL, sizeof(struct pos), 
                                PROT_READ | PROT_WRITE,
                                MAP_SHARED | MAP_ANONYMOUS,
                                -1, 0);

  if(!shared_sum) {
    return PARALLEL_SHMEM_MAP_ERR;
  }

  sem_t* mutex_sem = SEM_FAILED;
  if ((mutex_sem = sem_open(SEM_MUTEX_NAME, O_CREAT, ACCESSPERMS, 1)) == SEM_FAILED) {
      munmap(shared_sum, sizeof(struct pos));
      return PARALLEL_SEM_OPEN_ERR;
    }
  pid_t nchildren[n];
  for(size_t child_idx = 0; child_idx < n; child_idx++) {
    if((nchildren[child_idx] = fork()) < 0) {
      munmap(shared_sum, sizeof(struct pos));
      sem_close(mutex_sem);
      unlink(SEM_MUTEX_NAME);

      return PARALLEL_CHILD_CREATE_ERR;
    } else if(!nchildren[child_idx]) {
      size_t offset = size / n;

      size_t left_border = offset * child_idx;
      size_t right_border = left_border + offset;

#ifdef DEBUG
      printf("Child(%ld) left border: %ld\n", child_idx, left_border);
      printf("Child(%ld) right border: %ld\n", child_idx, right_border);
      printf("Child(%ld) offset: %ld\n", child_idx, offset);
      printf("\n");
#endif

      if(right_border > size || child_idx + 1 == n) {
        right_border = size;
      }

      struct pos sum = {0, 0, 0};
      int err = SUCCESS;
      if((err = get_sum(*arr, left_border, right_border, &sum))) {
        free(*arr);
        sem_close(mutex_sem);
        unlink(SEM_MUTEX_NAME);
        _exit(err);
      }

      sem_wait(mutex_sem);

      shared_sum->x += sum.x;
      shared_sum->y += sum.y;
      shared_sum->z += sum.z;

      if(sem_post(mutex_sem)) {
        free(*arr);
        sem_close(mutex_sem);
        unlink(SEM_MUTEX_NAME);
        _exit(PARALLEL_SEM_POST_ERR);
      };

      free(*arr);
      sem_close(mutex_sem);
      unlink(SEM_MUTEX_NAME);
      _exit(EXIT_SUCCESS);
    }
  }

  size_t count = 0; 
  int status = 0;
  while(count < n) {
    pid_t wpid = waitpid(-1, &status, 0);

    if(wpid < 0) {
      munmap(shared_sum, sizeof(struct pos));
      sem_close(mutex_sem);
      unlink(SEM_MUTEX_NAME);

      return PARALLEL_PWAIT_ERR;
    }

    if (WIFEXITED(status)) {
      int exit_status = WEXITSTATUS(status);

      if(exit_status) {
        munmap(shared_sum, sizeof(struct pos));
        sem_close(mutex_sem);
        unlink(SEM_MUTEX_NAME);

        return exit_status;
      }

      count++;
    } else {
      munmap(shared_sum, sizeof(struct pos));
      sem_close(mutex_sem);
      unlink(SEM_MUTEX_NAME);

      return PARALLEL_CHILD_FAILURE_ERR;
    }    
  }

#ifdef DEBUG
  print(stdout, shared_sum);
#endif

  mean->x = shared_sum->x / size;
  mean->y = shared_sum->y / size;
  mean->z = shared_sum->z / size;

  munmap(shared_sum, sizeof(struct pos));
  sem_close(mutex_sem);
  unlink(SEM_MUTEX_NAME);

  return SUCCESS;
}
