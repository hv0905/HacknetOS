//
// Created by epiphyllum on 22/04/28.
//

#ifndef HACKNETOS_MISSIONCHECKSERVICE_H
#define HACKNETOS_MISSIONCHECKSERVICE_H

#include <string>

class __single_inheritance HacknetApplication;


class MissionCheckService
{
    HacknetApplication *ref;

public:
    MissionCheckService(HacknetApplication *ref);

    bool check_mission_1(const std::string &);

    bool check_mission_2(const std::string &);

    bool check_mission_3(const std::string &);

    bool check_mission_4(const std::string &);

    bool check_mission_5(const std::string &);

    bool check_mission_6(const std::string &);

    bool check_mission_7(const std::string &);

    bool check_mission_8(const std::string &);

    bool check_mission_9(const std::string &);

    bool check_mission_10(const std::string &);

};


#endif //HACKNETOS_MISSIONCHECKSERVICE_H
