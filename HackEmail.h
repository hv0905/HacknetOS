//
// Created by 16950 on 2022/4/15.
//

#ifndef HACKNETOS_HACKEMAIL_H
#define HACKNETOS_HACKEMAIL_H
#include "string"
class HackEmail
{
public:
HackEmail(const std::string &title="",const std::string &sender="",int mid=0,bool deleted=1);
void lsMail(int missionId);
void cdMail(const std::string &title);
private:
   std::string emailTitle;
std::string sender;
std::string emailContent;
 int missionId;
bool deleted;
};
#endif //HACKNETOS_HACKEMAIL_H
