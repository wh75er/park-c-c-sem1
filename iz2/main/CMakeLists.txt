add_executable(main main.c)
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_features(main PRIVATE cxx_std_17)

target_link_libraries(main PRIVATE naive_mean)
target_link_libraries(main PRIVATE args)
target_link_libraries(main PRIVATE errors)
target_link_libraries(main PRIVATE pos)
target_link_libraries(main PRIVATE io)
