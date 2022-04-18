//
// Created by epiphyllum on 22/04/18.
//

#include "HackCommand.h"

HackCommand::HackCommand(CommandHandler handler, const std::string &prefix,
                         const std::string &helpText, const std::string &pattern, bool requiredHacked, bool shouldLog)
        : prefix(prefix), pattern(pattern), helpText(helpText),
          handler(handler), requiredHacked(requiredHacked), shouldLog(shouldLog)
{}

const std::string &HackCommand::getPrefix() const
{
    return prefix;
}

const std::string &HackCommand::getPattern() const
{
    return pattern;
}

const std::string &HackCommand::getHelpText() const
{
    return helpText;
}

CommandHandler HackCommand::getHandler() const
{
    return handler;
}

bool HackCommand::isRequiredHacked() const
{
    return requiredHacked;
}

bool HackCommand::isShouldLog() const
{
    return shouldLog;
}

