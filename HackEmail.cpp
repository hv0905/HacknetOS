//
// Created by 16950 on 2022/4/15.
//
#include"HackEmail.h"

#include <utility>

HackEmail::HackEmail(const std::string &title, const std::string &sender, const std::string &content, int mid) :
        emailTitle(title), sender(sender), emailContent(content), missionId(mid)
{};
const HackEmail Email[] = {
        HackEmail("Diana", "Diana", "Diana", 1)
};
 std::string displayedEmail[1000];
void HackEmail::lsMail(int missionId)
{
    int pos=0;
    for (const auto &i: Email)
    {
        if (i.missionId <= missionId)
        {
            if(pos>=40)
                break;
            displayedEmail[pos++]=i.emailTitle;
        }
    }
}

void HackEmail::cdMail(const std::string &title)
{
    for (const auto &i: Email)
        if (i.emailTitle == title)
        {
            displayedEmail[0]=i.emailTitle;
            displayedEmail[1]=i.sender;
            int pos=2;
            int num=60;
                int len=i.emailContent.length();//字符串长度
                int end=num;//分割定长大小
               std:: string s;
                for(int start=0;start<len;)
                {
                    if(start>len)
                    {
                        break;
                    }
                    s=i.emailContent.substr(start,num);//从0开始，分割num位字符串
                    start=end;
                    end=end+num;
                    displayedEmail[pos++]=s;
                }
                break;
        }
}



