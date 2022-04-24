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
#include "RenderService.h"
#include "BackgroundTasks/HackBackgroundTask.h"
#include "HackCommand.h"

class HacknetApplication
{
    bool ending = false;
    int gameStatus = 0;

    HackDirectory *CurrentDir;
    HackServer *CurrentConnected;
    HackServer *localSever;
    int missionId{};
    std::vector<std::string> commandBuffer{};
    InputService inputService{};
    RenderService renderService{this};
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

    void command_ls(std::stringstream &);

    void rmAll();

    void rmDir(const std::string &dirName);

    void command_Scan(std::stringstream &s);

    void command_porthack(std::stringstream &s);

    void processCommand(const std::string &command);

    [[nodiscard]] bool isEnding() const;

    void setEnding(bool ending);

    HackServer *getCurrentConnected() const;

    const std::vector<std::string> &getCommandBuffer() const;

    std::vector<std::string> &getCommandBuffer();

    RenderService &getRenderService();

    std::string getPrompt();

    std::vector<HackCommand> getAvailExecutiveCommand();

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

    void executive_sshcrack(std::stringstream &commandStream);

    void executive_ftpbounce(std::stringstream &commandStream);

    std::string getCommandAutoComplete(const std::string &command);

    std::string getFilenameAutoComplete(const std::string &command);

    // endregion

    //region static
    static inline HacknetApplication *current = nullptr;

    friend class StarterCreator;

    friend class RenderService;

    friend class InputService;
    //endregion static
};

#endif //HACKNETOS_HACKNETAPPLICATION_H
