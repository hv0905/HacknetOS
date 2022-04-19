//
// Created by epiphyllum on 22/04/09.
//

#include "HackCommand.h"
#include "HacknetApplication.h"
#include "Utility/Util.h"
#include "Utility/UiUtil.h"
#include "Utility/StringUtil.h"

const HackCommand globalCommands[] = {
        HackCommand(&HacknetApplication::command_help, "help", "显示本帮助列表"),
        HackCommand(&HacknetApplication::command_scp, "scp", "从远程计算机复制文件[filename]至指定本地文件夹(/home或/bin为默认)",
                    "[filename] [OPTIONAL: dest]", true,
                    true),
        HackCommand(&HacknetApplication::command_connect, "scan", "在已连接计算机上扫描链接", "", true, true),
        HackCommand(&HacknetApplication::command_rm, "rm", "删除文件", "[filename (or use * for all files in the folder)]",
                    true, true),
        HackCommand(&HacknetApplication::command_ps, "ps", "列出正在运行的程序以及它们的PID"),
        HackCommand(&HacknetApplication::command_kill, "kill", "结束进程", "[PID]"),
        HackCommand(&HacknetApplication::lsDir, "ls", "列出目录所有内容", "", true, true),
        HackCommand(&HacknetApplication::cdDir, "cd", "切换目录", "<dir>", true, true),
        HackCommand(&HacknetApplication::command_mv, "mv", "移动或重命名文件", "<src> <dst>", true, true),
        HackCommand(&HacknetApplication::command_connect, "connect", "连接到服务器", "<target_ip>"),
        HackCommand(&HacknetApplication::command_nmap, "nmap", "扫描已连接计算机的活动端口及保安级别"),
        HackCommand(&HacknetApplication::command_dc, "dc", "断开连接"),
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
    Util::clearScreen();
    UIUtil::drawFramework();
}

void HacknetApplication::lsDir(std::stringstream &)
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

void HacknetApplication::cdDir(std::stringstream &dirStream)
{
    std::string dirName;
    dirStream >> dirName;
    bool flag = false;
    for (int i = 0; i < CurrentDir->getsubDirs().size(); i++)
    {
        if (CurrentDir->getsubDirs()[i]->getDirName() == dirName)
        {
            flag = true;
            CurrentDir = (CurrentDir->getsubDirs()[i]);
            break;
        }
    }
    if (!flag)
        commandBuffer.emplace_back("Can't find the directory.");
}

[[maybe_unused]] void HacknetApplication::rmSubDir()
{
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
    CurrentDir->getfiles().clear();
}

void HacknetApplication::rmDir(const std::string &dirName)
{
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
            return;
        }
    }
    for (int i = 0; i < CurrentDir->getfiles().size(); i++)
    {
        if (CurrentDir->getfiles()[i]->getName() == dirName)
        {
            CurrentDir->getfiles().erase(CurrentDir->getfiles().begin() + i);
            commandBuffer.emplace_back("Deleting");
            commandBuffer.emplace_back(CurrentDir->getfiles()[i]->getName());
            return;
        }
    }
}

void HacknetApplication::cdParentDir()
{
    CurrentDir = CurrentDir->getParentDir();
}

void HacknetApplication::cdRootDir()
{
    CurrentDir = CurrentDir->getRootDir();
}

void HacknetApplication::command_nmap(std::stringstream &)
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

void HacknetApplication::command_connect(std::stringstream &ss)
{
    std::string ip;
    ss >> ip;
    if (CurrentDir == nullptr || CurrentConnected == nullptr);
    else
        internalDisconnect();
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

void HacknetApplication::command_rm(std::stringstream &commandStream)
{
    std::string command;
    commandStream >> command;
    if (command == "*")
        rmSubDir();
    else
        rmDir(command);
}

void HacknetApplication::command_cd(std::stringstream &commandStream)
{
    std::string command;
    commandStream >> command;
    if (command == "/")
    {
        cdRootDir();
        return;
    }
    std::vector<std::string> splitCommand;
    int start = 0, end = 0;
    for (int i = 0; i < command.size(); i++)
    {
        if (command[i] == '/')
        {
            splitCommand.push_back(command.substr(start, end - start));
            start = end + 1;
        }
        end++;
    }
    splitCommand.push_back(command.substr(start, end - start));
    for (auto i: splitCommand)
    {
        if (i == "..")
            cdParentDir();
        else
        {
            std::stringstream subCommandStream;
            subCommandStream << i;
            cdDir(subCommandStream);
        }
    }
}

void HacknetApplication::command_dc(std::stringstream &)
{
    internalDisconnect();
}

void HacknetApplication::command_mv(std::stringstream &commandStream)
{
    std::string firstCommand, secondCommand;
    commandStream >> firstCommand >> secondCommand;
    if (secondCommand.empty() || firstCommand.empty())
    {
        commandBuffer.emplace_back("Enter the wrong command");
        return;
    }
    else
    {
        for (int i = 0; i < CurrentDir->getsubDirs().size(); i++)
        {
            if (CurrentDir->getsubDirs()[i]->getDirName() == firstCommand)
            {
                if (secondCommand == "..")
                {
                    commandBuffer.emplace_back("Move the file to its superior directory");
                    CurrentDir->getParentDir()->getsubDirs().push_back(CurrentDir->getsubDirs()[i]);
                    CurrentDir->getsubDirs().erase(CurrentDir->getsubDirs().begin() + i);
                }
                else
                {
                    CurrentDir->getsubDirs()[i]->setDirName(secondCommand);
                    commandBuffer.emplace_back("Rename " + firstCommand + " to " + secondCommand);
                }
                return;
            }
        }
        for (int i = 0; i < CurrentDir->getfiles().size(); i++)
        {
            if (CurrentDir->getfiles()[i]->getName() == firstCommand)
            {
                if (secondCommand == "..")
                {
                    CurrentDir->getParentDir()->getfiles().push_back(CurrentDir->getfiles()[i]);
                    CurrentDir->getfiles().erase(CurrentDir->getfiles().begin() + i);
                    commandBuffer.emplace_back("Move the file to its superior directory");
                }
                else
                {
                    CurrentDir->getfiles()[i]->setName(secondCommand);
                    commandBuffer.emplace_back("Rename " + firstCommand + " to " + secondCommand);
                }
                return;
            }
        }
    }
    commandBuffer.emplace_back("Don't find " + firstCommand);
}

void HacknetApplication::command_scp(std::stringstream &command)
{
    std::string dirName, address;
    command >> dirName;
    HackServer *tempConnect = CurrentConnected;
    HackDirectory *tempDirectory = CurrentDir;
    HackFile *copied;
    for (int i = 0; i < CurrentDir->getfiles().size(); i++)
    {
        if (CurrentDir->getfiles()[i]->getName() == dirName)
        {
            copied = CurrentDir->getfiles()[i]->clone();
            CurrentConnected = localSever;
            CurrentDir = &(localSever->rootDirectory);
            command_cd(command);
            CurrentDir->getfiles().push_back(copied);
        }
    }
    CurrentDir = tempDirectory;
    CurrentConnected = tempConnect;
    tempDirectory = nullptr;
    tempConnect = nullptr;
}

void HacknetApplication::internalDisconnect()
{
    CurrentDir = nullptr;
    CurrentConnected = nullptr;
    commandBuffer.emplace_back("Disconnected");
}

HackDirectory *HacknetApplication::locateDir(const std::string &path, bool local)
{
    auto vec = StringUtil::split(path, "/");
    if (vec.size() == 0)
    {
        return nullptr;
    }

    HackDirectory *head;
    if (vec[0] == "")
    {
        head = local ? &(localSever->rootDirectory) : &(CurrentConnected->rootDirectory);
        vec.erase(vec.begin());
    }
    else
    {
        head = CurrentDir;
    }

    if (vec.back() == "")
    {
        vec.pop_back();
    }

    for (auto &item: vec)
    {
        if (item == "..")
        {
            if (head->getParentDir() == nullptr)
            {
                return nullptr;
            }
            head = head->getParentDir();
        }
        else
        {
            auto it = std::find_if(head->getsubDirs().begin(), head->getsubDirs().end(), [&item](HackDirectory *t)
            {
                return t->getDirName() == item;
            });
            if (it == head->getsubDirs().end())
            {
                return nullptr;
            }
            else
            {
                head = *it;
            }
        }
    }

    return head;

}

HackFile *HacknetApplication::locateFile(std::string path)
{
    if (path.empty() || path.back() == '/')
    {
        return nullptr; // Not a valid filepath
    }

    int lastS = path.find_last_of('/');
    if (lastS == std::string::npos)
    {
        // pure file name
        auto it = std::find_if(CurrentDir->getfiles().begin(), CurrentDir->getfiles().end(), [&path](HackFile *t)
        {
            return t->getName() == path;
        });
        return it == CurrentDir->getfiles().end() ? nullptr : *it;
    }
    else if (lastS == 0)
    {
        path.erase(path.begin());
        // file in root directory
        auto it = std::find_if(CurrentConnected->rootDirectory.getfiles().begin(),
                               CurrentConnected->rootDirectory.getfiles().end(), [&path](HackFile *t)
                               {
                                   return t->getName() == path;
                               });
        return it == CurrentConnected->rootDirectory.getfiles().end() ? nullptr : *it;
    }
    else
    {
        // file in subdirectory, get the target path first
        // /home/user/file
        // 0123456789^1234
        std::string targetPath = path.substr(0, lastS);
        path.erase(0, lastS + 1);

        auto dir = locateDir(targetPath);
        if (!dir)
        {
            return nullptr;
        }

        auto it = std::find_if(dir->getfiles().begin(), dir->getfiles().end(), [&path](HackFile *t)
        {
            return t->getName() == path;
        });

        return it == dir->getfiles().end() ? nullptr : *it;
    }


}
