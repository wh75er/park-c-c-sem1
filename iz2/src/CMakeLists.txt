add_library(pos_lib pos.c)
add_library(args_lib args.c)
add_library(io_lib io.c)
add_library(errors_lib errors_handler.c)

target_include_directories(pos_lib PUBLIC ../include)
target_include_directories(args_lib PUBLIC ../include)
target_include_directories(io_lib PUBLIC ../include)
target_include_directories(errors_lib PUBLIC ../include)

target_compile_features(pos_lib PUBLIC cxx_std_11)
target_compile_features(args_lib PUBLIC cxx_std_11)
target_compile_features(io_lib PUBLIC cxx_std_11)
target_compile_features(errors_lib PUBLIC cxx_std_11)
