cmake_minimum_required(VERSION 3.21)
project(HackNetOS)

set(CMAKE_CXX_STANDARD 17)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(HackNetOS main.cpp Util.cpp HacknetApplication.cpp HackDirectory.cpp HackFile.cpp MusicUtil.cpp MusicUtil.h)
