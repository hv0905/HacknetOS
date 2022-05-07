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
    // 247.112.153.237
    //    Anderson_log->AppendFile(new HackTxtFile("@18907_Connection_From_XXX.XXX.XXX.XXX", L"Connection from [IP MASKED] established."));
    //    Anderson_log->AppendFile(new HackTxtFile("@18922_XXX.XXX.XXX.XXX_Given_Administrator_Access", L"Connection from [IP MASKED] given administrator privileges."));
    //    Anderson_log->AppendFile(new HackTxtFile("@18928_XXX.XXX.XXX.XXX_Accessed_File_[Valence_Dossier.pdf]", L"File [Valence_Dossier.pdf] was read by [IP MASKED] -- System Administrator"));
    //    Anderson_log->AppendFile(new HackTxtFile("@19002_XXX.XXX.XXX.XXX_Deleted_File_[Valence_Dossier.pdf]", L"File [Valence_Dossier.pdf] was deleted by [IP MASKED] -- System Administrator"));
    //    Anderson_log->AppendFile(new HackTxtFile("@19002_XXX.XXX.XXX.XXX_Disconnected", L"[IP MASKED] Disconnected from system"));

    auto target = ref->locateServer("247.112.153.237");
    if (!target) return true;
    auto log = target->getRootDirectory().LocateSonDir("log");
    if (!log) return true;
    if (log->LocateFile("@18907_Connection_From_XXX.XXX.XXX.XXX") != nullptr) return false;
    if (log->LocateFile("@18922_XXX.XXX.XXX.XXX_Given_Administrator_Access") != nullptr) return false;
    if (log->LocateFile("@18928_XXX.XXX.XXX.XXX_Accessed_File_[Valence_Dossier.pdf]") != nullptr) return false;
    if (log->LocateFile("@19002_XXX.XXX.XXX.XXX_Deleted_File_[Valence_Dossier.pdf]") != nullptr) return false;
    if (log->LocateFile("@19002_XXX.XXX.XXX.XXX_Disconnected") != nullptr) return false;

    return true;
}

bool MissionCheckService::check_mission_5(const std::string &)
{
    return ref->localSever->getRootDirectory().LocateSonDir("home") &&
           ref->localSever->getRootDirectory().LocateSonDir("home")->LocateFile("Entropy_Induction_Test");
}

bool MissionCheckService::check_mission_6(const std::string &)
{
    auto target = ref->locateServer("183.198.0.210");
    return target->getRootDirectory().LocateSonDir("MsgBoard") == nullptr ||
           target->getRootDirectory().LocateSonDir("MsgBoard")->LocateFile("config.sys") ==
           nullptr;
}

bool MissionCheckService::check_mission_7(const std::string &)
{
    auto bin = ref->getLocalSever()->getRootDirectory().LocateSonDir("bin");
    return bin && bin->LocateFile("ftpbounce.exe");
}

bool MissionCheckService::check_mission_8(const std::string &)
{
    auto target = ref->locateServer("38.228.127.137");
    auto pc = target->getRootDirectory().LocateSonDir("PointClicker");
    if (!pc) return true;
    auto save = pc->LocateSonDir("Save");
    if (!save) return true;
    return save->LocateFile("Mengsk.pcsav") == nullptr;
}

bool MissionCheckService::check_mission_9(const std::string &)
{
    auto target = ref->locateServer("234.228.181.58");
    auto workspace = target->getRootDirectory().LocateSonDir("WORKSPACE");
    if (!workspace) return true;
    return workspace->LocateFile("SECURE_MAILLIST.dec") == nullptr;
}

bool MissionCheckService::check_mission_10(const std::string &input)
{
    return input == "*******";
}
