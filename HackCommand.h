//
// Created by epiphyllum on 22/04/18.
//

#ifndef HACKNETOS_HACKCOMMAND_H
#define HACKNETOS_HACKCOMMAND_H

#include <string>
#include <sstream>

class __single_inheritance HacknetApplication;

typedef void (HacknetApplication::*CommandHandler)(std::stringstream &args);


class HackCommand
{
    std::string prefix;
    std::string pattern;
    std::string helpText;

    bool requiredHacked = false;
    bool shouldLog = false;

    CommandHandler handler;

public:
    HackCommand(CommandHandler handler, const std::string &prefix,
                const std::string &helpText = "", const std::string &pattern = "", bool requiredHacked = false,
                bool shouldLog = false);


    [[nodiscard]] const std::string &getPrefix() const;

    [[nodiscard]] const std::string &getPattern() const;

    [[nodiscard]] const std::string &getHelpText() const;

    [[nodiscard]] CommandHandler getHandler() const;

    [[nodiscard]] bool isRequiredHacked() const;

    [[nodiscard]] bool isShouldLog() const;

    void setPrefix(const std::string &prefix);


};


#endif //HACKNETOS_HACKCOMMAND_H
