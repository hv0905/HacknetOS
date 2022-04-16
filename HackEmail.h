//
// Created by 16950 on 2022/4/15.
//
#ifndef HACKNETOS_HACKEMAIL_H
#define HACKNETOS_HACKEMAIL_H
#include "string"
class HackEmail {
public:
    HackEmail(const std::wstring &title = L"", const std::wstring &sender = L"", const std::wstring &content = L"",
                         int mid = 1000);

    static void lsMail(int missionId);

    static void cdMail(const std::wstring &title);

private:
    std::wstring emailTitle;
    std::wstring sender;
    std::wstring emailContent;
    int missionId{};
};
#endif //HACKNETOS_HACKEMAIL_H
