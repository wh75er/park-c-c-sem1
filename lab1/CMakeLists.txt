cmake_minimum_required(VERSION 3.7)

if(${CMAKE_VERSION} VERSION_LESS 3.18)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
  cmake_policy(VERSION 3.18)
endif()

project(StructProject VERSION 1.0
  DESCRIPTION "Mail.ru TP IZ1"
  LANGUAGES C CXX)

add_subdirectory(src)
add_subdirectory(main)

