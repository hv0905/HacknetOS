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
    auto local_bin = new HackDirectory("bin");
    local_bin->AppendFile(new HackTxtFile("SecurityTracer.exe", L"#SECURITYTRACER_PROGRAM#"));
    local_home->AppendDirectory(new HackDirectory("Sub1"));
    local_home->AppendFile(new HackTxtFile("file1.txt", L"Hello World!"));
    local_home->AppendFile(new HackTxtFile("file2.txt", L"Hello World!"));
    local_home->AppendFile(new HackTxtFile("file3.txt", L"Hello World!"));

    local->getRootDirectory().AppendDirectory(local_home);
    local->getRootDirectory().AppendDirectory(local_bin);
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
    auto tutorial_bin = new HackDirectory("bin");

    auto NewFolder_15 = new HackDirectory("NewFolder_15");
    auto NewFolder_64 = new HackDirectory("NewFolder_64");

    auto IRC_Log_583977_8977 = new HackTxtFile("IRC_Log:583977(8977)",
                                               L"\n"
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
    auto IRC_Log_178890_14081 = new HackTxtFile("IRC_Log:178890+(14081)",
                                                L" -Word_of_God- Welcome Abstruse to #christian I am a Bible Bot. For more info type: /msg Word_of_God !info\n"
                                                " <Abstruse> !kjv numbers 22:21\n"
                                                " <Word_of_God>  Numbers 22:21 -- And Balaam rose up in the morning, and saddled his ass, and went with the princes of Moab. -  (KJV)\n"
                                                " *** SageRider sets mode: +b *!*@c211-30-208-111.rivrw3.nsw.optusnet.com.au\n"
                                                " *** Word_of_God was kicked from #christian by SageRider (Please dont Swear)\n"
                                                " <Abstruse> I know I'm never going to be able to come back in this channel again after this, but damn was it worth it to see that... ");
    auto config_txt = new HackTxtFile("config.txt", L"config.ini\n"
                                                    "init_num: \"12\"\n"
                                                    "continual_spawning \"YES\"\n"
                                                    "colours_enabled {\"peach\",\"ivory\",\"fudge\",\"chocolate\",\"magenta\"}\n"
                                                    "behaviors_enabled {\"twirl\",\"thrust\",\"helicopter\"}\n"
                                                    "resolution: {\"1280\",\"800\"}\n"
                                                    "fullscreen: \"YES\"\n"
                                                    "alt_tab_enabled: \"YES\"\n"
                                                    "texture_folder: \"C:/Documents_and_Settings/Admin/Fax/Not_Porn/Documents/Serious_Documents/System/textures\"");
    NewFolder_64->AppendFile(IRC_Log_583977_8977);
    NewFolder_64->AppendFile(Speech_node);

    NewFolder_15->AppendFile(IRC_Log_178890_14081);

    tutorial_home->AppendDirectory(NewFolder_64);
    tutorial_home->AppendDirectory(NewFolder_15);

    tutorial_bin->AppendFile(config_txt);

    tutorialServer->getRootDirectory().AppendDirectory(tutorial_home);
    tutorialServer->getRootDirectory().AppendDirectory(tutorial_bin);
    tutorialServer->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    tutorialServer->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    app->serverList.push_back(tutorialServer);

    app->serverList[0]->getConnectedNodes().push_back(tutorialServer);

    //教程关服务器

    //毒蛇——作战基地服务器
    auto ViperServer = new HackServer("176.198.61.104", "毒蛇作战基地", 0);
    auto Viper_bin = new HackDirectory("bin");
    auto Viper_home = new HackDirectory("home");

    Viper_bin->AppendFile(
            new HackBinFile("sshcrack.exe", HackCommand(&HacknetApplication::executive_sshcrack, "sshcrack", "-")));
    Viper_home->AppendFile(new HackTxtFile("EmailDraft.txt", L"爸爸, \n"
                                                             "    很抱歉之前没有及时给你回信 - 我在学校真的很忙 - 今年非常难熬, 不过我想我熬过来了. \n"
                                                             "    我这次找你其实是想问你要点钱 - 我们学校今年有个新项目, 它叫 \"FTPBounce.exe\", 这个程序特别有用! 不过这个程序也很贵, 而且上次你给我的钱我也花完了... .IT这些项目软件都非常的贵. \n"
                                                             "    能不能再给我打2000$? 我真的很需要. \n"
                                                             "\n"
                                                             "    谢谢! \n"
                                                             "    爱你的儿子, \n"
                                                             "    Tim"));

    ViperServer->getRootDirectory().AppendDirectory(Viper_home);
    ViperServer->getRootDirectory().AppendDirectory(Viper_bin);
    ViperServer->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    ViperServer->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    app->serverList.push_back(ViperServer);
    //毒蛇——作战基地服务器

    //Bitwise测试PC
    auto Bitwise = new HackServer("210.175.139.250", "Bitwise测试PC", 1);
    auto IRC_Log_139697_8593 = new HackTxtFile("IRC_Log:139697+(8593)", L"<frank> 你能教我安装GTA3吗? \n"
                                                                        "\n"
                                                                        "<knightmare> 首先, 把你现在不用的程序都关掉\n"
                                                                        "\n"
                                                                        "frank离开了IRC聊天室. \n"
                                                                        "\n"
                                                                        "<knightmare> ... 智障");
    auto NewFolder24 = new HackDirectory("NewFolder24");
    auto Bitwise_home = new HackDirectory("home");

    NewFolder24->AppendFile(IRC_Log_139697_8593);
    Bitwise_home->AppendDirectory(NewFolder24);

    Bitwise->getRootDirectory().AppendDirectory(Bitwise_home);
    Bitwise->getRootDirectory().AppendDirectory(new HackDirectory("bin"));
    Bitwise->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    Bitwise->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    app->serverList.push_back(Bitwise);
    //Bitwise测试PC

    //Anderson的卧室电脑
    auto AndersonServer = new HackServer("247.112.153.237", "Anderson的卧室电脑", 1);
    auto Anderson_Documents = new HackDirectory("Documents");
    auto Anderson_home = new HackDirectory("home");

    Anderson_Documents->AppendFile(new HackTxtFile("charlog.txt", L"[HotRice] 准备好出去浪了吗? \n"
                                                                  "[Kiah] 那取决于. . . \n"
                                                                  "[Kiah] 你准备好去死了吗\n"
                                                                  "[M4cr0b4t] 哈哈哈\n"
                                                                  "[HotRice] 闭嘴, Johnson! \n"
                                                                  "[HotRice] 忘了你上次打翻花生酱的事情了? \n"
                                                                  "[M4cr0b4t] 别提那次的事情了\n"
                                                                  "[HotRice] 就那一次就够你受的了\n"
                                                                  "[HotRice] 有谁知道Hellerphant在哪里吗? \n"
                                                                  "[Kiah] 没有人知道他去哪了\n"
                                                                  "[Kiah] 我估计是有个魔法怪物把他抓走了. \n"
                                                                  "[HotRice] 严肃点, 我们的计划被打乱了. \n"
                                                                  "[HotRice] 为什么每次我担心的事情总会发生? "));

    Anderson_home->AppendDirectory(Anderson_Documents);

    AndersonServer->getRootDirectory().AppendDirectory(Anderson_home);
    AndersonServer->getRootDirectory().AppendDirectory(new HackDirectory("bin"));
    AndersonServer->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    AndersonServer->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    app->serverList.push_back(AndersonServer);
    //Anderson的卧室电脑

    //Entropy测试服务器
    auto EntropyServer=new HackServer("247.112.153.237","Entropy测试服务器",1);
    auto Entropy_home=new HackDirectory("home");
    auto Entropy_bin=new HackDirectory("bin");

    Entropy_home->AppendFile(new HackTxtFile("Entropy_Induction_Test",L"祝贺你, \n"
                                                                           "  下载此文件以完成您的入组测试. \n"
                                                                           "  Entropy马上就会联系你. "));
    Entropy_bin->AppendFile(new HackTxtFile("BIT_PLZ_READ.txt",L"Bit, 别躲藏在阴影里了, 出来见见我吧, 我有事要跟你谈. \n"
                                                               "Vap0r不会放过我的, 我觉得有点儿不对劲--她肯定有什么事瞒着我, 可以告诉我吗? \n"
                                                               "-T"));

    EntropyServer->getRootDirectory().AppendDirectory(Entropy_home);
    EntropyServer->getRootDirectory().AppendDirectory(Entropy_bin);
    EntropyServer->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    EntropyServer->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    app->serverList.push_back(EntropyServer);

    //Entropy测试服务器
    return app;
}
