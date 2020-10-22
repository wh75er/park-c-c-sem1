#include "mean.h"

/*
 *    Наивный метод поиска среднего каждой координаты
 * Результат складывается в структуру
*/
int
find_mean(const struct pos * const posns, const size_t size, struct pos * const mean) {
  mean->x = 0;
  mean->y = 0;
  mean->z = 0;

  for(size_t i = 0; i < size; i++) {
    mean.x += posns[i].x;
    mean.y += posns[i].y;
    mean.z += posns[i].z;
  }

  mean->x /= size;
  mean->y /= size;
  mean->z /= size;

  return 0;
}
