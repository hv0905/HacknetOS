//
// Created by epiphyllum on 22/04/28.
//

#ifndef HACKNETOS_MISSIONCHECKSERVICE_H
#define HACKNETOS_MISSIONCHECKSERVICE_H

class __single_inheritance HacknetApplication;


class MissionCheckService
{
    HacknetApplication *ref;

    bool check_mission_1();

public:
    MissionCheckService(HacknetApplication *ref);
};


#endif //HACKNETOS_MISSIONCHECKSERVICE_H
