//
// Created by epiphyllum on 22/04/19.
//

#ifndef HACKNETOS_HACKEXECUTIVEFILE_H
#define HACKNETOS_HACKEXECUTIVEFILE_H

#include "HackFile.h"
#include "HackCommand.h"
#include "HackBinaryFile.h"

class HackExecutiveFile : public HackBinaryFile
{

    HackCommand relatedCommand;

public:
    HackExecutiveFile(const std::string &name, const HackCommand &relatedCommand);

    explicit HackExecutiveFile(const HackCommand &relatedCommand);

    HackExecutiveFile *clone() override;

    [[nodiscard]] const HackCommand &getRelatedCommand() const;

};


#endif //HACKNETOS_HACKEXECUTIVEFILE_H
