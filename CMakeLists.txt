cmake_minimum_required(VERSION 3.21)
project(HackNetOS)

set(CMAKE_CXX_STANDARD 17)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(HackNetOS main.cpp Utility/Util.cpp HacknetApplication.cpp HackDirectory.cpp HackFile.cpp Utility/MusicUtil.cpp Utility/MusicUtil.h InputService.cpp InputService.h AsciiArt.cpp AsciiArt.h CommonType.h CommonType.cpp HackEmail.h HackEmail.cpp Utility/UiUtil.cpp Utility/UiUtil.h BackgroundTasks/HackBackgroundTask.cpp BackgroundTasks/HackBackgroundTask.h HackServer.cpp BackgroundTasks/TutorialBgTask.cpp BackgroundTasks/TutorialBgTask.h HackCommand.cpp HackCommand.h Utility/StringUtil.cpp Utility/StringUtil.h HackTxtFile.cpp HackTxtFile.h HackBinFile.cpp HackBinFile.h)

file(COPY "ASCII" DESTINATION "./")
