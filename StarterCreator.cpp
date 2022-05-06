//
// Created by epiphyllum on 22/04/20.
//

#include "StarterCreator.h"
#include "HackTxtFile.h"
#include "HackBinFile.h"

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
                                   "0", 1, MODE_PURE_MISSION, &MissionCheckService::check_mission_1),
        HackEmail(L"让我们来一起获取一些工具", L"Bit", L"很好 - 你现在应该安全了! 至少在你的电脑上...  \n"
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
                                           "毒蛇作战基地服务器：176.198.61.104\n"
                                           "      \n"
                                           "--Bit\n"
                                           "0"),
        HackEmail(L"初试牛刀", L"Bit", L"首先祝贺你! \n"
                                   "说实话...  .你这样回复我, 也不知道你到底成功了没, 不过既然你正在读这封邮件意味着你至少发现了一些东西, 我先假定你找到的那程序是有用的. \n"
                                   "\n"
                                   "我给你准备了一个小游戏, 让你试试你找到的新工具. 说实话, 我做这游戏可花了不少时间  -  -  我差点以为我要把这游戏带进坟墓里了. \n"
                                   "\n"
                                   "这个服务器的安全性对你来说应该不是太高, 我想让你黑进去, 找到我的帐号, 然后删掉它. \n"
                                   "\n"
                                   "你可能会需要使用你的新工具. 你可以通过输入\"程序名 端口号\"来调用它, 就像这样: \n"
                                   "\n"
                                   ">SSHCrack 22\n"
                                   " ^文件名   ^端口号\n"
                                   "    \n"
                                   "黑掉你找到的端口. \n"
                                   "\n"
                                   "对了, 给你提醒一下, 当你输入\"ssh\"然后按下Tab键就会自动补全命令, 这适用于所有的命令. \n"
                                   "\n"
                                   "祝你好运! \n"
                                   "\n"
                                   "Bitwise 测试PC@210.175.139.250\n"
                                   "\n"
                                   "--Bit\n"
                                   "0"),
        HackEmail(L"善始善终", L"Bit", L"好样的! 从现在开始事情变得越来越复杂了. \n"
                                   "我需要你帮我一个忙. \n"
                                   "最近我因一点点小马虎而给自己惹了不少麻烦. 这就是为什么我给你写这封邮件. 总而言之, 我的意思是, 有几台电脑上有一些我本不想存放在那里的操作日志. \n"
                                   "你一定要记住这点 -- 不要忘记删除你的操作日志. 如果你之前从没删过, 那就从现在开始. 你在任何现代的操作系统上所做的一切都会被跟踪记载在日志文件夹(~/log)下. 只需要进入这个文件夹, 使用\"rm *\"命令删除所有信息即可. 永远不要忘记这点. \n"
                                   "Anderson的卧室电脑:247.112.153.237\n"
                                   "--Bit\n"
                                   "0\n"
                                   "   "),
        HackEmail(L"生涯起点", L"Bit", L"好样的! 如果你收到这封邮件, 说明你做的很好... 恩, 也许这一切真的是值得的. \n"
                                   "我对你抱有的期望是不是太大了? 也许吧. \n"
                                   "我知道我没有充裕的时间来一点点教你, 你要学的东西太多了. 所以, 我的决定如下. \n"
                                   "有一个叫'Entropy'的组织目前正在招收新成员. 他们会教你更多黑客知识. 当你的黑客技术足以帮我完成我的夙愿时, 我会再联系你. \n"
                                   "为了进入Entropy, 你需要绕过一个代理服务器, 在你已经得到管理员权限计算机上运行几个shell(使用shell命令), 它可以用来过载代理服务器. \n"
                                   "祝你好运... \n"
                                   "还有, 谢谢. \n"
                                   "Entropy测试服务器:199.59.149.230\n"
                                   "--Bit\n"
                                   "0\n"
                                   "\n"),
        HackEmail(L"任务完成", L"Entropy", L"你好,\n"
                                       "\n"
                                       "首先, 祝贺你成功通过了Entropy黑客组织的考试! 当然了, 这种程度的考试对于一个经验丰富的黑客来说是小事一桩. 然而令人惊讶的是, 能通过这场考试的人并不多. \n"
                                       "在你正式加入我们组织之前, 我们必须对你的能力进行进一步的考验.\n"
                                       "最近, 有一家新闻网站摆明了同我们的对立立场. 我们希望你能临时瘫痪他们的服务器. 作为测试你能力的第二项任务, 我们要求你搞垮他们的新闻版块. 如果可以的话, 不要破坏无关的服务器和那些与Entropy无关的文章 -- 我们没必要把事情做的那么绝. \n"
                                       "这项任务可不是仅仅让你删除文章这么简单 -- 我们还要搞垮他们的程序. \n"
                                       "Slash-Bot 新闻服务器:183.198.0.210\n"
                                       "-Tex"),
        HackEmail(L"欢迎", L"Entropy", L"\n"
                                     "恭喜, \n"
                                     "你出色及时地完成了你的第一项任务, 让我们见识到了你的能力. 现在, 我诚挚地欢迎你来到Entropy黑客组织. \n"
                                     "在我们的资源服务器里, 你可以找到管理员账户的详细资料. 作为组织送给你的见面礼, 你可以去资源服务器里面随意下载你所需要的程序, 同时记得阅读我们组织的宗旨. 一旦你准备好了, 请回复这封邮件. 我会给你安排一些真正有挑战的任务. \n"
                                     "再次的恭喜你通过测试. \n"
                                     "Entropy资源服务器:196.21.2.201\n"
                                     "-Tex\n"),
        HackEmail(L"RE:欢迎", L"Entropy",
                  L"很好, 看来你拿到了你所需的东西. 那么, 你就可以正式地开始接受Enpropy黑客组织的各项任务了. 附件里我给出了我们组织的任务资源数据库的ip地址, 还一并给出了你的用户名和密码以用于获得登录权限. \n"
                  "当你有空的时候, 就去接受并完成你的第一项任务吧. \n"
                  "届时我将会再次联系你来评估你的任务进度. \n"
                  "-Tex\n"),
        HackEmail(L"Point_Clicker", L"Entropy MailBot", L"你好, \n"
                                                        "我现在有点郁闷, 但更倒霉的是, 我的那些同事没一个能帮的上忙的. \n"
                                                        "虽然我很反感向外界寻求帮助, 但是我只能这么做了. \n"
                                                        "把你们组织介绍给我的那个人向我保证你们会保密, 所以我就简要说明一下: 我在PointClicker里已经刷到无敌了, 我希望我能再刷一遍二周目来证明我在这个游戏里的王者地位. 然而这个游戏并没有重置按钮. \n"
                                                        "我希望你能黑进游戏服务器删掉我的存档, 这样我就能再爽一次了. 我的用户名是\"Mengsk\". 你要是想的话, 在你删之前可以先感受一下我的存档有多屌. \n"
                                                        "即将\"脱坑\"的, \n"
                                                        "PointClicker服务器:38.228.127.137\n"
                                                        "-M"),
        HackEmail(L"经典的反黑客攻击", L"Entropy MailBot", L"你好黑客, \n"
                                                   "\"PP市场\"公司最近雇佣了一名自由黑客, 他入侵了竞争对手公司的服务器窃取了一些敏感信息(我们猜测应该是邮件形式的简历列表). 他把这些简历从对手公司的服务器里删掉了, 并将简历转交到雇主公司的招聘部门. \n"
                                                   "这种商业间谍行为很明显是在给黑客的声誉抹黑. 虽然我们对他们公司之间的竞争并不感兴趣, 但是\"PP市场\"公司雇佣黑客的消息已经传遍了整个网络, 所以我们要确保\"PP市场\"这次吃不了兜着走. \n"
                                                   "我们不知道那些文件的确切名字, 所以你找的时候要费点心思. 记住, 你要找的是一份被偷走的邮件列表 -- 它们可能被加密或归档了. 注意, PP公司可能会对此有所防范, 他们应该会采取相应的安全措施. \n"
                                                   "PP市场:234.228.181.58\n"
                                                   "-Entropy 管理员"),
        HackEmail(L"重返校园", L"Entropy MailBot", L"各位黑客, \n"
                                               "Milburgh高中的管理层联系到我们, 希望我们能悄悄地搞到他们IT部门员工的管理员密码, 以此就IT部门都保存了学生的什么数据来展开一项调查. \n"
                                               "当你入侵时, 务必使一切数据保留原样 -- 任何的篡改将会影响到管理层人员的判断. \n"
                                               "而你所需要做的, 就是黑进去, 找到密码, 然后清除你的操作日志, 把密码回复给我. 至于如何把密码交给学校的管理层就不需要你操心了. \n"
                                               "祝你好运, \n"
                                               "Milburg高中IT办公室：92.24.43.165\n"
                                               "-Entropy 管理员"),
        HackEmail(L"RE:重返校园", L"Entropy MailBot", L"你确定? \n"
                                                  "*******... . 我不知道想出这种密码的人是天才还是白痴, 还是说两者都是? \n"
                                                  "妈的, 我是说, 当初我也找到了这个密码, 而且我的核验脚本显示这个密码的正确的, 然而我还在继续独自破解那些星号! \n"
                                                  "这就他妈的尴尬了... .这你叫我怎么去跟学校的头头们解释? \n"
                                                  "不论怎么说... 问题解决了, 你做的不错. \n"
                                                  "-管理员")

};

HacknetApplication *StarterCreator::createStarterOS()
{

    auto app = new HacknetApplication();
    // add emails
    for (auto &email: Email)
    {
        app->emailList.push_back(new HackEmail(email));
    }
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

    //Milburg高中IT办公室
    auto MilburgServer=new HackServer ("92.24.43.165","Milburg高中IT办公室",1);
    auto Milburg_home=new HackDirectory("home");
    auto MH_STAFF=new HackDirectory("MH_STAFF");
    MH_STAFF->AppendFile(new HackTxtFile("pw_memo.log",L"4:37 PM - MBIT: 我一直在想咱学校的网络安全系统\n"
                                                       "4:37 PM - JBrooks: 是么\n"
                                                       "4:37 PM - MBIT: 嗯, 我觉得这些升级神马的全都是劳民伤财\n"
                                                       "4:37 PM - MBIT: 你试试这个\n"
                                                       "4:38 PM - MBIT: 最简单的办法\n"
                                                       "4:38 PM - MBIT: 我们只需要把IT的密码设成这个\n"
                                                       "4:38 PM - MBIT: *******\n"
                                                       "4:38 PM - JBrooks: 什么鬼\n"
                                                       "4:38 PM - MBIT: 就是这个啊! \n"
                                                       "4:38 PM - MBIT: 就是7个*啊\n"
                                                       "4:38 PM - MBIT: 这就是密码, 只有星号\n"
                                                       "4:38 PM - MBIT: 谁会想到会是这个密码? ! 肯定没有人能猜的到! 就算有人黑到了密码, 那看起来也像是被加密了的密码. \n"
                                                       "4:38 PM - MBIT: 这简直就是牢不可破啊! "));
    MH_STAFF->AppendFile(new HackTxtFile("Announcements.txt",L"关于网络/代理服务器瘫痪的通知\n"
                                                             "虽然我们的一部分员工不知道代理服务器瘫痪是什么意思, 但是很明显我们的一部分学生知道那意味着什么. \n"
                                                             "在通知发出的那个晚上, 很明显发现了网络连接依然可用, 但是绿网并没有工作. 在接下来的20分钟里有22T的爱情动作片被下载到了学校的服务器和各个房间的电脑内. \n"
                                                             "很明显我们想通过加强安全手段避免让这件事再一次发生. 也许, 不通知学生们这种事情会好很多. \n"
                                                             "非常感谢\n"
                                                             "\n"
                                                             "-校长办公室"));
    Milburg_home->AppendDirectory(MH_STAFF);

    MilburgServer->getRootDirectory().AppendDirectory(Milburg_home);
    MilburgServer->getRootDirectory().AppendDirectory(new HackDirectory("bin"));
    MilburgServer->getRootDirectory().AppendDirectory(new HackDirectory("log"));
    MilburgServer->getRootDirectory().AppendDirectory(new HackDirectory("sys"));

    app->serverList.push_back(MilburgServer);
    //Milburg高中IT办公室

    return app;
}
