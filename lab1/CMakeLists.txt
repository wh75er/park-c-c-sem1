cmake_minimum_required(VERSION 3.11)

project(StructProject VERSION 1.0
  DESCRIPTION "Mail.ru TP IZ1"
  LANGUAGES C CXX)

enable_testing()

add_subdirectory(src)
add_subdirectory(main)
add_subdirectory(tests)
