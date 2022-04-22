//
// Created by epiphyllum on 22/04/20.
//

#include "StarterCreator.h"
#include "HackTxtFile.h"

HacknetApplication *StarterCreator::createStarterOS()
{
    auto app = new HacknetApplication();
    auto *local = new HackServer("127.0.0.1", "Aiden Pearce", 0);
    auto local_home = new HackDirectory("home");
    local_home->AppendDirectory(new HackDirectory("Sub1"));
    local_home->AppendFile(new HackTxtFile("file1.txt", L"Hello World!"));
    local_home->AppendFile(new HackTxtFile("file2.txt", L"Hello World!"));
    local_home->AppendFile(new HackTxtFile("file3.txt", L"Hello World!"));

    local->getRootDirectory().AppendDirectory(local_home);
    local->getRootDirectory().AppendDirectory(new HackDirectory("bin"));
    local->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    local->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    local->accessible = true;
    app->serverList.push_back(local);
    app->localSever = app->serverList[0];

    // Add Servers, Directories, and Files here...

    return app;
}
