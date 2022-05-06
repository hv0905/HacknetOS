//
// Created by 16950 on 2022/4/15.
//
#include"HackEmail.h"

HackEmail::HackEmail(const std::wstring &title, const std::wstring &sender, const std::wstring &content, int mid,
                     MissionMode mode, CheckerHandler handler) :
        emailTitle(title), sender(sender), emailContent(content), parentMissionId(mid), mode(mode), checker(handler)
{}

const std::wstring &HackEmail::getEmailTitle() const
{
    return emailTitle;
}

const std::wstring &HackEmail::getSender() const
{
    return sender;
}

const std::wstring &HackEmail::getEmailContent() const
{
    return emailContent;
}

int HackEmail::getMissionId() const
{
    return parentMissionId;
}

CheckerHandler HackEmail::getCheckerHandler() const
{
    return checker;
}

const MissionMode HackEmail::getMode() const
{
    return mode;
}

bool HackEmail::isRead() const
{
    return read;
}

void HackEmail::setRead(bool read)
{
    HackEmail::read = read;
}
