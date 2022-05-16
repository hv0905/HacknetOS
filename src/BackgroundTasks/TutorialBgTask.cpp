//
// Created by epiphyllum on 22/04/17.
//

#include <iostream>
#include "../HacknetApplication.h"
#include "TutorialBgTask.h"
#include "../Utility/Util.h"
#include "../Utility/StringUtil.h"

const wchar_t *StepsText[] = {
        L"现在你正处于危险之中! \n"
        "以你最快的速度完成教程.\n"
        "在终端中输入\"connect [IP]\",或使用\"netmap\"命令来连接到一台电脑\n"
        "----------\n"
        "现在，连接到你自己的电脑(127.0.0.1)",
        L"干得漂亮. \n"
        " \n"
        "在你连接到任何系统之后, 你需要做的第一件事便是扫描(scan)它的相关节点. \n"
        "----------\n"
        "现在, 使用\"scan\"指令扫描这台电脑",
        L"好了, 需要在你自己电脑上进行的操作已经结束了. \n"
        "现在从你的机器断开.(使用dc指令即可断开连接) \n",
        L"是时候连接到一台外部计算机了. \n"
        " \n"
        "注意: 试图破坏他人计算机的安全将违反U.S.C 1030-1条规. \n"
        " \n"
        "从现在开始, 为自己的行为负责吧! \n"
        "----------\n"
        "使用\"connect [IP]\"指令连接到一台电脑, 连接到你刚刚扫描到的电脑",
        L"这个虚拟机的终端模块已被激活. 这将是你用于导航的主菜单. \n"
        " \n"
        "可以输入一个命令, 然后按回车键(ENTER)来运行. \n"
        " \n"
        "查看计算机的安全系统和活动端口可以使用\"nmap\"命令. \n"
        "----------\n"
        "分析当前连接的计算机",
        L"在这里你可以看到活动端口, 已激活的安全系统和需要破解的端口数, 你需要破解规定数量的端口才能运行PortHack. \n"
        "这台服务器没有已激活的安全系统, 需要破解的端口数量为0. 使用\"PortHack\"开始破解. \n"
        "----------\n"
        "如果想要在你连接到的设备上运行你所拥有的程序, 可在终端上输入该程序的名字. \n"
        "\n"
        "输入程序名字时不需要带上.exe",
        L"恭喜! 你已经控制了这个外部系统, 现在你是该系统的管理员. 你可以做任何事, 但你最好先扫描本机的相关节点\n"
        "-----------\n"
        "使用\"扫描网络(scan)\"命令来定位相关节点. ",
        L"没有结果 - 没有就没有吧. \n"
        "\n"
        "下一步, 查看文件系统. \n"
        "----------\n"
        "列出当前目录中的文件和文件夹\n"
        "输入\"ls\"查看当前目录中的文件和文件夹",
        L"访问\"bin\"文件夹(二进制文件夹)来搜索有用的可执行文件, 使用命令\n"
        " \n"
        "\"cd [文件夹名]\" (注意空格)",
        L"要查看当前文件夹的内容, 使用\"ls\"命令. \n"
        "这里没有程序, 但你最好查看config.txt以防止漏掉有用的信息. \n"
        "读取任何文件都可以使用cat命令. 例: \n"
        " \n"
        "\"cat config.txt\"\n",
        L"然而这里面卵都没有! \n"
        "现在, 你要清理你访问的痕迹. \n"
        "返回上一个目录\n"
        "使用\"cd ..\"\n"
        "注: 通配符\"..\"表示\"返回\"或\"上\". ",
        L"进入log文件夹",
        L"删除此目录中的所有文件\n"
        "你可以使用该命令删除该文件\n"
        "rm [文件名]\n"
        "你也可以使用该命令删除当前目录下的所有文件\n"
        "rm *\n"
        "注: 通配符\"*\"表示\"所有\". ",
        L"干的很好! \n"
        "与这台计算机断开连接",
        L"恭喜, 你已经完成了本教程的所有内容. \n"
        "想要结束本教学, 你需要找到本教学程序的PID, 并结束它. \n"
        "\"help\"命令可以给你列出完整的命令列表. "
};

void TutorialBgTask::drawMemory(Coord begin)
{
    checkStatus();
    auto lines = StringUtil::splitLines(StepsText[status], 40);
    for (int i = 0; i < lines.size(); ++i)
    {
        Util::setCursorPos(begin + Coord(0, i));
        std::wcout << lines[i];
    }
}

int TutorialBgTask::getMemorySize()
{
    return 16;
}

void TutorialBgTask::kill()
{
    ref->updateMissionId(std::max(ref->getMissionId(), 1));
    HackBackgroundTask::kill();
}

void TutorialBgTask::checkStatus()
{
    switch (status)
    {
        case 0:
            if (ref->getCurrentConnected() == ref->getLocalSever())
            {
                ++status;
            }
            break;
        case 1:
            if (ref->getInputService().getHistory().back() == "scan")
            {
                ++status;
            }
            break;
        case 2:
            if (ref->getCurrentConnected() == nullptr)
            {
                ++status;
            }
            break;
        case 3:
            if (std::find(ref->getLocalSever()->getConnectedNodes().begin(),
                          ref->getLocalSever()->getConnectedNodes().end(), ref->getCurrentConnected()) !=
                ref->getLocalSever()->getConnectedNodes().end())
            {
                ++status;
            }
            break;
        case 4:
            if (ref->getInputService().getHistory().back() == "nmap")
            {
                ++status;
            }
            break;
        case 5:
            if (ref->getCurrentConnected() && ref->getCurrentConnected()->isAccessible())
            {
                ++status;
            }
            break;
        case 6:
            if (ref->getInputService().getHistory().back() == "scan")
            {
                ++status;
            }
            break;
        case 7:
            if (ref->getInputService().getHistory().back() == "ls")
            {
                ++status;
            }
            break;
        case 8:
            if (ref->getCurrentDir() && ref->getCurrentDir()->getDirName() == "bin")
            {
                ++status;
            }
            break;
        case 9:
            if (ref->getInputService().getHistory().back() == "cat config.txt")
            {
                ++status;
            }
            break;
        case 10:
            if (ref->getCurrentConnected() && ref->getCurrentDir() == &ref->getCurrentConnected()->getRootDirectory())
            {
                ++status;
            }
            break;
        case 11:
            if (ref->getCurrentDir() && ref->getCurrentDir()->getDirName() == "log")
            {
                ++status;
            }
            break;
        case 12:
            if (ref->getInputService().getHistory().back() == "rm *")
            {
                ++status;
            }
            break;
        case 13:
            if (ref->getCurrentConnected() == nullptr)
            {
                ++status;
            }
            break;
    }
}

TutorialBgTask::TutorialBgTask(HacknetApplication *ref) : HackBackgroundTask(ref, "Tutorial")
{

}
