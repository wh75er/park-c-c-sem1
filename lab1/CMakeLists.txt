cmake_minimum_required(VERSION 3.11)

project(StructProject VERSION 1.0
  DESCRIPTION "Mail.ru TP IZ1"
  LANGUAGES C CXX)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

# Добавление покрытия кода
message("CMAKE_BUILD_TYPE IS ${CMAKE_BUILD_TYPE}")
if (CMAKE_BUILD_TYPE MATCHES Debug)
  message("Inside 2")
  include(CodeCoverage)
  append_coverage_compiler_flags()
  setup_target_for_coverage_gcovr_html(
    NAME coverage
    EXECUTABLE ctest
    BASE_DIRECTORY "${PROJECT_SOURCE_DIR}"
    EXCLUDE "build/*" "tests/*")
endif()

enable_testing()

add_subdirectory(src)
add_subdirectory(main)
add_subdirectory(tests)
