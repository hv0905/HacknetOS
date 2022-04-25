//
// Created by 16950 on 2022/4/15.
//
#include"HackEmail.h"

#include <utility>

HackEmail::HackEmail(const std::wstring &title, const std::wstring &sender, const std::wstring &content, int mid) :
        emailTitle(title), sender(sender), emailContent(content), missionId(mid)
{}

const HackEmail Email[] = {
        HackEmail(L"初次联系", L"Bit", L"Hi. \n"
                                   "我不认识你, 而且很遗憾的是我也没机会再认识你了, 但是如果你读到这封邮件, 那就意味着你还有机会来挽救这一切. \n"
                                   "我现在深陷危机, 留给我的时间已经不多了. 有件事我想求你帮我. \n"
                                   "但在这之前, 还有件更重要的事情需要你尽快处理, 越快越好. \n"
                                   "现在这个状态的Hacknet操作系统并不应该发布出去...  ..你的电脑里马上就会有一个追踪软件自动激活, 赶快删掉它. \n"
                                   "连接到你自己的节点(在网络图中的绿色节点), 然后找到并删除\"SecurityTracer.exe\". \n"
                                   "当你完成时, 回复这个邮件就行. \n"
                                   "快快快! \n"
                                   "\n"
                                   "-Bit\n"
                                   "0", 1),
        HackEmail(L"让我们来一起获取一些工具",L"Bit",L"很好 - 你现在应该安全了! 至少在你的电脑上...  \n"
                                         "\n"
                                         "在我们开始之前, 你需要获取一些工具 - 只使用porthack是无法侵入你将来发现的大部分电脑的...  至少你入侵不了那些你感兴趣的东西. \n"
                                         "      \n"
                                         "你应该从调查我朋友的服务器开始 - 他自称自己是\"Viper(毒蛇)\" - 听起来很可怕是吧? 老实说...  他干这行水平不怎么样, 但他总是有一些实用的代码. \n"
                                         "\n"
                                         "入侵他的电脑对你来说应该不是问题 - 问题在于能否找到有用的文件. \n"
                                         "\n"
                                         "在大多数情况下, 你可以忽略掉一些关于登陆记录, 程序的存储文件, IRC日志等等的这种\"普通\"文件. 像这种后缀为\".exe\"的文件才是你所寻找的. \n"
                                         "\n"
                                         "你可以使用命令\"scp\"下载任何文件. \n"
                                         "\n"
                                         "祝你好运 - 完成之后给我回信! \n"
                                         "      \n"
                                         "--Bit\n"
                                         "0")
};
std::wstring displayedEmail[1000];

void HackEmail::lsMail(int missionid)
{
    int pos = 0;
    for (const auto &i: Email)
    {
        if (i.missionId <= missionid)
        {
            if (pos >= 40)
                break;
            displayedEmail[pos++] = i.emailTitle;
        }
    }
}

void HackEmail::cdMail(const std::wstring &title)
{
    for (const auto &i: Email)
        if (i.emailTitle == title)
        {
            displayedEmail[0] = i.emailTitle;
            displayedEmail[1] = i.sender;
            int pos = 2;
            int num = 60;
            int len = i.emailContent.length();//字符串长度
            int end = num;//分割定长大小
            std::wstring s;
            for (int start = 0; start < len;)
            {
                if (start > len)
                {
                    break;
                }
                s = i.emailContent.substr(start, num);//从0开始，分割num位字符串
                start = end;
                end = end + num;
                displayedEmail[pos++] = s;
            }
            break;
        }
}



