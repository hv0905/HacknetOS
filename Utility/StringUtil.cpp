//
// Created by epiphyllum on 22/04/19.
//

#include "StringUtil.h"
#include <cctype>
#include <algorithm>
#include <Windows.h>

void StringUtil::ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
    {
        return !std::isspace(ch);
    }));
}

void StringUtil::rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
    {
        return !std::isspace(ch);
    }).base(), s.end());
}

void StringUtil::trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}

std::vector<std::string> StringUtil::split(const std::string &s, const std::string &delim)
{
    std::vector<std::string> elems;
    size_t pos = 0;
    size_t len = s.length();
    size_t delim_len = delim.length();
    if (delim_len == 0) return elems;
    while (pos < len)
    {
        int find_pos = s.find(delim, pos);
        if (find_pos == std::string::npos)
        {
            elems.push_back(s.substr(pos, len - pos));
            break;
        }
        elems.push_back(s.substr(pos, find_pos - pos));
        pos = find_pos + delim_len;
    }

    if (pos == len)
    { // BY DESIGN: we should add the last elem even if it is empty
        elems.emplace_back("");
    }

    return elems;
}

bool StringUtil::isAscii(wchar_t wc)
{
    return wc <= 0x7F;
}

std::vector<std::wstring> StringUtil::splitLines(const std::wstring &src, int lenPerLine)
{
    std::vector<std::wstring> lines;
    std::wstring line;
    line.reserve(lenPerLine);
    int left = lenPerLine;
    for (auto &item: src)
    {
        if (item == L'\n')
        {
            lines.push_back(line);
            line.clear();
            left = lenPerLine;
            continue;
        }
        int len = isAscii(item) ? 1 : 2;
        if (left < len)
        {
            lines.push_back(line);
            line.clear();
            left = lenPerLine;
        }
        line.push_back(item);
        left -= len;
    }
    if (!line.empty())
    {
        lines.push_back(line);
    }
    return lines;
}

std::wstring StringUtil::s2ws(const std::string &s)
{
    int len;
    int slength = (int) s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, nullptr, 0);
    auto *buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

std::string StringUtil::ws2s(const std::wstring &ws)
{
    int len;
    int slength = (int) ws.length() + 1;
    len = WideCharToMultiByte(CP_ACP, 0, ws.c_str(), slength, nullptr, 0, nullptr, nullptr);
    auto *buf = new char[len];
    WideCharToMultiByte(CP_ACP, 0, ws.c_str(), slength, buf, len, nullptr, nullptr);
    std::string r(buf);
    delete[] buf;
    return r;
}

void StringUtil::toLower(std::string &s)
{
    std::transform(s.begin(), s.end(), s.begin(), std::tolower);
}

std::string StringUtil::toLowerCopy(const std::string &s)
{
    std::string r = s;
    toLower(r);
    return r;
}

bool StringUtil::endsWith(std::string src, std::string suffix)
{
    if (suffix.size() > src.size())
    {
        return false;
    }
    return std::equal(suffix.rbegin(), suffix.rend(), src.rbegin());
}

