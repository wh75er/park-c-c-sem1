add_library(input_lib input.c)
add_library(class_lib class.c)
add_library(pather_lib pather.c)
add_library(errors_lib errors.c)

target_include_directories(input_lib PUBLIC ../include)
target_include_directories(class_lib PUBLIC ../include)
target_include_directories(pather_lib PUBLIC ../include)
target_include_directories(errors_lib PUBLIC ../include)

target_compile_features(input_lib PUBLIC cxx_std_11)
target_compile_features(class_lib PUBLIC cxx_std_11)
target_compile_features(pather_lib PUBLIC cxx_std_11)
target_compile_features(errors_lib PUBLIC cxx_std_11)
