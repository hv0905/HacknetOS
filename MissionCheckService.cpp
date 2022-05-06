//
// Created by epiphyllum on 22/04/28.
//

#include "MissionCheckService.h"
#include "HacknetApplication.h"

MissionCheckService::MissionCheckService(HacknetApplication *ref)
        :
        ref(ref)
{}

bool MissionCheckService::check_mission_1(const std::string &)
{
    return ref->localSever->getRootDirectory().LocateSonDir("bin")->LocateFile("SecurityTracer.exe") == nullptr;
}

bool MissionCheckService::check_mission_2(const std::string &)
{
    return ref->localSever->getRootDirectory().LocateSonDir("bin")->LocateFile("sshcrack.exe") != nullptr;
}

bool MissionCheckService::check_mission_3(const std::string &)
{
    auto target = ref->locateServer("210.175.139.250");
    return target && target->isAccessible();
}

bool MissionCheckService::check_mission_4(const std::string &)
{
    return false;
}
