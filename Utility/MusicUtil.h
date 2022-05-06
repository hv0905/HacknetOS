//
// Created by epiphyllum on 22/04/12.
//

#pragma once
#ifndef HACKNETOS_MUSICUTIL_H
#define HACKNETOS_MUSICUTIL_H

class MusicUtil
{

    static constexpr const char *const bgm[] = {"bgm\\0.mp3"};
    static constexpr const char *const notif[] = {"bgm\\n0.mp3"};
    static inline bool loaded = false;
    static inline int currentNotif = -1;

    static void loadNotif(int id);

public:
    static void playBgm(int id);

    static void playNotif(int id);

    static void stopAndClose();

    static bool isLoaded()
    {
        return loaded;
    }
};


#endif //HACKNETOS_MUSICUTIL_H
