#ifndef GENCONFIG_H
#define GENCONFIG_H
#include <string>
#include "rectGen.h"
#include "menu.h"

class genConfig
{
    public:
        genConfig();
        void mainConfigMenu();
        void preGenerate();

        static int avoidRadius;

        static char printChar,
                    startPrintChar,
                    eolPrintChar,
                    teleportPrintChar,
                    finishPrintChar,
                    borderChar;

    private:
        char setChar(std::string charName);
        menu menu;
};

#endif // GENCONFIG_H
