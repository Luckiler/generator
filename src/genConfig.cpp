#include <iostream>
#include "genConfig.h"

int genConfig::avoidRadius = 1;

char genConfig::printChar = '@',
     genConfig::startPrintChar = 'S',
     genConfig::eolPrintChar = 'O',
     genConfig::teleportPrintChar = 'T',
     genConfig::finishPrintChar = 'F',
     genConfig::borderChar = '#';

rectGen rectGen;

genConfig::genConfig()
{

}

void genConfig::preGenerate()
{
    //Menu loop
    bool repeat = true;
    while(repeat)
    {
        menu.splash();
        std::cout << "Canvas dimensions : " << rectGen::length << " x " << rectGen::height;
        std::cout << "\nSeed : " << rectGen::seed;
        std::cout << "\nIterations : " << rectGen::nbrOfIt;
        std::cout << "\n\n What property do you want to change?\n";
        std::cout << " 1 - Canvas length\n 2 - Canvas height\n 3 - Seed\n 4 - Number of iterations\n";
        std::cout << "\n 9 - Back\n";

        int input;
        std::cin >> input;
        switch(input)
        {
        case 1:
            {
                menu.splash();
                std::cout << "Current length : " << rectGen::length << "\n";
                std::cout << "Enter new length : ";
                std::cin >> input;

                if(input > 0 && input < 4294967295)
                {
                    rectGen::length = input;
                }
                break;
            }
        case 2:
            {
                menu.splash();
                std::cout << "Current height : " << rectGen::height << "\n";
                std::cout << "Enter new height : ";
                std::cin >> input;

                if(input > 0 && input < 4294967295)
                {
                    rectGen::height = input;
                }
                break;
            }
        case 3:
            {
                menu.splash();
                std::cout << "Current seed : " << rectGen::seed << "\n";
                std::cout << "Enter new seed : ";
                std::cin >> input;

                if(input > -2147483648 && input < 214783647)
                {
                    rectGen::seed = input;
                }
                break;
            }
        case 4:
            {
                menu.splash();
                std::cout << "Current number of iterations to perform : " << rectGen::nbrOfIt << "\n";
                std::cout << "Enter new number of iterations to perform : ";
                std::cin >> input;

                if(input > 0 && input < 4294967295)
                {
                    rectGen::nbrOfIt = input;
                }
                break;
            }
        case 9:
            {
                repeat = false;
                break;
            }
        default:
            {
                break;
            }
        }
    }
}
