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


add_executable(testlib testlib.cpp)
target_compile_features(testlib PRIVATE cxx_std_17)

target_link_libraries(testlib PRIVATE input_lib class_lib pather_lib gtest gtest_main)

add_test(NAME IzTest COMMAND testlib)
