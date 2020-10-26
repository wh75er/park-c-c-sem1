cmake_minimum_required(VERSION 3.11)

project(ParallelProject VERSION 1.0
  DESCRIPTION "Mail.ru TP IZ2"
  LANGUAGES C CXX)

option(USE_PARALLEL "Use parallel implementation" OFF)
option(USE_DEBUG "Enter debug mode" OFF)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
set(PROJECT_BUILD_DIR ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DPROC_DEBUG")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wpedantic")

if (USE_DEBUG)
  add_definitions(-DDEBUG)
endif()

# Code coverage
if (CMAKE_BUILD_TYPE MATCHES Debug)
  include(CodeCoverage)
  append_coverage_compiler_flags()
  setup_target_for_coverage_gcovr_html(
    NAME coverage
    EXECUTABLE valgrind --leak-check=full --show-leak-kinds=all ${PROJECT_BUILD_DIR}/tests/mean_tests#ctest -V
    BASE_DIRECTORY "${PROJECT_SOURCE_DIR}"
    EXCLUDE "${PROJECT_SOURCE_DIR}/build/*" 
    "${PROJECT_SOURCE_DIR}/tests/*" 
    "${PROJECT_SOURCE_DIR}/main/main.c" 
    "${PROJECT_SOURCE_DIR}/src/pos.c"
    "${PROJECT_SOURCE_DIR}/src/pos_array.c"
    "${PROJECT_SOURCE_DIR}/src/args.c"
    "${PROJECT_SOURCE_DIR}/src/io.c"
    "${PROJECT_SOURCE_DIR}/src/errors_handler.c")
endif()

enable_testing()

add_subdirectory(src)
add_subdirectory(main)
add_subdirectory(tests)
