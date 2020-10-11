include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

FetchContent_MakeAvailable(googletest)

set(LIBS pather_lib input_lib class_lib gtest gtest_main)

file(GLOB tests "${PROJECT_SOURCE_DIR}/tests/*.cpp")

foreach(file ${tests})
  set(name)
  get_filename_component(name ${file} NAME_WE)
  add_executable("${name}_tests"
    ${sources}
    ${file})
  target_link_libraries("${name}_tests" ${LIBS})
  add_test(NAME ${name} COMMAND "${name}_tests")
endforeach()

#add_executable(testinput input.cpp)
#target_compile_features(testinput PRIVATE cxx_std_17)

#target_link_libraries(testinput PRIVATE input_lib class_lib pather_lib gtest gtest_main)

#add_test(NAME input COMMAND testinput)
