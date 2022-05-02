//
// Created by epiphyllum on 22/04/20.
//

#include "StarterCreator.h"
#include "HackTxtFile.h"
#include "HackBinFile.h"

HacknetApplication *StarterCreator::createStarterOS()
{

    auto app = new HacknetApplication();
    // region local
    auto *local = new HackServer("127.0.0.1", "Aiden Pearce", 4);
    auto local_home = new HackDirectory("home");
    auto local_bin = new HackDirectory("bin");
    local_bin->AppendFile(new HackTxtFile("SecurityTracer.exe", L"#SECURITYTRACER_PROGRAM#"));

    local->getRootDirectory().AppendDirectory(local_home);
    local->getRootDirectory().AppendDirectory(local_bin);
    local->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    local->getRootDirectory().AppendDirectory(new HackDirectory("sys"));
    local->accessible = true;
    local->setSearchable();
    app->serverList.push_back(local);
    app->localSever = app->serverList[0];

    // end local
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


    app->serverList.push_back(cheater_zone);


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
    auto EntropyServer = new HackServer("247.112.153.237", "Entropy测试服务器", 1);
    auto Entropy_home = new HackDirectory("home");
    auto Entropy_bin = new HackDirectory("bin");

    Entropy_home->AppendFile(new HackTxtFile("Entropy_Induction_Test", L"祝贺你, \n"
                                                                       "  下载此文件以完成您的入组测试. \n"
                                                                       "  Entropy马上就会联系你. "));
    Entropy_bin->AppendFile(new HackTxtFile("BIT_PLZ_READ.txt", L"Bit, 别躲藏在阴影里了, 出来见见我吧, 我有事要跟你谈. \n"
                                                                "Vap0r不会放过我的, 我觉得有点儿不对劲--她肯定有什么事瞒着我, 可以告诉我吗? \n"
                                                                "-T"));

    EntropyServer->getRootDirectory().AppendDirectory(Entropy_home);
    EntropyServer->getRootDirectory().AppendDirectory(Entropy_bin);
    EntropyServer->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    EntropyServer->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    app->serverList.push_back(EntropyServer);

    //Entropy测试服务器

    //Slash-Bot 新闻服务器
    auto SlashServer = new HackServer("183.198.0.210", "Slash-Bot 新闻服务器", 1);
    auto Slash_MsgBoard = new HackDirectory("MsgBoard");
    auto listings = new HackDirectory("listings");
    listings->AppendFile(new HackTxtFile("Entropy_Group_engaged_in_malicious_Hacking?", L"Entropy 黑客组织要转型为骇客了?\n"
                                                                                        "\n"
                                                                                        "最近的报道称, 黑客组织\"Entropy\"收留了一个臭名昭著的骇客, 并且为他提供了工作. \n"
                                                                                        "我们还不能确认这个消息的真实性. 如果消息属实, 那么Entropy组织在将来一定会面临严峻的法律问题. \n"
                                                                                        "在我看来, 这样的举动会破坏现在的良好网络环境, 遏制那些富有创造力的黑客组织的发展. Entropy应当受到严厉的谴责. \n"
                                                                                        "记者 :  Tom Wilkins"));
    listings->AppendFile(new HackTxtFile("Suspicions_arise_over_Entropy", L"Entropy引起了公众的疑心\n"
                                                                          "\n"
                                                                          "在当今的网络世界中, 黑客组织Entropy因长期提供大量可靠的资源信息而出名. 然而, 该组织最近采购了一些可疑的信息之后, 就关闭了他们的公共信息终端. 这样的行为引起了同行们的疑心. \n"
                                                                          "虽然这个组织长时间以来因信息开源而在公众间享有良好的名誉, 但如果该组织真的做出不正当行为的话, 相关人士就必须采取措施了. \n"
                                                                          "我们将跟踪报道事态的发展. \n"
                                                                          "记者 : Tom Wilkins"));
    listings->AppendFile(new HackTxtFile("New_Macrosoft_Phone:_About_as_bad_as_you_expecte", L"巨硬公司发布新款手机 : 要多烂有多烂\n"
                                                                                             "\n"
                                                                                             "看起来巨硬公司的开发脚步根本停不下来. 我们的员工有幸得到一台最新的样品机\"Waterfall\", 然而经过我们的测试, 已经发现了很多严重的安全漏洞. \n"
                                                                                             "手机用户已经习惯于这个无处不在的科技巨头所开发的操作系统了, 然而这些安全漏洞使得任何安装在手机上的app都可以不受限制的控制手机, 该漏洞会让你的私人信息在未加密的情况下发送到网络上任何一个位置. \n"
                                                                                             "巨硬公司的第四代手机\"Waterfall\"本将在两星期后发售, 但由于漏洞的存在, 专家声称发售日期将延后一个月. 更多信息, 请关注我们的空间. "));
    listings->AppendFile(new HackTxtFile("Is_your_data_at_risk?", L"你的数据有风险吗?\n"
                                                                  "\n"
                                                                  "最近有一个恶意黑客组织非常活跃, 它致力于损害各种形式的网络社区媒体. 著名的网络交友社区FriendHole就是最近一次的受害者. \n"
                                                                  "对于网警来说这个组织的身份和位置仍然是个谜. 不过他们组织传达的信息很明确: \"在我们面前, 没有什么是安全的\". \n"
                                                                  "FaceSpace的CEO炸克伯格今天尝试安抚紧张的用户群, 他解释说, FaceSpace的安全措施是无懈可击的, 能查看用户个人信息的只有用户自己或用户指定的人, 还有FaceSpace 12000个值得信任的广告合作商. "));
    Slash_MsgBoard->AppendFile(new HackTxtFile("Config_CAUTION.txt", L"  ----- 警告 -----\n"
                                                                     "\n"
                                                                     "该文件夹中的config.sys是一个关键的系统文件. \n"
                                                                     "\n"
                                                                     "不要删除或者重命名这个文件\n"
                                                                     "\n"
                                                                     "这样做会使面板和主进程崩溃\n"
                                                                     "\n"
                                                                     "应在计划停机时间来更改该配置文件, 以避免机器崩溃. "));
    Slash_MsgBoard->AppendFile(new HackTxtFile("config.sys", L"010100110100101"));

    Slash_MsgBoard->AppendDirectory(listings);

    SlashServer->getRootDirectory().AppendDirectory(Slash_MsgBoard);
    SlashServer->getRootDirectory().AppendDirectory(new HackDirectory("home"));
    SlashServer->getRootDirectory().AppendDirectory(new HackDirectory("bin"));
    SlashServer->getRootDirectory().AppendDirectory(new HackDirectory("sys"));
    SlashServer->getRootDirectory().AppendDirectory(new HackDirectory("log"));

    app->serverList.push_back(SlashServer);
    //Slash-Bot 新闻服务器

    //Entropy资源服务器
    auto resourceServer = new HackServer("196.21.2.201", "Entropy资源服务器", 4);
    resourceServer->setAccessible(true);
    auto resource_home = new HackDirectory("home");
    auto resource_bin = new HackDirectory("bin");
    auto NewFolder22 = new HackDirectory("NewFolder22");

    NewFolder22->AppendFile(new HackTxtFile("IRC_Log:_178890_14081", L"*** Now talking in #christian\n"
                                                                     " -Word_of_God- Welcome Abstruse to #christian I am a Bible Bot. For more info type: /msg Word_of_God !info\n"
                                                                     " <Abstruse> !kjv numbers 22:21\n"
                                                                     " <Word_of_God>  Numbers 22:21 -- And Balaam rose up in the morning, and saddled his ass, and went with the princes of Moab. -  (KJV)\n"
                                                                     " *** SageRider sets mode: +b *!*@c211-30-208-111.rivrw3.nsw.optusnet.com.au\n"
                                                                     " *** Word_of_God was kicked from #christian by SageRider (Please dont Swear)\n"
                                                                     " <Abstruse> I know I'm never going to be able to come back in this channel again after this, but damn was it worth it to see that... "));
    resource_home->AppendFile(new HackTxtFile("Mantra.txt", L"Entropy 宗旨\n"
                                                            "我们的组织建立在三个准则之上. 我们力求做到这三点: \n"
                                                            "1)在任何事情上努力追求正义和公正\n"
                                                            "2)我们追求创造和分享, 而不是毁灭\n"
                                                            "3)永远不要为停滞不前而寻找理由\n"
                                                            "我们组织不会接受, 也不允许违背这三条准则的成员, 违反这三条准则的成员将会被直接开除. "));
    resource_home->AppendDirectory(NewFolder22);
    resource_bin->AppendFile(
            new HackBinFile("sshcrack.exe", HackCommand(&HacknetApplication::executive_sshcrack, "sshcrack", "-")));
    resource_bin->AppendFile(
            new HackBinFile("ftpbounce.exe", HackCommand(&HacknetApplication::executive_ftpbounce, "ftpbounce", "-")));

    resourceServer->getRootDirectory().AppendDirectory(resource_home);
    resourceServer->getRootDirectory().AppendDirectory(resource_bin);
    resourceServer->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    resourceServer->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    app->serverList.push_back(resourceServer);
    //Entropy资源服务器

    //Point Clicker服务器
    auto PointClickerServer = new HackServer("38.228.127.137", "Point Clicker", 2);
    auto PointClicker = new HackDirectory("PointClicker");
    auto PointClickerSave = new HackDirectory("Save");
    PointClickerSave->AppendFile(new HackTxtFile("Mengsk.pcsav", L"12312312412312312\n"
                                                                 "123123124123123\n"));
    PointClickerSave->AppendFile(new HackTxtFile("Bit.pcsav", L"4252423425463534\n"
                                                              "45411423441432323\n"));
    PointClickerSave->AppendFile(new HackTxtFile("Blizz.pcsav", L"75363456653633534\n"
                                                                "857736345252342342\n"));
    PointClicker->AppendDirectory(PointClickerSave);
    PointClickerServer->getRootDirectory().AppendDirectory(new HackDirectory("home"));
    PointClickerServer->getRootDirectory().AppendDirectory(new HackDirectory("bin"));
    PointClickerServer->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    PointClickerServer->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    app->serverList.push_back(PointClickerServer);
    //Point Clicker服务器

    //PP市场服务器
    auto PPServer = new HackServer("234.228.181.58", "PP市场公司", 2);
    auto PP_home = new HackDirectory("home");
    auto PP_WORKSPACE = new HackDirectory("WORKSPACE");
    auto PP_document = new HackDirectory("documents");
    PP_WORKSPACE->AppendFile(new HackTxtFile("SECURE_MAILLIST.dec", L"010100101010101010\n"
                                                                    "010010101010100101\n"
                                                                    "010100101010101010\n"
                                                                    "010010101010010101\n"
                                                                    "100101010010101010\n"
                                                                    "010101010010101010\n"
                                                                    "The file content is too long to display"));
    PP_WORKSPACE->AppendFile(new HackTxtFile("Maillist_info.txt",
                                             L"这就是我们从黑客手中得到的邮件列表(顺便一提, 我们给这家伙付了不少钱). 结果这邮件列表还是加密的? 那我们到底为啥要付钱给这个黑客? \n"
                                             "HR说他会找其他人来尝试解码这个邮件列表, 或者只要有人能从中提取出有用的东西都行. 根据黑客的说法, 这个文本的大小是正确的, 所以只要我们能破解开这个文件, 我们就能得到正确的数据. \n"
                                             "真麻烦. 好吧, 至少这邮件列表确实在我们手里了, 虽然我们还打不开...  ."));
    PP_document->AppendFile(new HackTxtFile("IncidentLog1.txt", L"[nem] 你周末登录了S3吗? \n"
                                                                "\n"
                                                                "[felix] 没, 怎么了? \n"
                                                                "\n"
                                                                "[nem] 有些文件丢失了, 我们的宽带使用率也显示错误. 然而我并没有查到相应的操作日志. \n"
                                                                "\n"
                                                                "[felix] 这有点奇怪啊. \n"
                                                                "\n"
                                                                "[felix] 你有没有查看过防火墙的完整性? \n"
                                                                "\n"
                                                                "[nem] 还没. \n"
                                                                "\n"
                                                                "[nem] 糟了. \n"
                                                                "\n"
                                                                "[felix] 怎么了? \n"
                                                                "\n"
                                                                "[nem] 邮件服务器的RDP服务已经宕机了. \n"
                                                                "\n"
                                                                "[nem] 我去机房瞅瞅. \n"
                                                                "\n"
                                                                "[nem] 马上回来. "));
    PP_home->AppendDirectory(PP_WORKSPACE);
    PP_home->AppendDirectory(PP_document);
    PPServer->getRootDirectory().AppendDirectory(PP_home);
    PPServer->getRootDirectory().AppendDirectory(new HackDirectory("bin"));
    PPServer->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    PPServer->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    app->serverList.push_back(PPServer);
    //PP市场服务器
    return app;
}
