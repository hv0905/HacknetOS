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

}


#endif //HACKNETOS_STRINGUTIL_H
