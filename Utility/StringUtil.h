//
// Created by epiphyllum on 22/04/19.
//

#ifndef HACKNETOS_STRINGUTIL_H
#define HACKNETOS_STRINGUTIL_H

#include <string>
#include <vector>

namespace StringUtil
{
    void ltrim(std::string &s);

    void rtrim(std::string &s);

    void trim(std::string &s);

    std::vector<std::string> split(const std::string &s, const std::string &delim);

    inline bool isAscii(wchar_t wc);

    std::vector<std::wstring> splitLines(const std::wstring &src, int lenPerLine);

    std::wstring s2ws(const std::string &s);

    std::string ws2s(const std::wstring &ws);

    void toLower(std::string &s);

    std::string toLowerCopy(const std::string &s);

    bool endsWith(std::string src, std::string suffix);

}


#endif //HACKNETOS_STRINGUTIL_H
