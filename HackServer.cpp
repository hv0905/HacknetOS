//
// Created by epiphyllum on 22/04/09.
//

#include "HackServer.h"

const std::string &HackServer::getIp() const
{
    return ip;
}

bool HackServer::checkIfSecureBroken() const
{
    return !HTTPLocked + !SSHLocked + !FTPLocked + !SMTPLocked >= minRequired;
}

const std::string &HackServer::getName() const
{
    return name;
}

bool HackServer::isAccessible() const
{
    return accessible;
}

bool HackServer::isSshLocked() const
{
    return SSHLocked;
}

void HackServer::setSshLocked(bool sshLocked)
{
    SSHLocked = sshLocked;
}

bool HackServer::isHttpLocked() const
{
    return HTTPLocked;
}

void HackServer::setHttpLocked(bool httpLocked)
{
    HTTPLocked = httpLocked;
}

bool HackServer::isFtpLocked() const
{
    return FTPLocked;
}

void HackServer::setFtpLocked(bool ftpLocked)
{
    FTPLocked = ftpLocked;
}

bool HackServer::isSmtpLocked() const
{
    return SMTPLocked;
}

void HackServer::setSmtpLocked(bool smtpLocked)
{
    SMTPLocked = smtpLocked;
}

const std::vector<HackServer *> &HackServer::getConnectedNodes() const
{
    return ConnectedNodes;
}

std::vector<HackServer *> &HackServer::getConnectedNodes()
{
    return ConnectedNodes;
}

void HackServer::setConnectedNodes(const std::vector<HackServer *> &connectedNodes)
{
    ConnectedNodes = connectedNodes;
}

int HackServer::getMinRequired() const
{
    return minRequired;
}

void HackServer::setMinRequired(int minRequired)
{
    HackServer::minRequired = minRequired;
}

const HackDirectory &HackServer::getRootDirectory() const
{
    return rootDirectory;
}

HackDirectory &HackServer::getRootDirectory()
{
    return rootDirectory;
}

void HackServer::setRootDirectory(const HackDirectory &rootDirectory)
{
    HackServer::rootDirectory = rootDirectory;
}

HackServer::HackServer(const std::string &ip, const std::string &name, int minRequired) : ip(ip), name(name),
                                                                                          minRequired(minRequired)
{}

HackServer::HackServer()
{}

HackServer::~HackServer()
= default;

void HackServer::setAccessible(bool accessible)
{
    HackServer::accessible = accessible;
}

void HackServer::setSearchable()
{
    Searchable = true;
}

bool HackServer::isSearchable() const
{
    return Searchable;
}


