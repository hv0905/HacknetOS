//
// Created by epiphyllum on 22/04/09.
//

#include <ctime>
#include "HackCommand.h"
#include "HacknetApplication.h"
#include "Utility/Util.h"
#include "Utility/StringUtil.h"
#include "Utility/MusicUtil.h"
#include "HackTxtFile.h"
#include "HackExecutiveFile.h"
#include "BackgroundTasks/PortHackBackgroundTask.h"
#include "BackgroundTasks/SshCrackBgTask.h"
#include "BackgroundTasks/FtpBounceBgTask.h"
#include "BackgroundTasks/TutorialBgTask.h"
#include "HackMenuPanel.h"
#include "HackEmail.h"
#include "HackMailViewer.h"
#include <algorithm>

const HackCommand globalCommands[] = {
        HackCommand(&HacknetApplication::command_help, "help", "显示本帮助列表", "[page (default: 1)]"),
        HackCommand(&HacknetApplication::command_scp, "scp", "从远程计算机复制文件[filename]至指定本地文件夹(/home或/bin为默认)",
                    "[filename] [OPTIONAL: dest]", true, true),
        HackCommand(&HacknetApplication::command_Scan, "scan", "在已连接计算机上扫描链接", "", true, true),
        HackCommand(&HacknetApplication::command_rm, "rm", "删除文件", "[filename (or use * for all files in the folder)]",
                    true, true),
        HackCommand(&HacknetApplication::command_ps, "ps", "列出正在运行的程序以及它们的PID"),
        HackCommand(&HacknetApplication::command_kill, "kill", "结束进程", "[PID]"),
        HackCommand(&HacknetApplication::command_exe, "exe", "列出所有外部可执行文件(包括隐藏式可执行文件)"),
        HackCommand(&HacknetApplication::command_ls, "ls", "列出目录所有内容", "", true, true),
        HackCommand(&HacknetApplication::command_cd, "cd", "切换目录", "[dir]", true, true),
        HackCommand(&HacknetApplication::command_mv, "mv", "移动或重命名文件", "[src] [dst]", true, true),
        HackCommand(&HacknetApplication::command_connect, "connect", "连接到服务器", "[target_ip]"),
        HackCommand(&HacknetApplication::command_nmap, "nmap", "扫描已连接计算机的活动端口及保安级别"),
        HackCommand(&HacknetApplication::command_dc, "dc", "断开连接"),
        HackCommand(&HacknetApplication::command_cat, "cat", "显示文件内容", "[filename]", true, true),
        HackCommand(&HacknetApplication::command_porthack, "porthack", "通过已开放的端口破解计算机管理员密码"),
        HackCommand(&HacknetApplication::command_clear, "clear", "清除终端"),
        HackCommand(&HacknetApplication::command_mailbox, "mailbox", "打开Jmail邮箱(注意: 这将断开您与现有计算机的连接)"),
        HackCommand(&HacknetApplication::command_netmap, "netmap", "打开网络地图"),
        HackCommand(&HacknetApplication::command_shell, "shell", "在当前计算机挂载shell节点", "", true, false),
        HackCommand(&HacknetApplication::command_overload, "overload", "使所有shell节点向目标计算机发起过载攻击", ""),
        HackCommand(&HacknetApplication::command_shellkill, "shellkill", "断开与所有shell节点的连接", ""),
};


void HacknetApplication::Exec()
{
    // First, connect to local server
    //internalConnect(localSever);
    inputService.setAcceptCommand(true);
    renderService.requireUpdate = true;

    pushBackgroundTask(new TutorialBgTask(this));

    while (true)
    {
        // tick for all bg task
        for (auto &item: backgroundTasks)
        {
            if (!item->isStopped())
            {
                item->tick();
            }
        }
        renderService.RenderTick();
        auto result = inputService.tickInput();
        if (result.has_value())
        {
            // process the incoming command
            processCommand(result.value());
            renderService.requireUpdate = true;
        }
        Util::sleep(50);
        if (ending)
        {
            break;
        }
    }
}


void HacknetApplication::command_ls(std::stringstream &)
{

    if (CurrentDir->getsubDirs().empty() && CurrentDir->getfiles().empty())
    {
        pushLog("There is no file and directory in this folder.");
        return;
    }
    CurrentDir->sort();
    pushLog("-----------------------------");
    pushLog("The contain of " + CurrentConnected->getIp() + "@>" + CurrentDir->getAbsolutePath());
    for (auto i: CurrentDir->getsubDirs())
    {
        pushLog(":" + i->getDirName());
    }
    for (auto i: CurrentDir->getfiles())
    {
        pushLog(i->getName());
    }
    pushLog("-----------------------------");
}

void HacknetApplication::rmAll()
{
//    while (!CurrentDir->getsubDirs().empty())
//    {
//        pushLog("Deleting " + CurrentDir->getsubDirs().back()->getDirName());
//        delete CurrentDir->getsubDirs().back();
//        CurrentDir->getsubDirs().pop_back();
//    }

    while (!CurrentDir->getfiles().empty())
    {
        pushLog("Deleting " + CurrentDir->getfiles().back()->getName());
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
        pushLog("Deleting");
        pushLog(file->getName());
        HackDirectory *parentDir = file->getParentDir();
        parentDir->getfiles().erase(find(parentDir->getfiles().begin(), parentDir->getfiles().end(), file));
        delete file;
    }
    else if (dir != nullptr)
    {
        pushLog("Deleting");
        pushLog(dir->getDirName());
        HackDirectory *parentDir = dir->getParentDir();
        parentDir->getsubDirs().erase
                (find(parentDir->getsubDirs().begin(), parentDir->getsubDirs().end(), dir));
        delete dir;
    }
    else
    {
        pushLog("There is not such a file or directory");
    }
}

void HacknetApplication::command_nmap(std::stringstream &)
{
    if (CurrentConnected == nullptr)
    {
        pushLog("Fatal: No available connections.");
        return;
    }
    auto target = CurrentConnected;
    threadPool.push_back(new std::thread([this, target]
                                         {
                                             pushLog("Probing......");
                                             Util::sleep(300);
                                             pushLog("Probe Complete");
                                             Util::sleep(50);
                                             if (target->getShellLife() != 0)
                                             {
                                                 pushLog("Proxy detected.");
                                             }
                                             pushLog("OPEN PORTS:-----------------------");
                                             Util::sleep(50);
                                             pushLog("Port# 80: - HTTP WebServer: " +
                                                     (std::string) ((target->isHttpLocked()) ? "locked" : "unlocked"));
                                             Util::sleep(50);
                                             pushLog("Port# 25: - SMTP MailServer: " +
                                                     (std::string) ((target->isSmtpLocked()) ? "locked" : "unlocked"));
                                             Util::sleep(50);
                                             pushLog("Port# 21: - FTP Server: " +
                                                     (std::string) ((target->isFtpLocked()) ? "locked" : "unlocked"));
                                             Util::sleep(50);
                                             pushLog("Port# 22: - SSH: " +
                                                     (std::string) ((target->isSshLocked()) ? "locked" : "unlocked"));
                                             Util::sleep(50);
                                             pushLog("----------------------------------");
                                             Util::sleep(50);
                                             pushLog("Open Ports:Required for Crack:  " +
                                                     std::to_string(target->getMinRequired()));
                                             nmapDetail = true;
                                         }));

}

void HacknetApplication::command_ps(std::stringstream &)
{
    pushLog("PID    NAME");
    for (auto &item: backgroundTasks)
    {
        if (!item->isStopped())
            pushLog(std::to_string(item->getPid()) + "   " + item->getThreadName());
    }
}

void HacknetApplication::command_kill(std::stringstream &input)
{
    int p;
    input >> p;
    if (input.fail())
    {
        pushLog("输入内容不是一个合法的PID.");
        return;
    }

    auto th = std::find_if(backgroundTasks.begin(), backgroundTasks.end(), [&p](HackBackgroundTask *item)
    {
        return item->getPid() == p && !item->isStopped();
    });
    if (th == backgroundTasks.end())
    {
        pushLog("PID为 " + std::to_string(p) + " 的进程不存在");
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
    auto serv = locateServer(ip);
    if (serv == nullptr)
    {
        pushLog("Don't find such server.");
    }
    else
    {
        serv->setSearchable();
        internalConnect(serv);
    }
}

void HacknetApplication::command_porthack(std::stringstream &s)
{
    if (CurrentConnected == nullptr)
    {
        pushLog("Fatal: No available connections.");
        return;
    }
    HacknetApplication::pushLog("PortHack Initialized --Running");
    if (CurrentConnected->checkIfSecureBroken(shellProgress))
    {
        pushBackgroundTask(new PortHackBackgroundTask(this, "PortHack"));
    }
    else
    {
        pushLog("Fatal: 运行所需端口数过少, 在目标计算机上开放更多端口.");
    }

}

void HacknetApplication::command_Scan(std::stringstream &s)
{
    if (CurrentConnected == nullptr)
    {
        pushLog("Fatal: No available connections.");
    }
    HacknetApplication::pushLog("Scanning For " + CurrentConnected->getIp());
    if (CurrentConnected->getConnectedNodes().empty())
        HacknetApplication::pushLog("This node does not connect to other nodes");
    else
    {
        HacknetApplication::pushLog("The nodes connected to the node:");
        for (auto i: CurrentConnected->getConnectedNodes())
        {
            i->setSearchable();
            HacknetApplication::pushLog(":" + i->getName() + "  " + i->getIp());
        }
    }
}

void HacknetApplication::processCommand(const std::string &command)
{
    pushLog(getPrompt() + command);
    std::stringstream ss(command);
    std::string prefix;
    ss >> prefix;
    std::transform(prefix.begin(), prefix.end(), prefix.begin(), tolower);
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
    std::vector<HackCommand> cmds;
    if (targetCommand == nullptr)
    {
        cmds = getAvailExecutiveCommand();
        auto it = std::find_if(cmds.begin(), cmds.end(), [&prefix](const HackCommand &cmd)
        {
            return cmd.getPrefix() == prefix;
        });
        targetCommand = it == cmds.end() ? nullptr : &(*it);
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
                pushLog("Fatal: require admin access.");
                return;
            }
        }
        if (targetCommand->isShouldLog())
        {
            std::string logString = std::to_string(time(nullptr));
            logString += "@" + localSever->getIp() + "@" + command;
            std::wstring logContent = StringUtil::s2ws(logString);
            std::replace(logString.begin(), logString.end(), '/', '_');
            std::replace(logString.begin(), logString.end(), ' ', '_');
            CurrentConnected->getRootDirectory().LocateOrCreateSonDir("log")->AppendFile(
                    new HackTxtFile(logString, logContent));
        }
        auto handler = targetCommand->getHandler();
        if (handler != nullptr)
            (this->*handler)(ss);
        else pushLog("Not implemented yet.");
        return;
    }

    pushLog("Command not found. Check syntax.");
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
        pushLog("FATAL: 不存在本帮助页面");
        return;
    }
    int end = std::min(skip + 7, size - 1);
    pushLog(
            "显示帮助列表的第" + std::to_string(page) + "/" + std::to_string(size / 8 + (size % 8 ? 1 : 0)) + "页");
    pushLog("------------------------------");
    for (int i = skip; i <= end; ++i)
    {
        pushLog(globalCommands[i].getPrefix() + " " + globalCommands[i].getPattern());
        pushLog(globalCommands[i].getHelpText());
        pushLog("");
    }
    pushLog("------------------------------");


}

void HacknetApplication::command_clear(std::stringstream &)
{
    std::lock_guard lg(commandMutex);
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
        pushLog("There is no such directory here");
}

void HacknetApplication::command_dc(std::stringstream &)
{
    internalDisconnect();
}

void HacknetApplication::command_mv(std::stringstream &commandStream)
{
    std::string src, dst;
    commandStream >> src >> dst;
    if (dst.empty() || src.empty())
    {
        pushLog("Enter the wrong command");
        return;
    }
    auto dir = locateDir(src);
    auto file = locateFile(src);
    if (file != nullptr)
    {
        if (dst.back() == '/')
        {
            // move to dir
            auto newDir = locateDir(dst);
            if (newDir == nullptr)
            {
                pushLog("Destination directory not found");
                return;
            }
            std::string fileName = file->getName();
            auto it = std::find_if(newDir->getfiles().begin(), newDir->getfiles().end(), [&fileName](HackFile *t)
            {
                return t->getName() == fileName;
            });
            if (it != newDir->getfiles().end())
                file->setName("_" + file->getName());
            file->getParentDir()->getfiles().erase(
                    std::find(file->getParentDir()->getfiles().begin(), file->getParentDir()->getfiles().end(), file));
            newDir->AppendFile(file);
        }
        else
        {
            // move & rename
            // /home/dsf
            HackDirectory *newDir;
            auto pos = dst.find_last_of('/');
            if (pos == std::string::npos)
            {
                newDir = CurrentDir;
                pos = -1;
            }
            else
            {
                newDir = locateDir(dst.substr(0, pos + 1));
            }

            if (newDir == nullptr)
            {
                pushLog("Destination directory not found");
                return;
            }
            std::string fileName = file->getName();
            auto it = std::find_if(newDir->getfiles().begin(), newDir->getfiles().end(), [&fileName](HackFile *t)
            {
                return t->getName() == fileName;
            });
            if (it != newDir->getfiles().end())
                file->setName("_" + file->getName());
            file->getParentDir()->getfiles().erase(
                    std::find(file->getParentDir()->getfiles().begin(), file->getParentDir()->getfiles().end(), file));
            file->setName(dst.substr(pos + 1));
            newDir->AppendFile(file);
        }
    }
    else if (dir != nullptr)
    {
        if (dir->getParentDir() == nullptr)
        {
            pushLog("Can't move root directory");
            return;
        }
        auto dstDir = locateDir(dst);

        if (dstDir == nullptr)
        {
            // Move & rename
            if (dst.back() == '/')
            {
                dst.pop_back();
            }
            dir->getParentDir()->getsubDirs().erase(
                    std::find(dir->getParentDir()->getsubDirs().begin(), dir->getParentDir()->getsubDirs().end(), dir));

            auto pos = dst.find_last_of('/');
            if (pos == std::string::npos)
            {
                dstDir = CurrentDir;
                pos = -1;
            }
            else
            {
                dstDir = locateDir(dst.substr(0, pos + 1));
            }

            if (dstDir == nullptr)
            {
                pushLog("Destination directory not found");
                return;
            }
            dir->setDirName(dst.substr(pos + 1));
            dstDir->AppendDirectory(dir);
        }
        else
        {
            // Move to dst directly
            dir->getParentDir()->getsubDirs().erase(
                    std::find(dir->getParentDir()->getsubDirs().begin(), dir->getParentDir()->getsubDirs().end(), dir));
            dstDir->AppendDirectory(dir);
        }
    }
    else
    {
        pushLog("There is not such a file or directory");
    }

}

void HacknetApplication::command_scp(std::stringstream &command)
{
    std::string src, dst;
    command >> src;
    command >> dst;
    HackFile *copied;
    copied = locateFile(src);
    if (copied == nullptr)
    {
        pushLog("FATAL: Cannot find source file to download.");
        return;
    }
    copied = copied->clone();
    if (dst.empty())
    {
        dst = typeid(*copied) == typeid(HackExecutiveFile) ? "/bin/" : "/home/";
    }
    if (locateDir(dst, true) == nullptr)
    {
        pushLog("FATAL: Cannot find target destination path " + dst);
        delete copied;
    }
    else
    {
        auto newDir = locateDir(dst, true);
        std::string fileName = copied->getName();
        auto it = std::find_if(newDir->getfiles().begin(), newDir->getfiles().end(), [&fileName](HackFile *t)
        {
            return t->getName() == fileName;
        });
        if (it != newDir->getfiles().end())
            copied->setName("_" + copied->getName());
        locateDir(dst, true)->AppendFile(copied);
        pushLog("Downloading file " + fileName + "......Success."); // TODO ADD LATENCY
    }
}

void HacknetApplication::internalDisconnect()
{
    if (CurrentConnected != nullptr)
    {
        pushLog("Disconnected");
        CurrentConnected->setSshLocked(true);
        CurrentConnected->setFtpLocked(true);
        CurrentConnected->setSmtpLocked(true);
        CurrentConnected->setHttpLocked(true);
    }
    CurrentDir = nullptr;
    CurrentConnected = nullptr;
    nmapDetail = false;
    shellProgress = -1;
}

HackDirectory *HacknetApplication::locateDir(const std::string &path, bool local)
{
    auto vec = StringUtil::split(path, "/");
    if (vec.empty())
    {
        return nullptr;
    }

    HackDirectory *head;
    if (vec[0].empty())
    {
        head = local ? &(localSever->getRootDirectory()) : &(CurrentConnected->getRootDirectory());
        vec.erase(vec.begin());
    }
    else
    {
        head = CurrentDir;
    }

    if (vec.back().empty())
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

    auto lastS = path.find_last_of('/');
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
        pushLog("File not found");
        return;
    }

    auto lns = StringUtil::splitLines(StringUtil::s2ws(file->cat()), 170);
    for (auto &ln: lns)
    {
        pushLog(StringUtil::ws2s(ln));
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
        return CurrentConnected->getIp() + "@" + CurrentDir->getDirName() + "> ";
    }
}

void HacknetApplication::internalConnect(HackServer *target)
{
    if (CurrentConnected != nullptr)
        internalDisconnect();
    HacknetApplication::pushLog("Connection Established ::");
    HacknetApplication::pushLog(
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

HackServer *HacknetApplication::getCurrentConnected() const
{
    return CurrentConnected;
}

const std::vector<std::string> &HacknetApplication::getCommandBuffer() const
{
    return commandBuffer;
}

std::vector<std::string> &HacknetApplication::getCommandBuffer()
{
    return commandBuffer;
}

RenderService &HacknetApplication::getRenderService()
{
    return renderService;
}

std::string HacknetApplication::getCommandAutoComplete(const std::string &command)
{
    auto cmdLower = StringUtil::toLowerCopy(command);
    std::vector<std::string> possibleResult;
    for (const auto &i: globalCommands)
    {
        if (StringUtil::toLowerCopy(i.getPrefix()).rfind(cmdLower, 0) == 0)
        {
            possibleResult.emplace_back(i.getPrefix());
        }
    }

    for (const auto &i: getAvailExecutiveCommand())
    {
        if (StringUtil::toLowerCopy(i.getPrefix()).rfind(cmdLower, 0) == 0)
        {
            possibleResult.emplace_back(i.getPrefix());
        }
    }
    if (possibleResult.size() > 1)
    {
        for (auto &i: possibleResult)
        {
            pushLog(i);
            renderService.requireUpdate = true;
        }
    }
    if (possibleResult.empty())
        return command;
    else
        return StringUtil::getPublicPrefix(possibleResult);
}

std::string HacknetApplication::getFilenameAutoComplete(const std::string &command)
{
    auto pos = command.find_last_of('/');
    std::vector<std::string> possibleResult;
    HackDirectory *newDir;
    if (pos == std::string::npos)
    {
        newDir = CurrentDir;
        pos = -1;
    }
    else
    {
        newDir = locateDir(command.substr(0, pos));
    }

    if (newDir == nullptr)
    {
        return command;
    }
    std::string right = command.substr(pos + 1);
    StringUtil::toLower(right);

    for (auto i: newDir->getsubDirs())
    {
        if (StringUtil::toLowerCopy(i->getDirName()).rfind(right, 0) == 0)
        {
            possibleResult.emplace_back(i->getDirName());
        }
    }
    for (auto i: newDir->getfiles())
    {
        if (StringUtil::toLowerCopy(i->getName()).rfind(right, 0) == 0)
        {
            possibleResult.emplace_back(i->getName());
        }
    }
    if (possibleResult.size() > 1)
    {
        for (auto &i: possibleResult)
        {
            pushLog(i);
            renderService.requireUpdate = true;
        }
    }
    if (possibleResult.empty())
        return command;
    else
        return command.substr(0, pos + 1) + StringUtil::getPublicPrefix(possibleResult);
}

void HacknetApplication::executive_sshcrack(std::stringstream &commandStream)
{
    int port;
    commandStream >> port;
    if (CurrentConnected == nullptr)
    {
        pushLog("Fatal: No available connections.");
        return;
    }
    if (!commandStream)
    {
        pushLog("未提供端口号.");
        pushLog("Execution failed.");
        return;
    }
    if (port != 22)
    {
        pushLog("无法连接到目标端口或目标端口正在运行不与此程序兼容的服务.");
        pushLog("Execution failed.");
        return;
    }
    if (getCurrentConnected()->getShellLife() != 0 && shellProgress < getCurrentConnected()->getShellLife())
    {
        pushLog("代理已激活, 无法与目标端口建立连接.");
        pushLog("Execution failed.");
        return;
    }

    pushLog("SecureShellCrack running...");
    pushBackgroundTask(new SSHCrackBgTask(this, "SecureShellCrack"));

}

void HacknetApplication::executive_ftpbounce(std::stringstream &commandStream)
{
    int port;
    commandStream >> port;
    if (CurrentConnected == nullptr)
    {
        pushLog("Fatal: No available connections.");
        return;
    }
    if (!commandStream)
    {
        pushLog("未提供端口号.");
        pushLog("Execution failed.");
        return;
    }
    if (port != 21)
    {
        pushLog("无法连接到目标端口或目标端口正在运行不与此程序兼容的服务.");
        pushLog("Execution failed.");
        return;
    }

    if (getCurrentConnected()->getShellLife() != 0 && shellProgress < getCurrentConnected()->getShellLife())
    {
        pushLog("代理已激活, 无法与目标端口建立连接.");
        pushLog("Execution failed.");
        return;
    }

    pushLog("FTPBounce running...");
    pushBackgroundTask(new FTPBounceBgTask(this, "FTPBounce"));
}

std::vector<HackCommand> HacknetApplication::getAvailExecutiveCommand()
{
    auto binDir = localSever->getRootDirectory().LocateSonDir("bin");
    std::vector<HackCommand> result;
    for (auto &file: binDir->getfiles())
    {
        if (typeid(*file) != typeid(HackExecutiveFile))
            continue;
        auto binFile = dynamic_cast<HackExecutiveFile *>(file);
        auto cmd = binFile->getRelatedCommand();

        if (StringUtil::endsWith(file->getName(), ".exe"))
        {
            cmd.setPrefix(file->getName().substr(0, file->getName().size() - 4));
        }
        else
        {
            cmd.setPrefix(file->getName());
        }
        result.push_back(cmd);
    }

    return result;
}

void HacknetApplication::pushLog(const std::string &log)
{
    std::lock_guard lock(commandMutex);
    commandBuffer.push_back(log);
    renderService.requireUpdate = true;
}

void HacknetApplication::command_mailbox(std::stringstream &)
{
    internalDisconnect();
    pushLog("JMail initializing...");

    auto avail = getAvailEmail();
    std::vector<std::string> titles;
    titles.reserve(avail.size());
    for (auto &i: avail)
    {
        titles.push_back((i->isRead() ? "   " : " * ") + StringUtil::ws2s(i->getEmailTitle()));
    }

    auto select = HackMenuPanel(":: MailBox ::", titles);
    select.setReverse(true);
    int i = select.Exec();
    if (i == -1) return;
    auto viewer = HackMailViewer(avail[i], this);
    if (viewer.Exec())
    {
        updateMissionId(getMissionId() + 1);
    }
}

const InputService &HacknetApplication::getInputService() const
{
    return inputService;
}

HackServer *HacknetApplication::getLocalSever() const
{
    return localSever;
}

HackDirectory *HacknetApplication::getCurrentDir() const
{
    return CurrentDir;
}

bool HacknetApplication::pushBackgroundTask(HackBackgroundTask *task)
{
    if (task == nullptr)
        return false;
    // checkMem
    int totalMem = 0;
    for (auto &i: backgroundTasks)
    {
        if (i->isStopped()) continue;
        totalMem += i->getMemorySize() + 1;
    }

    if (totalMem + task->getMemorySize() + 1 > HackBackgroundTask::MAX_MEMORY)
    {
        pushLog("Fatal: Out of memory.");
        return false;
    }
    backgroundTasks.push_back(task);
    return true;
}

void HacknetApplication::updateMissionId(int newId)
{
    if (newId > missionId && getAvailEmail(newId).size() > getAvailEmail().size())
    { // notif
        MusicUtil::playNotif(0);// You got mail
        pushLog("***你收到了新的邮件.***");
        pushLog("请使用指令mailbox打开邮箱进行确认.");
    }
    missionId = newId;
}

int HacknetApplication::getMissionId() const
{
    return missionId;
}

void HacknetApplication::command_exe(std::stringstream &)
{
    auto l = getAvailExecutiveCommand();
    for (auto &i: l)
    {
        pushLog(":" + i.getPrefix());
    }
}

void HacknetApplication::command_netmap(std::stringstream &)
{
    // collect avail ips
    std::vector<HackServer *> ips;
    std::vector<std::string> titles;

    for (auto &i: serverList)
    {
        if (!i->isSearchable()) continue;
        ips.push_back(i);
        titles.push_back(i->getName() + " - " + i->getIp());
    }

    auto select = HackMenuPanel(" :: NetMap v1.3 ::", titles);
    int i = select.Exec();
    if (i == -1) return;
    internalConnect(ips[i]);

}

std::vector<HackEmail *> HacknetApplication::getAvailEmail(int mid)
{
    std::vector<HackEmail *> result;
    for (auto &i: emailList)
    {
        if (i->getMissionId() <= mid)
        {
            result.push_back(i);
        }
    }

    return result;
}

std::vector<HackEmail *> HacknetApplication::getAvailEmail()
{
    return getAvailEmail(missionId);
}

MissionCheckService &HacknetApplication::getCheckService()
{
    return checkService;
}

HackServer *HacknetApplication::locateServer(std::string ip)
{
    auto it = std::find_if(serverList.begin(), serverList.end(), [&ip](HackServer *t)
    {
        return t->getIp() == ip;
    });
    if (it == serverList.end()) return nullptr;
    return *it;
}

void HacknetApplication::command_shell(std::stringstream &)
{
    auto shellProc = findShellTask();
    if (shellProc == nullptr)
    {
        // Try to create the proc
        if (!pushBackgroundTask(new ShellBgTask(this, "Shell")))
        {
            pushLog("Fatal: Out of memory.");
            return;
        }
        shellProc = dynamic_cast<ShellBgTask *>(backgroundTasks.back());
    }

    if (std::find(shellProc->getConnectedServers().begin(), shellProc->getConnectedServers().end(), CurrentConnected) ==
        shellProc->getConnectedServers().end())
    {
        shellProc->getConnectedServers().push_back(CurrentConnected);
    }
}

void HacknetApplication::command_overload(std::stringstream &)
{
    if (findShellTask() == nullptr)
    {
        pushLog("Fatal: No shells are mounted.");
    }
    else if (CurrentConnected == nullptr)
    {
        pushLog("Fatal: No available connections.");
    }
    else if (CurrentConnected->getShellLife() == 0)
    {
        pushLog("Fatal: No active proxy.");
    }
    else
    {
        shellProgress = std::max(shellProgress, 0);
    }
}

void HacknetApplication::command_shellkill(std::stringstream &)
{
    auto shellProc = findShellTask();
    if (shellProc != nullptr)
    {
        shellProc->kill();
    }
}

ShellBgTask *HacknetApplication::findShellTask()
{
    auto it = std::find_if(backgroundTasks.begin(), backgroundTasks.end(), [](HackBackgroundTask *p)
    {
        return !p->isStopped() && typeid(*p) == typeid(ShellBgTask);
    });
    if (it != backgroundTasks.end())
    {
        return dynamic_cast<ShellBgTask *>(*it);
    }
    else
    {
        return nullptr;
    }

}

int HacknetApplication::getShellProgress() const
{
    return shellProgress;
}

void HacknetApplication::setShellProgress(int shellProgress)
{
    HacknetApplication::shellProgress = shellProgress;
}
