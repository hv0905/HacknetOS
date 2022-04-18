//
// Created by epiphyllum on 22/04/09.
//

#pragma once
#ifndef HACKNETOS_HACKSERVER_H
#define HACKNETOS_HACKSERVER_H

#include <string>
#include "HackDirectory.h"

class HackServer
{
    friend class HacknetApplication;
    std::string ip;
    HackDirectory directory;

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
public:

    std::string getIp();

};


#endif //HACKNETOS_HACKSERVER_H
