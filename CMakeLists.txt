cmake_minimum_required(VERSION 3.21)
project(HackNetOS)

set(CMAKE_CXX_STANDARD 17)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(HackNetOS
        main.cpp Utility/Util.cpp HacknetApplication.cpp HacknetApplication.h HackServer.cpp HackServer.h HackDirectory.cpp HackDirectory.h HackFile.cpp HackFile.h Utility/MusicUtil.cpp Utility/MusicUtil.h InputService.cpp InputService.h AsciiArt.cpp AsciiArt.h CommonType.h CommonType.cpp HackEmail.h HackEmail.cpp Utility/UiUtil.cpp Utility/UiUtil.h BackgroundTasks/HackBackgroundTask.cpp BackgroundTasks/HackBackgroundTask.h BackgroundTasks/TutorialBgTask.cpp BackgroundTasks/TutorialBgTask.h HackCommand.cpp HackCommand.h Utility/StringUtil.cpp Utility/StringUtil.h HackTxtFile.cpp HackTxtFile.h HackBinFile.cpp HackBinFile.h StarterCreator.cpp StarterCreator.h BackgroundTasks/PortHackBackgroundTask.cpp BackgroundTasks/PortHackBackgroundTask.h AsciiAnimation.cpp AsciiAnimation.h RenderService.cpp RenderService.h BackgroundTasks/SshCrackBgTask.cpp BackgroundTasks/SshCrackBgTask.h BackgroundTasks/FtpBounceBgTask.cpp BackgroundTasks/FtpBounceBgTask.h)

file(COPY "ASCII" DESTINATION "./")
