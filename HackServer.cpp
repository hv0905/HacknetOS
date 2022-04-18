//
// Created by epiphyllum on 22/04/09.
//

#include "HackServer.h"
std::string HackServer::getIp()
{
    return ip;
}
bool HackServer::checkAccessibility()
{
    if(accessible)
        return accessible;
    else
    {
        if(HTTPExist&&!HTTPLocked+!SSHLocked&&SSHExist+
        !FTPLocked&&FTPExist+!SMTPExist&&SMTPLocked>=minRequired)
            accessible= true;
        return accessible;
    }
}
int HackServer::getmissionId()
{
    return missionId;
}


