//
// Created by 16950 on 2022/4/15.
//
#include"HackEmail.h"

#include <utility>
 HackEmail:: HackEmail(std::string title,std::string sender,std::string content,int mid):
emailTitle(std::move(title)),sender(std::move(sender)),emailContent(std::move(content)),missionId(mid){};
const HackEmail Email[100]={
        HackEmail("Diana", "Diana", "Diana", 1)
};
void HackEmail::lsMail(int missionId) {
    for (const auto & i : Email)
        if (i.missionId <= missionId ) {
            //显示邮件
        }
}
void HackEmail::cdMail(const std::string& title) {
    for (const auto & i : Email)
        if (i.emailTitle == title ) {
            //显示邮件内容
        }
}



