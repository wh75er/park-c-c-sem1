include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

FetchContent_MakeAvailable(googletest)

set(LIBS pos gtest gtest_main)
set(PARALLEL_LIBS parallel_mean ${LIBS})
set(NAIVE_LIBS naive_mean ${LIBS})

file(GLOB tests "${PROJECT_SOURCE_DIR}/tests/*.cpp")

foreach(file ${tests})
  set(name)
  get_filename_component(name ${file} NAME_WE)
  add_executable("${name}_tests"
    ${sources}
    ${file})
  target_link_libraries("${name}_tests" ${PARALLEL_LIBS})
  if("${name}" STREQUAL "mean")
    add_executable("naive_${name}_tests" 
      ${sources}
      ${file})
    target_link_libraries("naive_${name}_tests" ${NAIVE_LIBS})
    add_test(NAME naive_${name} COMMAND "naive_${name}_tests")
    add_test(NAME parallel_${name} COMMAND "${name}_tests")
  else()
    add_test(NAME ${name} COMMAND "${name}_tests")
  endif()
endforeach()
