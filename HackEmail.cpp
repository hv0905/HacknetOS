//
// Created by 16950 on 2022/4/15.
//
#include"HackEmail.h"
HackEmail::HackEmail(const std::string &title=,const std::string &sender=,int mid,bool deleted):
emailTitle(title),sender(sender),missionId(mid),deleted(deleted)
{};
const HackEmail Email[100]={
        HackEmail("Diana","Diana",1,0)
};
void HackEmail::lsMail(int missionId){
    for(int i=0;i<100;i++)
        if(Email[i].missionId<=missionId&&Email[i].deleted==0){
            //显示邮件
            }
}
void HackEmail::cdMail(const std::string& title) {
    for(int i=0;i<100;i++)
        if(Email[i].emailTitle==title&&Email[i].deleted==0){
            //显示邮件内容
        }
}


