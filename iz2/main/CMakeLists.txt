add_executable(main main.c)
target_include_directories(main PUBLIC ../include)

target_compile_features(main PRIVATE cxx_std_17)

target_link_libraries(main PRIVATE args_lib)
target_link_libraries(main PRIVATE errors_lib)
target_link_libraries(main PRIVATE pos_lib)
target_link_libraries(main PRIVATE io_lib)
