//
// Created by 16950 on 2022/4/15.
//

#ifndef HACKNETOS_HACKEMAIL_H
#define HACKNETOS_HACKEMAIL_H
#include "string"
class HackEmail
{
public:
HackEmail(const string &title,const string &sender);
void lsMail(int missionid);
voide cdMail(int id);
private:
   string mailTitle;
string sender;
string mailContent;
int emailId
int missionid;
bool deleted;
};
#endif //HACKNETOS_HACKEMAIL_H
