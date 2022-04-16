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
    std::string ip;
    HackDirectory directory;

    bool accessible;

    int minRequired;

    bool SSHExist;
    bool FTPExist;
    bool HTTPExist;
    bool HTTPSExist;

    bool SSHLocked;
    bool HTTPLocked;
    bool FTPLocked;
    bool SMTPLocked;

};


#endif //HACKNETOS_HACKSERVER_H
