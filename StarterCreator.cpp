//
// Created by epiphyllum on 22/04/20.
//

#include "StarterCreator.h"
#include "HackTxtFile.h"
#include "HackBinFile.h"

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

    auto cheater_zone = new HackServer("1337.1337.1337.1337", "Cheater Zone", 0);
    auto cheater_zone_bin = new HackDirectory("bin");
    cheater_zone_bin->AppendFile(
            new HackBinFile("sshcrack.exe", HackCommand(&HacknetApplication::executive_sshcrack, "sshcrack", "-")));
    cheater_zone_bin->AppendFile(
            new HackBinFile("ftpbounce.exe", HackCommand(&HacknetApplication::executive_ftpbounce, "ftpbounce", "-")));
    cheater_zone->getRootDirectory().AppendDirectory(new HackDirectory("home"));
    cheater_zone->getRootDirectory().AppendDirectory(cheater_zone_bin);
    cheater_zone->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    cheater_zone->getRootDirectory().AppendDirectory(new HackDirectory("sys"));


    local->accessible = true;
    app->serverList.push_back(local);
    app->serverList.push_back(cheater_zone);
    app->localSever = app->serverList[0];

    // Add Servers, Directories, and Files here...

    return app;
}
