cmake_minimum_required(VERSION 3.21)
project(HackNetOS)

set(CMAKE_CXX_STANDARD 17)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(HackNetOS
        src/main.cpp src/Utility/Util.cpp src/HacknetApplication.cpp src/HacknetApplication.h src/HackServer.cpp src/HackServer.h src/HackDirectory.cpp src/HackDirectory.h src/HackFile.cpp src/HackFile.h src/Utility/MusicUtil.cpp src/Utility/MusicUtil.h src/InputService.cpp src/InputService.h src/AsciiArt.cpp src/AsciiArt.h src/CommonType.h src/CommonType.cpp src/HackEmail.h src/HackEmail.cpp src/Utility/UiUtil.cpp src/Utility/UiUtil.h src/BackgroundTasks/HackBackgroundTask.cpp src/BackgroundTasks/HackBackgroundTask.h src/BackgroundTasks/TutorialBgTask.cpp src/BackgroundTasks/TutorialBgTask.h src/HackCommand.cpp src/HackCommand.h src/Utility/StringUtil.cpp src/Utility/StringUtil.h src/HackTxtFile.cpp src/HackTxtFile.h src/HackExecutiveFile.cpp src/HackExecutiveFile.h src/StarterCreator.cpp src/StarterCreator.h src/BackgroundTasks/PortHackBackgroundTask.cpp src/BackgroundTasks/PortHackBackgroundTask.h src/AsciiAnimation.cpp src/AsciiAnimation.h src/RenderService.cpp src/RenderService.h src/BackgroundTasks/SshCrackBgTask.cpp src/BackgroundTasks/SshCrackBgTask.h src/BackgroundTasks/FtpBounceBgTask.cpp src/BackgroundTasks/FtpBounceBgTask.h src/HackMenuPanel.cpp src/HackMenuPanel.h src/HackMailViewer.cpp src/HackMailViewer.h src/MissionCheckService.cpp src/MissionCheckService.h src/HackBinaryFile.cpp src/HackBinaryFile.h src/BackgroundTasks/ShellBgTask.cpp src/BackgroundTasks/ShellBgTask.h)

file(COPY "ASCII" DESTINATION "./")
