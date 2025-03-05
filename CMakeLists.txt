cmake_minimum_required(VERSION 3.15)
project(socketutils LANGUAGES C)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ")
message("-- Current CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("-- Current CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message("-- Current CMAKE_C_FLAGS_DEBUG: ${CMAKE_C_FLAGS_DEBUG}")
set(sources
    src/sockettee.c
    tests/socketredirector_test.c

)

set(headers
    header/sockettee.h
    header/rlutil.h

)

include_directories(socketutils PUBLIC
	${CMAKE_SOURCE_DIR}/header
)


add_executable(sockettee ${sources} ${headers})
