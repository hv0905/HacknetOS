//
// Created by epiphyllum on 22/04/09.
//

#include <iostream>
#include <ctime>
#include "HackCommand.h"
#include "HacknetApplication.h"
#include "Utility/Util.h"
#include "Utility/UiUtil.h"
#include "Utility/StringUtil.h"
#include "AsciiArt.h"
#include "HackTxtFile.h"
#include <algorithm>

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
        HackCommand(&HacknetApplication::command_cd, "cd", "切换目录", "<dir>", true, true),
        HackCommand(&HacknetApplication::command_mv, "mv", "移动或重命名文件", "<src> <dst>", true, true),
        HackCommand(&HacknetApplication::command_connect, "connect", "连接到服务器", "<target_ip>"),
        HackCommand(&HacknetApplication::command_nmap, "nmap", "扫描已连接计算机的活动端口及保安级别"),
        HackCommand(&HacknetApplication::command_dc, "dc", "断开连接"),
        HackCommand(&HacknetApplication::command_cat, "cat", "显示文件内容", "[filename]", true, true),
        HackCommand(nullptr, "porthack", "通过已开放的端口破解计算机管理员密码"),
        HackCommand(&HacknetApplication::command_clear, "clear", "清除终端")
};

const AsciiArt serverLogos[] = {
        AsciiArt("ASCII/laptop.ascii"),
        AsciiArt("ASCII/server.ascii"),
};

void HacknetApplication::Exec()
{
    // First, connect to local server
    internalConnect(localSever);
    inputService.setAcceptCommand(true);
    while (true)
    {
        Draw();
        auto result = inputService.tickInput();
        if (result.has_value())
        {
            // process the incoming command
            processCommand(result.value());
            requireUpdate = true;
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
    if (requireUpdate)
    {
        Util::clearScreen();
        UIUtil::drawFramework();
        RenderStatusBar();
    }
    RenderTerminal();

    requireUpdate = false;
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

void HacknetApplication::rmAll()
{
    while (!CurrentDir->getsubDirs().empty())
    {
        commandBuffer.emplace_back("Deleting");
        commandBuffer.emplace_back(CurrentDir->getsubDirs().back()->getDirName());
        delete CurrentDir->getsubDirs().back();
        CurrentDir->getsubDirs().pop_back();
    }

    while (!CurrentDir->getfiles().empty())
    {
        commandBuffer.emplace_back("Deleting");
        commandBuffer.emplace_back(CurrentDir->getfiles().back()->getName());
        delete CurrentDir->getfiles().back();
        CurrentDir->getfiles().pop_back();
    }
}

void HacknetApplication::rmDir(const std::string &dirName)
{
    auto dir = locateDir(dirName);
    auto file = locateFile(dirName);
    if (file != nullptr)
    {
        commandBuffer.emplace_back("Deleting");
        commandBuffer.emplace_back(file->getName());
        HackDirectory *parentDir = file->getParentDir();
        parentDir->getfiles().erase(find(parentDir->getfiles().begin(), parentDir->getfiles().end(), file));
        delete file;
    }
    else if (dir != nullptr)
    {
        commandBuffer.emplace_back("Deleting");
        commandBuffer.emplace_back(dir->getDirName());
        HackDirectory *parentDir = dir->getParentDir();
        parentDir->getsubDirs().erase
                (find(parentDir->getsubDirs().begin(), parentDir->getsubDirs().end(), dir));
        delete dir;
    }
    else
    {
        commandBuffer.emplace_back("There is not such a file or directory");
    }
}

void HacknetApplication::command_nmap(std::stringstream &)
{
    commandBuffer.emplace_back("----------------------------------");
    commandBuffer.emplace_back("Probe Complete-Open ports:");
    commandBuffer.emplace_back("----------------------------------");
    commandBuffer.emplace_back("Port# 80: - HTTP WebServer: " +
                               (std::string) ((CurrentConnected->isHttpLocked()) ? "locked" : "unlocked"));
    commandBuffer.emplace_back("Port# 25: - SMTP MailServer: " +
                               (std::string) ((CurrentConnected->isSmtpLocked()) ? "locked" : "unlocked"));
    commandBuffer.emplace_back("Port# 21: - FTP Server: " +
                               (std::string) ((CurrentConnected->isFtpLocked()) ? "locked" : "unlocked"));
    commandBuffer.emplace_back("Port# 22: - SSH: " +
                               (std::string) ((CurrentConnected->isSshLocked()) ? "locked" : "unlocked"));
    commandBuffer.emplace_back("----------------------------------");
    commandBuffer.emplace_back("Open Ports:Required for Crack:  " + std::to_string(CurrentConnected->getMinRequired()));
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
    auto it = std::find_if(serverList.begin(), serverList.end(), [&ip](HackServer *t)
    {
        return t->getIp() == ip;
    });
    if (it == serverList.end())
    {
        commandBuffer.emplace_back("Don't find such server.");
    }
    else
    {
        internalConnect(*it);
    }
}

void HacknetApplication::porkHack()
{
    HacknetApplication::commandBuffer.emplace_back("PortHack Initialized --Running");
    if (CurrentConnected->checkIfSecureBroken())
        HacknetApplication::commandBuffer.emplace_back("--PortHack Complete--");
    else
        HacknetApplication::commandBuffer.emplace_back("--PortHack Fail--");
}

void HacknetApplication::Scan()
{
    HacknetApplication::commandBuffer.emplace_back("Scanning For " + CurrentConnected->getIp());
    if (CurrentConnected->getConnectedNodes().empty())
        HacknetApplication::commandBuffer.emplace_back("This node does not connect to other nodes");
    else
    {
        HacknetApplication::commandBuffer.emplace_back("The nodes connected to the node:");
        for (auto i: CurrentConnected->getConnectedNodes())
        {
            HacknetApplication::commandBuffer.emplace_back(":" + i->getName() + "  " + i->getIp());
        }
    }
}

void HacknetApplication::processCommand(const std::string &command)
{
    commandBuffer.push_back(getPrompt() + command);
    std::stringstream ss(command);
    std::string prefix;
    ss >> prefix;
    // Phrase 1: global
    int globalSize = std::extent<decltype(globalCommands)>::value;
    auto targetCommand = std::find_if(globalCommands, globalCommands + globalSize, [&prefix](const HackCommand &cmd)
    {
        return cmd.getPrefix() == prefix;
    });

    if (targetCommand == globalCommands + globalSize)
    {
        targetCommand = nullptr;
    }

    // Phrase 2: executive files TODO
    if (targetCommand != nullptr)
    {

    }

    // Phrase 3: exec
    if (targetCommand != nullptr)
    {
        // check permission
        if (targetCommand->isRequiredHacked())
        {
            if (CurrentConnected == nullptr)
            {
                internalConnect(localSever);
            }
            else if (!CurrentConnected->isAccessible())
            {
                commandBuffer.emplace_back("Fatal: require admin access.");
                return;
            }
        }
        if (targetCommand->isShouldLog())
        {
            std::string logString = std::to_string(time(nullptr));
            logString += "@" + localSever->getIp() + "@" + command;
            std::wstring logContent = StringUtil::s2ws(logString);
            std::replace(logString.begin(), logString.end(), ' ', '_');
            CurrentConnected->getRootDirectory().LocateOrCreateSonDir("log")->AppendFile(
                    new HackTxtFile(logString, logContent));
        }
        auto handler = targetCommand->getHandler();
        if (handler != nullptr)
            (this->*handler)(ss);
        else commandBuffer.emplace_back("Not implemented yet.");
        return;
    }

    commandBuffer.emplace_back("Command not found. Check syntax.");
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
    commandBuffer.emplace_back(
            "显示帮助列表的第" + std::to_string(page) + "/" + std::to_string(size / 8 + (size % 8 ? 1 : 0)) + "页");
    commandBuffer.emplace_back("------------------------------");
    for (int i = skip; i <= end; ++i)
    {
        commandBuffer.push_back(globalCommands[i].getPrefix() + " " + globalCommands[i].getPattern());
        commandBuffer.push_back(globalCommands[i].getHelpText());
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
        rmAll();
    else
        rmDir(command);
}

void HacknetApplication::command_cd(std::stringstream &commandStream)
{
    std::string command;
    commandStream >> command;
    if (locateDir(command) != nullptr)
        CurrentDir = locateDir(command);
    else
        commandBuffer.emplace_back("There is no such directory here");
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
    auto dir = locateDir(firstCommand);
    auto file = locateFile(firstCommand);
    if (file != nullptr)
    {
        if (secondCommand == "..")
        {
            HackDirectory *parentDir = file->getParentDir();
            parentDir->getfiles().erase
                    (find(parentDir->getfiles().begin(), parentDir->getfiles().end(), file));
            parentDir->getParentDir()->getfiles().push_back(file);
        }
        else
        {
            file->setName(secondCommand);
        }
    }
    else if (dir != nullptr)
    {
        if (secondCommand == "..")
        {
            HackDirectory *parentDir = dir->getParentDir();
            parentDir->getsubDirs().erase
                    (find(parentDir->getsubDirs().begin(), parentDir->getsubDirs().end(), dir));
            parentDir->getParentDir()->getfiles().push_back(file);
        }
        else
        {
            dir->setDirName(secondCommand);
        }
    }
    else
    {
        commandBuffer.emplace_back("There is not such a file or directory");
    }

}

void HacknetApplication::command_scp(std::stringstream &command)
{
    std::string dirName, address;
    command >> dirName;
    command >> address;
    HackFile *copied;
    copied = locateFile(dirName)->clone();
    if (locateDir(address, true) == nullptr)
    {
        commandBuffer.emplace_back("Don't find " + address);
        delete copied;
    }
    else
    {
        locateDir(address, true)->getfiles().push_back(copied);
    }
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
        head = local ? &(localSever->getRootDirectory()) : &(CurrentConnected->getRootDirectory());
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
        head = head->LocateSonDir(item);
        if (head == nullptr)
        {
            return nullptr;
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
        return CurrentDir->LocateFile(path);
    }
    else if (lastS == 0)
    {
        path.erase(path.begin());
        // file in root directory
        return CurrentConnected->getRootDirectory().LocateFile(path);
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

        return dir->LocateFile(path);
    }
}

void HacknetApplication::command_cat(std::stringstream &commandStream)
{
    std::string filePath;
    commandStream >> filePath;

    auto file = locateFile(filePath);
    if (!file)
    {
        commandBuffer.emplace_back("File not found");
        return;
    }

    auto lns = StringUtil::splitLines(StringUtil::s2ws(file->cat()), 170);
    for (auto &ln: lns)
    {
        commandBuffer.emplace_back(StringUtil::ws2s(ln));
    }
}

void HacknetApplication::RenderStatusBar()
{
    // write time

    if (CurrentConnected == nullptr)
    {
        // disconnected
        Util::setCursorPos(UIUtil::START_STATUSPANEL + Coord(84, 2));
        std::cout << "已断开连接";
    }
    else
    {
        // connected
        serverLogos[1].draw(UIUtil::START_STATUSPANEL);
        Util::setCursorPos(UIUtil::START_STATUSPANEL + Coord(11, 0));
        std::cout << "连接到";
        Util::setCursorPos(UIUtil::START_STATUSPANEL + Coord(11, 1));
        std::cout << CurrentConnected->getName();
        Util::setCursorPos(UIUtil::START_STATUSPANEL + Coord(11, 2));
        std::cout << "@" << CurrentConnected->getIp();
        if (CurrentConnected->isAccessible())
        {
            // :: 您是本系统的管理员 ::
            Util::setCursorPos(UIUtil::START_STATUSPANEL + Coord(11, 4));
            Util::setColorAttr(Util::BG_LIGHT_BLUE);
            Util::setColorAttr(Util::FG_BLACK);
            // 72
            for (int i = 0; i < 72; ++i)
            {
                std::cout << ' ';
            }
            std::cout << ":: 您是本系统的管理员 ::";
            for (int i = 0; i < 72; ++i)
            {
                std::cout << ' ';
            }
            Util::setColorAttr(Util::ATTR_NORMAL);
        }
    }
}

std::string HacknetApplication::getPrompt()
{
    if (CurrentConnected == nullptr)
    {
        return "> ";
    }
    else
    {
        return CurrentConnected->getIp() + "@> ";
    }
}

void HacknetApplication::internalConnect(HackServer *target)
{
    if (CurrentConnected != nullptr)
        internalDisconnect();
    HacknetApplication::commandBuffer.emplace_back("Connection Established ::");
    HacknetApplication::commandBuffer.emplace_back(
            "Connect To " + target->getName() + " in" + target->getIp());
    CurrentConnected = target;
    CurrentDir = &target->getRootDirectory();
}

HacknetApplication::~HacknetApplication()
{
    for (auto &server: serverList)
    {
        delete server;
    }

    for (auto &thread: threadPool)
    {
        delete thread;
    }
    for (auto &bgtsk: backgroundTasks)
    {
        delete bgtsk;
    }
}

void HacknetApplication::RenderTerminal()
{
    // Area buffer
    if (requireUpdate)
    {
        int buffSize = std::min(UIUtil::SIZE_TERMINAL.height - 2, static_cast<int>(commandBuffer.size()));
        int h = 0;
        for (auto it = commandBuffer.end() - buffSize; it != commandBuffer.end(); ++it)
        {
            Util::setCursorPos(UIUtil::START_TERMINAL + Coord(0, h++));
            std::cout << *it;
        }
    }
    else
    {
        // only update prompt
        Util::clearLine(UIUtil::START_TERMINAL + Coord(0, UIUtil::SIZE_TERMINAL.height - 1),
                        UIUtil::SIZE_TERMINAL.width);
    }

    // Area prompt
    inputService.renderCMD(getPrompt(), UIUtil::START_TERMINAL + Coord(0, UIUtil::SIZE_TERMINAL.height - 1));
}
