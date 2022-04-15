//
// Created by 16950 on 2022/4/15.
//
#ifndef HACKNETOS_HACKEMAIL_H
#define HACKNETOS_HACKEMAIL_H
#include "string"
class HackEmail {
public:
    explicit HackEmail(std::string title = "", std::string sender = "", std::string content = "",
              int mid = 1000, bool deleted = 1);

    static void lsMail(int missionId);

    static void cdMail(const std::string &title);

private:
    std::string emailTitle;
    std::string sender;
    std::string emailContent;
    int missionId;
    bool deleted;
};
#endif //HACKNETOS_HACKEMAIL_H
