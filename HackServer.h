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
    friend class StarterCreator;

    std::string ip;

    std::string name;

    HackDirectory rootDirectory;

    bool accessible = false;

    int minRequired{};

    bool SSHLocked = true;
    bool HTTPLocked = true;
    bool FTPLocked = true;
    bool SMTPLocked = true;

    std::vector<HackServer *> ConnectedNodes;

    bool Searchable= false;
public:

    HackServer(const std::string &ip, const std::string &name, int minRequired);

    HackServer();

    virtual ~HackServer();

    [[nodiscard]] const std::string &getIp() const;

    [[nodiscard]] bool checkIfSecureBroken() const;

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] bool isAccessible() const;

    [[nodiscard]] bool isSshLocked() const;

    void setSshLocked(bool sshLocked);

    [[nodiscard]] bool isHttpLocked() const;

    void setHttpLocked(bool httpLocked);

    [[nodiscard]] bool isFtpLocked() const;

    void setFtpLocked(bool ftpLocked);

    [[nodiscard]] bool isSmtpLocked() const;

    void setSmtpLocked(bool smtpLocked);

    [[nodiscard]] int getMinRequired() const;

    void setMinRequired(int minRequired);

    [[nodiscard]] const std::vector<HackServer *> &getConnectedNodes() const;

    [[nodiscard]] std::vector<HackServer *> &getConnectedNodes();

    void setConnectedNodes(const std::vector<HackServer *> &connectedNodes);

    [[nodiscard]] const HackDirectory &getRootDirectory() const;

    [[nodiscard]] HackDirectory &getRootDirectory();

    void setRootDirectory(const HackDirectory &rootDirectory);

    void setAccessible(bool accessible);

    void setSearchable();

};


#endif //HACKNETOS_HACKSERVER_H
