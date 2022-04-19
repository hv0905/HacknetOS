//
// Created by epiphyllum on 22/04/19.
//

#include "StringUtil.h"
#include <cctype>

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
