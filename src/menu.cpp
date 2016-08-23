#include <iostream>
#include "menu.h"
#include "rectGen.h"

menu::menu()
{
    //ctor
}

void menu::general()
{
    bool repeat = true;
    while(repeat)
    {
        menu::splash();
        std::cout << " 1 - Generate\n 2 - Configure\n 9 - Exit\n";
        int input;
        std::cin >> input;
        switch(input)
        {
        case 1:
            {
            //Starts the generation
            rectGen rectGen;
            rectGen.initialize(genConfig::avoidRadius);
            break;
            }
        case 2:
            {
            //starts the configuration menu
            break;
            }
        case 9:
            repeat = false;
            break;
        default:
            break;
        }
    }
}

void menu::splash()
{
    menu::clearScr();
    std::cout << " - Random 'pattern' generator - \n\n";
}

void menu::clearScr()
{
    //Cheap way of 'clearing the screen'. We just bring everything up really.
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
