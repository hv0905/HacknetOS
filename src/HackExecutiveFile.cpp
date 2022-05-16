//
// Created by epiphyllum on 22/04/19.
//

#include "HackExecutiveFile.h"


HackExecutiveFile *HackExecutiveFile::clone()
{
    return new HackExecutiveFile(*this);
}

const HackCommand &HackExecutiveFile::getRelatedCommand() const
{
    return relatedCommand;
}

HackExecutiveFile::HackExecutiveFile(const std::string &name, const HackCommand &relatedCommand) : HackBinaryFile(name),
                                                                                                   relatedCommand(
                                                                                                           relatedCommand)
{}

HackExecutiveFile::HackExecutiveFile(const HackCommand &relatedCommand) : relatedCommand(relatedCommand)
{}
