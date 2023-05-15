# HacknetOS

[![Cover](web/cover.min.jpg)](web/cover.png)

_封面作品使用Stable Diffusion + Anything v4.5制作_

[![Build](https://github.com/hv0905/HacknetOS/actions/workflows/Build.yml/badge.svg)](https://github.com/hv0905/HacknetOS/actions/workflows/Build.yml)
[![Release](https://img.shields.io/github/v/release/hv0905/HacknetOS)](https://github.com/hv0905/HacknetOS/releases)

游戏 [Hacknet](https://hacknet-os.com) 的纯C++控制台复刻.

[English document](index.md)

## ✨ 特性

- 在纯控制台中实现的黑客游戏
- 与真实UN*X极为相似的终端及文件系统逻辑.
- 每一个破解工具都有独特的基于ASCII的动画.

## ✈️ 开始游戏!

### 下载和运行

从 [Release](https://github.com/hv0905/HacknetOS/releases)
或从 [构建流水线](https://github.com/hv0905/HacknetOS/actions/workflows/Build.yml)下载HacknetOS最新的构建版本.

直接运行`HacknetOS.exe`.
强烈建议在[Windows Terminal](https://apps.microsoft.com/store/detail/windows-terminal/9N0DX20HK701?hl=en-us&gl=US)
中启动游戏以获得更好的游戏体验.

你必须把你的控制台窗口缩放到至少220 x 50的大小才可以正常运行游戏. 如果你的电脑屏幕可容纳内容过少以至于无法设置到这个尺寸,你可以考虑降低DPI缩放或者减小控制台字体大小.

### 启用bgm功能

> 这步是可选的, 游戏在没有bgm文件的情况下也可正常工作.

1. 从Steam购买并下载 [Hacknet OST](https://store.steampowered.com/app/408710/Hacknet_Official_Soundtrack/)
2. 使用PowerShell运行`generate_bgm.ps1`即可自动生成bgm目录.
3. 如果你已经打开了HacknetOS, 重启游戏.

## 📷 截图

![title](web/screenshots/title.jpg)

![tutorial](web/screenshots/tutorial.jpg)

![crack](web/screenshots/crack.jpg)

![mailbox](web/screenshots/mailbox.jpg)

## 🪧 未来功能计划

- 使用JSON进行存读档(没错, 因为之前参加比赛的限制, 这个游戏不可以存读档==)
- 将初始存档从代码文件中分离
- 实现更多原版游戏中有但本游戏没有的命令
- 国际化支持
- 跨平台支持

## 💻 构建和开发

本项目使用Cmake构建, 如需构建本项目请按下面几步操作:

1. 下载以下必须依赖: `Micorsoft Visual C++ buildtool`, `CMake`
2. 在源代码目录下运行以下命令:

```shell
mkdir build && cd build # Create build dir
cmake .. # Initialize CMake project
cmake --build . # Build the project
```

> 目前, 本项目只支持在windows平台下使用`MSVC`工具链进行编译.(但是可以使用类似Ninja等等构建器来加速编译)
>
> 跨平台支持已列入计划!
>

强烈建议使用以下编辑器或ide完成开发:

- CLion
- Visual Studio(安装CMake工作负载)
- Visual Studio Code

## ❤ 如何贡献

为它做贡献未必一定要贡献代码。哪怕你只是简单的记录了Bug，提交了Issue，甚至在社区里讨论它都对我们很大的帮助。

如果你需要修改它的代码，请先fork它，再创建一个功能分支。这样可以保持我们的主支流整洁。

如果你希望反馈它，请在反馈的同时附带详细的故障说明和错误日志。这将极大的有助于我们诊断该问题。

## 特别感谢

剧本和创意来自: [Hacknet](https://hacknet-os.com)

如果你喜欢这类型的游戏, 一定要去试试原版游戏!

## Copyright

Copyright 2022 EdgeNeko  
Licensed under GPLv3 license.