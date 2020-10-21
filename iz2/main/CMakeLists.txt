add_executable(main main.c)
target_include_directories(main PUBLIC ../include)

target_compile_features(main PRIVATE cxx_std_17)

#target_link_libraries(main PRIVATE input_lib)
#target_link_libraries(main PRIVATE class_lib)
#target_link_libraries(main PRIVATE pather_lib)
#target_link_libraries(main PRIVATE errors_lib)
