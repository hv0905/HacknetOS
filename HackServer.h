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
    friend class StarterCreator;

    std::string ip;

    std::string name;

    HackDirectory rootDirectory;

    bool accessible = false;

    int minRequired;

    bool SSHLocked = true;
    bool HTTPLocked = true;
    bool FTPLocked = true;
    bool SMTPLocked = true;

    std::vector<HackServer *> ConnectedNodes;
public:

    HackServer(const std::string &ip, const std::string &name, int minRequired);

    HackServer();

    [[nodiscard]] const std::string &getIp() const;

    bool checkIfSecureBroken() const;

    const std::string &getName() const;

    bool isAccessible() const;

    bool isSshLocked() const;

    void setSshLocked(bool sshLocked);

    bool isHttpLocked() const;

    void setHttpLocked(bool httpLocked);

    bool isFtpLocked() const;

    void setFtpLocked(bool ftpLocked);

    bool isSmtpLocked() const;

    void setSmtpLocked(bool smtpLocked);

    int getMinRequired() const;

    void setMinRequired(int minRequired);

    const std::vector<HackServer *> &getConnectedNodes() const;

    std::vector<HackServer *> &getConnectedNodes();

    void setConnectedNodes(const std::vector<HackServer *> &connectedNodes);

    const HackDirectory &getRootDirectory() const;

    HackDirectory &getRootDirectory();

    void setRootDirectory(const HackDirectory &rootDirectory);

};


#endif //HACKNETOS_HACKSERVER_H
