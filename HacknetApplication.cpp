//
// Created by epiphyllum on 22/04/09.
//

#include "HacknetApplication.h"
#include "Utility/Util.h"

static const HackCommand globalCommands[] = {
        HackCommand(&HacknetApplication::command_help, "help", "显示本帮助列表"),
        HackCommand(nullptr, "scp", "从远程计算机复制文件[filename]至指定本地文件夹(/home或/bin为默认)", "[filename] [OPTIONAL: dest]", true,
                    true),
        HackCommand(nullptr, "scan", "在已连接计算机上扫描链接", "", true, true),
        HackCommand(nullptr, "rm", "删除文件", "[filename (or use * for all files in the folder)]", true, true),
        HackCommand(&HacknetApplication::command_ps, "ps", "列出正在运行的程序以及它们的PID"),
        HackCommand(&HacknetApplication::command_kill, "kill", "结束进程", "[PID]"),
        HackCommand(&HacknetApplication::lsDir, "ls", "列出目录所有内容", "", true, true),
        HackCommand(&HacknetApplication::cdDir, "cd", "切换目录", "<dir>", true, true),
        HackCommand(nullptr, "mv", "移动或重命名文件", "<src> <dst>", true, true),
        HackCommand(nullptr, "connect", "连接到服务器", "<target_ip>"),
        HackCommand(nullptr, "nmap", "扫描已连接计算机的活动端口及保安级别"),
        HackCommand(nullptr, "dc", "断开连接"),
        HackCommand(nullptr, "cat", "显示文件内容", "[filename]", true, true),
        HackCommand(nullptr, "porthack", "通过已开放的端口破解计算机管理员密码"),
        HackCommand(&HacknetApplication::command_clear, "clear", "清除终端")
};

void HacknetApplication::Exec()
{
    while (true)
    {
        Draw();
        auto result = inputService.tickInput();
        if (result.has_value())
        {
            // process the incoming command
            processCommand(result.value());
        }
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

void HacknetApplication::lsDir(std::stringstream &)
{
    if (!CurrentConnected->accessible)
    {
        HacknetApplication::commandBuffer.emplace_back("The server isn't hacked.");
        return;
    }
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

void HacknetApplication::cdDir(std::stringstream &dirStream)
{
    std::string dirName;
    dirStream >> dirName;
    if (!CurrentConnected->accessible)
    {
        HacknetApplication::commandBuffer.emplace_back("The server isn't hacked.");
        return;
    }
    bool flag = false;
    for (int i = 0; i < CurrentDir->getsubDirs().size(); i++)
    {
        if (CurrentDir->getsubDirs()[i]->getDirName() == dirName)
        {
            flag = true;
            CurrentDir = (CurrentDir->getsubDirs()[i]);
            commandBuffer.push_back(CurrentConnected->getIp() + "@>" + dirName);
            break;
        }
    }
    if (!flag)
        commandBuffer.emplace_back("Can't find the directory.");
}

[[maybe_unused]] void HacknetApplication::rmSubDir()
{
    if (!CurrentConnected->accessible)
    {
        HacknetApplication::commandBuffer.emplace_back("The server isn't hacked.");
        return;
    }
    for (auto i: CurrentDir->getsubDirs())
    {
        commandBuffer.emplace_back("Deleting");
        commandBuffer.emplace_back(i->getDirName());
    }
    for (auto i: CurrentDir->getfiles())
    {
        commandBuffer.emplace_back("Deleting");
        commandBuffer.emplace_back(i->getName());
    }
    CurrentDir->getsubDirs().clear();
}

void HacknetApplication::rmDir(const std::string &dirName)
{
    if (!CurrentConnected->accessible)
    {
        HacknetApplication::commandBuffer.emplace_back("The server isn't hacked.");
        return;
    }
    if (CurrentDir->getsubDirs().empty())
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
    if (!CurrentConnected->accessible)
    {
        HacknetApplication::commandBuffer.emplace_back("The server isn't hacked.");
        return;
    }
    CurrentDir = CurrentDir->getParentDir();
    commandBuffer.push_back(CurrentConnected->getIp() + "@>" + CurrentDir->getDirName());
}

void HacknetApplication::cdRootDir()
{
    CurrentDir = CurrentDir->getRootDir();
    commandBuffer.push_back(CurrentConnected->getIp() + "@>" + CurrentDir->getDirName());
    if (!CurrentConnected->accessible)
    {
        HacknetApplication::commandBuffer.emplace_back("The server isn't hacked.");
        return;
    }
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

void HacknetApplication::command_ps(std::stringstream &)
{
    commandBuffer.emplace_back("PID    NAME");
    for (auto &item: backgroundTasks)
    {
        if (!item->isStopped())
            commandBuffer.emplace_back(std::to_string(item->getPid()) + "   " + item->getThreadName());
    }
}

void HacknetApplication::command_kill(std::stringstream &input)
{
    int p;
    input >> p;
    if (input.fail())
    {
        commandBuffer.emplace_back("输入内容不是一个合法的PID.");
        return;
    }

    auto th = std::find_if(backgroundTasks.begin(), backgroundTasks.end(), [&p](HackBackgroundTask *item)
    {
        return item->getPid() == p && !item->isStopped();
    });
    if (th == backgroundTasks.end())
    {
        commandBuffer.emplace_back("PID为 " + std::to_string(p) + " 的进程不存在");
    }
    else
    {
        (*th)->kill();
    }
}

void HacknetApplication::connect(std::string ip)
{
    HacknetApplication::commandBuffer.emplace_back("Disconnected");
    for (int i = 0; i < serverList.size(); i++)
    {
        if (serverList[i].ip == ip)
        {
            HacknetApplication::commandBuffer.emplace_back("Connection Established ::");
            HacknetApplication::commandBuffer.emplace_back(
                    "Connect To " + serverList[i].name + " in" + serverList[i].ip);
            CurrentConnected = &serverList[i];
            CurrentDir = &serverList[i].rootDirectory;
        }
    }
}

void HacknetApplication::porkHack()
{
    HacknetApplication::commandBuffer.emplace_back("PortHack Initialized --Running");
    if (CurrentConnected->checkAccessibility())
        HacknetApplication::commandBuffer.emplace_back("--PortHack Complete--");
    else
        HacknetApplication::commandBuffer.emplace_back("--PortHack Fail--");
}

void HacknetApplication::Scan()
{
    if (!CurrentConnected->accessible)
    {
        HacknetApplication::commandBuffer.emplace_back("The server isn't hacked.");
        return;
    }
    HacknetApplication::commandBuffer.emplace_back("Scanning For " + CurrentConnected->ip);
    if (CurrentConnected->ConnectedNodes.empty())
        HacknetApplication::commandBuffer.emplace_back("This node does not connect to other nodes");
    else
    {
        HacknetApplication::commandBuffer.emplace_back("The nodes connected to the node:");
        for (auto i: CurrentConnected->ConnectedNodes)
        {
            HacknetApplication::commandBuffer.emplace_back(":" + i->name + "  " + i->ip);
        }
    }
}

void HacknetApplication::processCommand(const std::string &command)
{
    std::stringstream ss(command);
    std::string prefix;
    ss >> prefix;
    // Phrase 1: global
    int globalSize = std::extent<decltype(globalCommands)>::value;
    auto globalP = std::find_if(globalCommands, globalCommands + globalSize, [&prefix](const HackCommand &cmd)
    {
        return cmd.getPrefix() == prefix;
    });

    if (globalP != globalCommands + globalSize)
    {
        auto handler = globalP->getHandler();
        if (handler != nullptr)
            (this->*handler)(ss);
        else commandBuffer.emplace_back("Not implemented yet.");
        return;
    }

    // Phrase 2: executive files TODO
}

bool HacknetApplication::isEnding() const
{
    return ending;
}

void HacknetApplication::setEnding(bool ending)
{
    HacknetApplication::ending = ending;
}

void HacknetApplication::command_help(std::stringstream &ss)
{
    int page;
    ss >> page;
    if (!ss)
    {
        page = 1;
    }

    int size = std::extent<decltype(globalCommands)>::value;
    int skip = (page - 1) * 8;
    if (skip >= size || skip < 0)
    {
        commandBuffer.emplace_back("FATAL: 不存在本帮助页面");
        return;
    }
    int end = std::min(skip + 7, size - 1);
    commandBuffer.emplace_back("------------------------------");
    for (int i = skip; i <= end; ++i)
    {
        commandBuffer.push_back(globalCommands->getPattern() + " " + globalCommands->getPrefix());
        commandBuffer.push_back(globalCommands->getHelpText());
        commandBuffer.emplace_back("");
    }
    commandBuffer.emplace_back("------------------------------");


}

void HacknetApplication::command_clear(std::stringstream &)
{
    commandBuffer.clear();
}



