//
// Created by 16950 on 2022/4/15.
//
#ifndef HACKNETOS_HACKEMAIL_H
#define HACKNETOS_HACKEMAIL_H

#include <vector>
#include "string"
#include "MissionCheckService.h"

typedef bool (MissionCheckService::*checkMethod)();

class HackEmail
{
public:
    HackEmail(const std::wstring &title = L"", const std::wstring &sender = L"", const std::wstring &content = L"",
              int mid = 1000);

    static std::vector<const HackEmail *> getAvailMail(int missionid);

    static void cdMail(const std::wstring &title);

    const std::wstring &getEmailTitle() const;

    const std::wstring &getSender() const;

    const std::wstring &getEmailContent() const;

    int getMissionId() const;

private:
    std::wstring emailTitle;
    std::wstring sender;
    std::wstring emailContent;
    int missionId{};
};
#endif //HACKNETOS_HACKEMAIL_H
