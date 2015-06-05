include_directories(../src ../wiiuse_simple)
add_executable(wiiuse_simple_example wiiuse_simple_example.c)
target_link_libraries(wiiuse_simple_example wiiuse wiiuse_simple)
