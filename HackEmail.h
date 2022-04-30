//
// Created by 16950 on 2022/4/15.
//
#ifndef HACKNETOS_HACKEMAIL_H
#define HACKNETOS_HACKEMAIL_H

#include <vector>
#include "string"
#include "MissionCheckService.h"

typedef bool (MissionCheckService::*CheckerHandler)();

enum MissionMode
{
    MODE_NO_MISSION,
    MODE_PURE_MISSION,
    MODE_REPLY_MISSION
};

class HackEmail
{
public:
    HackEmail(const std::wstring &title = L"", const std::wstring &sender = L"", const std::wstring &content = L"",
              int mid = 1000, MissionMode mode = MODE_NO_MISSION, CheckerHandler handler = nullptr);

    static std::vector<const HackEmail *> getAvailMail(int missionid);

    [[nodiscard]] const std::wstring &getEmailTitle() const;

    [[nodiscard]] const std::wstring &getSender() const;

    [[nodiscard]] const std::wstring &getEmailContent() const;

    [[nodiscard]] int getMissionId() const;

private:
    const std::wstring emailTitle;
    const std::wstring sender;
    const std::wstring emailContent;
    const int parentMissionId{};
    const MissionMode mode{};
    const CheckerHandler checker;
};
#endif //HACKNETOS_HACKEMAIL_H
