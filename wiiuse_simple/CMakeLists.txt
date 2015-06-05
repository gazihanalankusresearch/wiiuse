
if(WIN32)
	set(CMAKE_DEBUG_POSTFIX _debug)
endif()

# I'm not sure if this is necessary here. I don't know much about CMake. Will test only on Win8.1
add_definitions(-DWIIUSE_SIMPLE_COMPILE_LIB)

include_directories(../src)

add_library(wiiuse_simple SHARED wiiuse_simple.c wiiuse_simple.h)

target_link_libraries(wiiuse_simple wiiuse)

