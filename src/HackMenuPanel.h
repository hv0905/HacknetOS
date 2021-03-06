//
// Created by epiphyllum on 22/04/25.
//

#ifndef HACKNETOS_HACKMENUPANEL_H
#define HACKNETOS_HACKMENUPANEL_H

#include <string>
#include <vector>

class HackMenuPanel
{
    std::string title;
    int currentSkip = 0;
    int currentSelection = 0;
    bool reverse = false;
    std::vector<std::string> items;

    const int MAX_VISIBLE_ITEMS = 48;

public:
    // Return selected index
    // -1: No selection
    HackMenuPanel(const std::string &title, const std::vector<std::string> &items);

    int Exec();

    void upItem();

    void downItem();

    void Draw();

    void setReverse(bool reverse);


};


#endif //HACKNETOS_HACKMENUPANEL_H
