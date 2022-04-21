//
// Created by epiphyllum on 22/04/09.
//

#pragma once
#ifndef HACKNETOS_HACKNETAPPLICATION_H
#define HACKNETOS_HACKNETAPPLICATION_H

#include <thread>
#include "HackEmail.h"
#include "HackDirectory.h"
#include "HackServer.h"
#include "InputService.h"
#include "BackgroundTasks/HackBackgroundTask.h"

class HacknetApplication
{
    bool ending = false;
    int gameStatus = 0;
    bool doRender = true;

    bool requireUpdate = true;
    HackDirectory *CurrentDir;
    HackServer *CurrentConnected;
    HackServer *localSever;
    int missionId{};
    std::vector<std::string> commandBuffer{};
    InputService inputService{};
    std::vector<HackBackgroundTask *> backgroundTasks{};
    std::vector<HackServer *> serverList{};
    std::vector<std::thread *> threadPool{};

    void internalDisconnect();

    void internalConnect(HackServer *target);

    void wrapAppend(const std::string str);

    HackDirectory *locateDir(const std::string &path, bool local = false);

    HackFile *locateFile(std::string path);

public:

    virtual ~HacknetApplication();

    void Exec();

    void Draw();

    void lsDir(std::stringstream &);

    void rmAll();

    void rmDir(const std::string &dirName);

    void Scan();

    void porkHack();

    void processCommand(const std::string &command);

    [[nodiscard]] bool isEnding() const;

    void setEnding(bool ending);

    // region handler for global commands

    void command_connect(std::stringstream &ss);

    void command_ps(std::stringstream &);

    void command_kill(std::stringstream &input);

    void command_nmap(std::stringstream &);

    void command_help(std::stringstream &);

    void command_clear(std::stringstream &);

    void command_rm(std::stringstream &commandStream);

    void command_cd(std::stringstream &commandStream);

    void command_dc(std::stringstream &);

    void command_mv(std::stringstream &commandStream);

    void command_scp(std::stringstream &commandStream);

    void command_cat(std::stringstream &commandStream);

    // endregion

    // region Method for render
    void RenderStatusBar();

    void RenderTerminal();

    std::string getPrompt();
    // endregion

    friend class StarterCreator;
};

#endif //HACKNETOS_HACKNETAPPLICATION_H
