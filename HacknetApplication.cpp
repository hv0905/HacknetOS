//
// Created by epiphyllum on 22/04/09.
//

#include "HacknetApplication.h"
#include "Utility/Util.h"
void HacknetApplication::Exec()
{
    while (true)
    {
        Draw();
        inputService.tickInput();
        Util::sleep(50);
        if (ending)
        {
            break;
        }
    }
}

void HacknetApplication::Draw()
{

}

void HacknetApplication::lsDir()
{
    if (CurrentDir->getsubDirs().empty() && CurrentDir->getfiles().empty())
    {
        commandBuffer.emplace_back("There is no file and directory in this folder.");
        return;
    }

    commandBuffer.emplace_back("-----------------------------");
    commandBuffer.push_back("The contain of" + CurrentConnected->getIp() + "@>" + CurrentDir->getDirName());
    for (auto i: CurrentDir->getsubDirs())
    {
        commandBuffer.push_back(":" + i->getDirName());
    }
    for (auto i: CurrentDir->getfiles())
    {
        commandBuffer.push_back(":" + i->getName());
    }
    commandBuffer.emplace_back("-----------------------------");
}

void HacknetApplication::cdDir(const std::string& dirName)
{
    bool flag = false;
    for (int i=0;i<CurrentDir->getsubDirs().size();i++)
    {
        if (CurrentDir->getsubDirs()[i]->getDirName() == dirName)
        {
            flag = true;
            CurrentDir = (CurrentDir->getsubDirs()[i]);
            commandBuffer.push_back(CurrentConnected->getIp() + "@>" + dirName);
            break;
        }
    }
    if(!flag)
        commandBuffer.emplace_back("Can't find the directory.");
}

[[maybe_unused]] void HacknetApplication::rmsubDir()
{
    for (auto i:CurrentDir->getsubDirs())
    {
        commandBuffer.emplace_back("Deleting");
        commandBuffer.emplace_back(i->getDirName());
    }
    for (auto i:CurrentDir->getfiles())
    {
        commandBuffer.emplace_back("Deleting");
        commandBuffer.emplace_back(i->getName());
    }
    CurrentDir->getsubDirs().clear();
}

void HacknetApplication::rmDir(const std::string &dirName)
{
    if(CurrentDir->getsubDirs().empty())
    {
        commandBuffer.emplace_back("");
    }
    for (int i = 0; i < CurrentDir->getsubDirs().size(); i++)
    {
        if (CurrentDir->getsubDirs()[i]->getDirName() == dirName)
        {
            CurrentDir->getsubDirs().erase(CurrentDir->getsubDirs().begin() + i);
            commandBuffer.emplace_back("Deleting");
            commandBuffer.emplace_back(CurrentDir->getsubDirs()[i]->getDirName());
            break;
        }
    }
    for (int i = 0; i < CurrentDir->getfiles().size(); i++)
    {
        if (CurrentDir->getfiles()[i]->getName() == dirName)
        {
            CurrentDir->getfiles().erase(CurrentDir->getfiles().begin() + i);
            commandBuffer.emplace_back("Deleting");
            commandBuffer.emplace_back(CurrentDir->getfiles()[i]->getName());
            break;
        }
    }
}

void HacknetApplication::cdParentDir()
{
    CurrentDir = CurrentDir->getParentDir();
    commandBuffer.push_back(CurrentConnected->getIp() + "@>" + CurrentDir->getDirName());
}

void HacknetApplication::cdRootDir()
{
    CurrentDir = CurrentDir->getRootDir();
    commandBuffer.push_back(CurrentConnected->getIp() + "@>" + CurrentDir->getDirName());
}

void HacknetApplication::namp()
{
    commandBuffer.emplace_back("----------------------------------");
    commandBuffer.emplace_back("Probe Complete-Open ports:");
    commandBuffer.emplace_back("----------------------------------");
    if (CurrentConnected->HTTPExist)
    {
        commandBuffer.emplace_back("Port# 80: - HTTP WebServer: " +
                                   (std::string) ((CurrentConnected->HTTPLocked) ? "locked" : "unlocked"));
    }
    if (CurrentConnected->SMTPExist)
    {
        commandBuffer.emplace_back("Port# 25: - SMTP MailServer: " +
                                   (std::string) ((CurrentConnected->SMTPLocked) ? "locked" : "unlocked"));
    }
    if (CurrentConnected->FTPExist)
    {
        commandBuffer.emplace_back("Port# 21: - FTP Server: " +
                                   (std::string) ((CurrentConnected->FTPLocked) ? "locked" : "unlocked"));
    }
    if (CurrentConnected->SSHExist)
    {
        commandBuffer.emplace_back("Port# 22: - SSH: " +
                                   (std::string) ((CurrentConnected->SSHLocked) ? "locked" : "unlocked"));
    }
    commandBuffer.emplace_back("----------------------------------");
    commandBuffer.emplace_back("Open Ports:Required for Crack:  " + std::to_string(CurrentConnected->minRequired));
}

void HacknetApplication::command_ps()
{
    commandBuffer.emplace_back("PID    NAME");
    for (auto &item: backgroundTasks)
    {
        if (!item->isStopped())
            commandBuffer.emplace_back(std::to_string(item->getPid()) + "   " + item->getThreadName());
    }
}

void HacknetApplication::command_kill(const std::string &pid)
{
    try
    {
        int p = stoi(pid);
        auto th = std::find_if(backgroundTasks.begin(), backgroundTasks.end(), [&p](HackBackgroundTask *item)
        {
            return item->getPid() == p && !item->isStopped();
        });
        if (th == backgroundTasks.end())
        {
            commandBuffer.emplace_back("PID为 " + pid + " 的进程不存在");
        }
        else
        {
            (*th)->kill();
        }

    } catch (...)
    {
        commandBuffer.emplace_back(pid + "不是一个合法的PID.");
        return;
    }
}








