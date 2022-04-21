//
// Created by epiphyllum on 22/04/20.
//

#include "StarterCreator.h"

HacknetApplication *StarterCreator::createStarterOS()
{
    auto app = new HacknetApplication();
    auto *local = new HackServer("127.0.0.1", "Aiden Pearce", 4);
    local->getRootDirectory().AppendDirectory(new HackDirectory("home"));
    local->getRootDirectory().AppendDirectory(new HackDirectory("bin"));
    local->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    local->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    local->accessible = true;
    app->serverList.push_back(local);
    app->localSever = app->serverList[0];

    // Add Servers, Directories, and Files here...

    return app;
}