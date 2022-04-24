//
// Created by epiphyllum on 22/04/19.
//

#include "HackBinFile.h"


HackBinFile *HackBinFile::clone()
{
    return new HackBinFile(*this);
}

std::string HackBinFile::cat()
{
    return "Not Implement Yet";
}

const HackCommand &HackBinFile::getRelatedCommand() const
{
    return relatedCommand;
}

HackBinFile::HackBinFile(const std::string &name, const HackCommand &relatedCommand) : HackFile(name),
                                                                                       relatedCommand(relatedCommand)
{}

HackBinFile::HackBinFile(const HackCommand &relatedCommand) : relatedCommand(relatedCommand)
{}
