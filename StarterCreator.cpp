//
// Created by epiphyllum on 22/04/20.
//

#include "StarterCreator.h"
#include "HackTxtFile.h"
#include "HackBinFile.h"

HacknetApplication *StarterCreator::createStarterOS()
{
    auto app = new HacknetApplication();
    auto *local = new HackServer("127.0.0.1", "Aiden Pearce", 0);
    auto local_home = new HackDirectory("home");
    local_home->AppendDirectory(new HackDirectory("Sub1"));
    local_home->AppendFile(new HackTxtFile("file1.txt", L"Hello World!"));
    local_home->AppendFile(new HackTxtFile("file2.txt", L"Hello World!"));
    local_home->AppendFile(new HackTxtFile("file3.txt", L"Hello World!"));

    local->getRootDirectory().AppendDirectory(local_home);
    local->getRootDirectory().AppendDirectory(new HackDirectory("bin"));
    local->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    local->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    auto cheater_zone = new HackServer("1337.1337.1337.1337", "Cheater Zone", 0);
    auto cheater_zone_bin = new HackDirectory("bin");
    cheater_zone_bin->AppendFile(
            new HackBinFile("sshcrack.exe", HackCommand(&HacknetApplication::executive_sshcrack, "sshcrack", "-")));
    cheater_zone_bin->AppendFile(
            new HackBinFile("ftpbounce.exe", HackCommand(&HacknetApplication::executive_ftpbounce, "ftpbounce", "-")));
    cheater_zone->getRootDirectory().AppendDirectory(new HackDirectory("home"));
    cheater_zone->getRootDirectory().AppendDirectory(cheater_zone_bin);
    cheater_zone->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    cheater_zone->getRootDirectory().AppendDirectory(new HackDirectory("sys"));


    local->accessible = true;
    app->serverList.push_back(local);
    app->serverList.push_back(cheater_zone);
    app->localSever = app->serverList[0];

    // Add Servers, Directories, and Files here...
    //教程关服务器
    auto *tutorialServer = new HackServer("248.110.68.189", "Dengler Consortium", 0);
    auto tutorial_home = new HackDirectory("home");
    auto IRC_Log_583977_8977 = new HackTxtFile("IRC_Log:583977(8977)",
                                               L"#583977 +(8799)- [X]\n"
                                               "\n"
                                               "<DannyB> 我在街上碰到个妹子问我是否还保有处男之身(if i was saved)\n"
                                               "\n"
                                               " <DannyB> 我跟她说几分钟前我刚经过一个检查点\n"
                                               "\n"
                                               " <DannyB> 如果我死了我可以在那加载存档\n"
                                               "\n"
                                               " <DannyB> 她一脸懵逼");
    auto Speech_node = new HackTxtFile("Speech_node",
                                       L"\n"
                                       "周五向全公司作报告的演讲笔记, 千万别忘了! ! ! \n"
                                       "领潮争先, 共创未来\n"
                                       "\n"
                                       "－Facebook集成: 在技术时代, 我们必须将集成Facebook作为我们游戏企划关键, 以此来减少开支, 最大化利润. \n"
                                       "－协同增效: 为了最大化工作效率, 我们必须通力合作, 以求双赢. \n"
                                       "－社会媒体: 我们必须构建社会媒体的知识基础, 通过电子商务在以客户为导向的领域摘得头筹. \n"
                                       "－超频CPU: 我们要紧随潮流, 扩展社会内容渠道, 提高网络带宽, 来提高线上占有率, 让公司收入翻两番. \n"
                                       "－质量驱动路线: 授权方案让我们在 Web 2.0 上获得了许多令人惊讶的特色. (我认为这足以称为独立于因特网之外的第二个因特网, 周五之前同 Paul 一起再探讨一下? )(顺手让他帮我修好我的打印机)(顺手也问一下为什么我的打印机驱动文件夹是加密的)\n"
                                       "－未来路线图: 自顶而下的电子化处理方式, 将我们的客户基础成功变现, 重新划分市场, 提高公司收入. ");
    auto NewFolder_64 = new HackDirectory("NewFolder_64");
    NewFolder_64->AppendFile(IRC_Log_583977_8977);
    NewFolder_64->AppendFile(Speech_node);
    auto NewFolder_15 = new HackDirectory("NewFolder_15");
    auto IRC_Log_178890_14081 = new HackTxtFile("IRC_Log:178890+(14081)",
                                                L"(译者注: 这段涉及到圣经历史, 汉化组无力)\n"
                                                "*** Now talking in #christian\n"
                                                " -Word_of_God- Welcome Abstruse to #christian I am a Bible Bot. For more info type: /msg Word_of_God !info\n"
                                                " <Abstruse> !kjv numbers 22:21\n"
                                                " <Word_of_God>  Numbers 22:21 -- And Balaam rose up in the morning, and saddled his ass, and went with the princes of Moab. -  (KJV)\n"
                                                " *** SageRider sets mode: +b *!*@c211-30-208-111.rivrw3.nsw.optusnet.com.au\n"
                                                " *** Word_of_God was kicked from #christian by SageRider (Please dont Swear)\n"
                                                " <Abstruse> I know I'm never going to be able to come back in this channel again after this, but damn was it worth it to see that... ");
    NewFolder_15->AppendFile(IRC_Log_178890_14081);
tutorial_home->AppendDirectory(NewFolder_64);
tutorial_home->AppendDirectory(NewFolder_15);
auto config_txt=new HackTxtFile("config.txt",L"config.ini\n"
                                             "init_num: \"12\"\n"
                                             "continual_spawning \"YES\"\n"
                                             "colours_enabled {\"peach\",\"ivory\",\"fudge\",\"chocolate\",\"magenta\"}\n"
                                             "behaviors_enabled {\"twirl\",\"thrust\",\"helicopter\"}\n"
                                             "resolution: {\"1280\",\"800\"}\n"
                                             "fullscreen: \"YES\"\n"
                                             "alt_tab_enabled: \"YES\"\n"
                                             "texture_folder: \"C:/Documents_and_Settings/Admin/Fax/Not_Porn/Documents/Serious_Documents/System/textures\"");
auto tutorial_bin=new HackDirectory("bin");
    tutorialServer->getRootDirectory().AppendDirectory(tutorial_home);
    tutorial_bin->AppendFile(config_txt);
    local->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    local->getRootDirectory().AppendDirectory(new HackDirectory("sys"));
    //教程关服务器

    return app;
}
