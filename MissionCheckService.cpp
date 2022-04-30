//
// Created by epiphyllum on 22/04/28.
//

#include "MissionCheckService.h"
#include "HacknetApplication.h"

MissionCheckService::MissionCheckService(HacknetApplication *ref)
        :
        ref(ref)
{}

bool MissionCheckService::check_mission_1()
{
    return false;
}
