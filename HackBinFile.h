//
// Created by epiphyllum on 22/04/19.
//

#ifndef HACKNETOS_HACKBINFILE_H
#define HACKNETOS_HACKBINFILE_H

#include "HackFile.h"
#include "HackCommand.h"

class HackBinFile : public HackFile
{
    HackCommand relatedCommand;

public:
    HackBinFile(const std::string &name, const HackCommand &relatedCommand);

    explicit HackBinFile(const HackCommand &relatedCommand);

    HackBinFile *clone() override;

    std::string cat() override;

    [[nodiscard]] const HackCommand &getRelatedCommand() const;

};


#endif //HACKNETOS_HACKBINFILE_H
