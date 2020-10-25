cmake_minimum_required(VERSION 3.11)

project(ParallelProject VERSION 1.0
  DESCRIPTION "Mail.ru TP IZ2"
  LANGUAGES C CXX)

option(USE_PARALLEL "Using parallel implementation" OFF)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DPROC_DEBUG")

# Добавление покрытия кода
include(CodeCoverage)
append_coverage_compiler_flags()
setup_target_for_coverage_gcovr_html(
  NAME coverage
  EXECUTABLE valgrind --leak-check=full --show-leak-kinds=all ctest
  BASE_DIRECTORY "${PROJECT_SOURCE_DIR}"
  EXCLUDE "${PROJECT_SOURCE_DIR}/build/*" 
  "${PROJECT_SOURCE_DIR}/tests/*" 
  "${PROJECT_SOURCE_DIR}/main/main.c" 
  "${$PROJECT_SOURCE_DIR}/src/errors.c")

enable_testing()

add_subdirectory(src)
add_subdirectory(main)
#add_subdirectory(tests)
