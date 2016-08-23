#include <iostream>
#include "menu.h"
#include "rectGen.h"

menu::menu()
{
    //ctor
}

void menu::general()
{
    //This is actually the main loop
    bool repeat = true;
    while(repeat)
    {
        //Simple menu
        menu::splash();
        std::cout << " 1 - Generate\n 2 - Configure\n 9 - Exit\n";
        int input;
        std::cin >> input;
        switch(input)
        {
        case 1:
            {
            //Starts the pregeneration process
            rectGen rectGen;
            rectGen.initialize(genConfig::avoidRadius);
            break;
            }
        case 2:
            {
            //Starts the configuration menu(WIP)
            break;
            }
        case 9:
            //Breaks the while loop
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
    std::cout << " - Random 'pattern' generator - \n\n\n\n";
}

void menu::clearScr()
{
    //Cheap way of 'clearing the screen'. We just bring everything up really.
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
