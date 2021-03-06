//
// Created by epiphyllum on 22/04/12.
//

#include "MusicUtil.h"
#include <Windows.h>
#include <cstdio>
#include <filesystem>

// required for music player lib
#pragma comment(lib, "Winmm.lib")

void MusicUtil::playBgm(int id)
{
    if (loaded) {
        stopAndClose();
    }
    char message[256]{};
    std::filesystem::path path = std::filesystem::current_path() / bgm[id];
    sprintf(message, "open \"%ls\" type mpegvideo alias bgm", path.c_str());
    mciSendStringA(message, nullptr, 0, nullptr);
    mciSendStringA("play bgm repeat", nullptr, 0, nullptr);

    loaded = true;
    //sndPlaySoundW(path.c_str(), SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void MusicUtil::stopAndClose()
{
    if (!loaded) return;
    mciSendStringA("stop bgm", nullptr, 0, nullptr);
    mciSendStringA("close bgm", nullptr, 0, nullptr);
    loaded = false;
}

void MusicUtil::playNotif(int id)
{
    if (currentNotif != id)
    {
        loadNotif(id);
    }

    mciSendStringA("play notif", nullptr, 0, nullptr);

}

void MusicUtil::loadNotif(int id)
{
    if (id != -1)
    {
        mciSendStringA("stop notif", nullptr, 0, nullptr);
        mciSendStringA("close notif", nullptr, 0, nullptr);
    }
    char message[256]{};
    std::filesystem::path path = std::filesystem::current_path() / notif[id];
    sprintf(message, "open \"%ls\" type mpegvideo alias notif", path.c_str());
    mciSendStringA(message, nullptr, 0, nullptr);

}
