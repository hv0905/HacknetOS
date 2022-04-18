//
// Created by epiphyllum on 22/04/09.
//

#pragma once
#ifndef HACKNETOS_HACKSERVER_H
#define HACKNETOS_HACKSERVER_H

#include <string>
#include "HackDirectory.h"
class HacknetApplication;
class HackServer
{
    friend class HacknetApplication;

    std::string ip;

    std::string name;

    HackDirectory rootDirectory;

    bool accessible;

    int minRequired;

    bool SSHExist;
    bool FTPExist;
    bool HTTPExist;
    bool SMTPExist;

    bool SSHLocked;
    bool HTTPLocked;
    bool FTPLocked;
    bool SMTPLocked;

    int missionId;

    std::vector<HackServer*>ConnectedNodes;
public:

    std::string getIp();

    bool checkAccessibility();

    int getmissionId();
};


#endif //HACKNETOS_HACKSERVER_H
