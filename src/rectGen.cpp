#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include "rectGen.h"
#include "genConfig.h"

genConfig genConfig;

int rectGen::height = 50,
    rectGen::length = 100;
unsigned int rectGen::seed = 1337,
             rectGen::nbrOfIt = 100;

rectGen::rectGen()
{

}

void rectGen::initialize(unsigned int avoidRadius)
{
    bool repeat = true;
    while(repeat)
    {
        menu.clearScr();
        std::cout << "Canvas dimensions : " << rectGen::length << " x " << rectGen::height;
        std::cout << "\nSeed : " << rectGen::seed;
        std::cout << "\nIterations : " << rectGen::nbrOfIt;
        std::cout << "\n\n 1 - Generate with current settings\n 2 - Change settings\n";

        int input;
        std::cin >> input;

        switch(input)
        {
        case 1:
            {
                repeat = false;
                break;
            }
        case 2:
            {
                genConfig.preGenerate();
                break;
            }
        default:
            {
                break;
            }
        }
    }

    //Here we prepare the 2D vector by filling it with ' ' so it is able to
    //hold the later computed values
    std::vector<std::vector<char> > grid;
    grid.resize(rectGen::height);
    for (int x = 0; x < rectGen::height; x++)
    {
        grid[x].resize(rectGen::length);
        for (int y = 0; y < rectGen::length; y++)
        {
            grid[x][y] = ' ';
        }
    }

    //We setup the starting point of the pattern
    unsigned int startPoint[2];
    startPoint[0] = seed % rectGen::height;
    startPoint[1] = seed % rectGen::length;
    grid[startPoint[0]][startPoint[1]] = genConfig::startPrintChar;

    //We assign the grid to the computed one and print it
    grid = rectGen::iteration(grid, startPoint, rectGen::nbrOfIt, rectGen::seed);
    rectGen::print2DVector(grid);
    std::cout << "\n\n 1 - Save to file(WIP)\n 9 - Back\n";
    int input;
    std::cin >> input;
    if (input == 1)
    {

    }
}

void rectGen::print2DVector(std::vector<std::vector<char>> grid)
{
    std::cout << "\n";

    //Here we create an additional frame around the borders of the canvas
    //for visual purpose at the same time that we print it
    for (unsigned int a = 0; a < grid[0].size() + 2; a++)
    {
        std::cout << "#";
    }
    std::cout << "\n";
    for (unsigned int x = 0; x < grid.size(); x++)
    {
        std::cout << "#";
        for (unsigned int y = 0; y < grid[x].size(); y++)
        {
            std::cout << grid[x][y];
        }
        std::cout << "#\n";
    }
    for (unsigned int b = 0; b < grid[0].size() + 2; b++)
    {
        std::cout << "#";
    }
}

bool rectGen::stuckTest(std::vector<std::vector<char>> grid, unsigned int testPoint[2])
{
    //Tests if the iteration was going to get stuck. With nested ifs to make
    //sure we are not testing inexistent locations and to optimize the test process
    int counter = rectGen::neighborScan(grid, testPoint);

    if (counter >= 8)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool rectGen::isCloseToPrint(std::vector<std::vector<char>> grid, unsigned int testPoint[2])
{
    //Tests if the iteration is going to be next to another previous printed
    //iteration and quantifies how many times its close to it. Nested ifs so
    //we don't check inexistent tiles
    int counter = rectGen::neighborScan(grid, testPoint);

    if (counter > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int rectGen::neighborScan(std::vector<std::vector<char>> grid, unsigned int testPoint[2])
{
    int counter = 0;
    if (testPoint[0] < grid.size() - 1)
    {
        if(testPoint[1] < grid[0].size() - 1)
        {
            if (grid[testPoint[0] + 1][testPoint[1] + 1] == genConfig::printChar ||
                    grid[testPoint[0] + 1][testPoint[1] + 1] == genConfig::startPrintChar ||
                    grid[testPoint[0] + 1][testPoint[1] + 1] == genConfig::teleportPrintChar)
            {
                counter++;
            }
        }

        if(testPoint[1] > 0)
        {
            if (grid[testPoint[0] + 1][testPoint[1] - 1] == genConfig::printChar ||
                    grid[testPoint[0] + 1][testPoint[1] - 1] == genConfig::startPrintChar ||
                    grid[testPoint[0] + 1][testPoint[1] - 1] == genConfig::teleportPrintChar)
            {
                counter++;
            }
        }

        if (grid[testPoint[0] + 1][testPoint[1]] == genConfig::printChar ||
                grid[testPoint[0] + 1][testPoint[1]] == genConfig::startPrintChar ||
                grid[testPoint[0] + 1][testPoint[1]] == genConfig::teleportPrintChar)
        {
            counter++;
        }
    }

    if (testPoint[1] < grid[0].size() - 1)
    {
        if(testPoint[0] > 0)
        {
            if (grid[testPoint[0] - 1][testPoint[1] + 1] == genConfig::printChar ||
                    grid[testPoint[0] - 1][testPoint[1] + 1] == genConfig::startPrintChar ||
                    grid[testPoint[0] - 1][testPoint[1] + 1] == genConfig::teleportPrintChar)
            {
                counter++;
            }
        }

        if (grid[testPoint[0]][testPoint[1] + 1] == genConfig::printChar ||
                grid[testPoint[0]][testPoint[1] + 1] == genConfig::startPrintChar ||
                grid[testPoint[0]][testPoint[1] + 1] == genConfig::teleportPrintChar)
        {
            counter++;
        }
    }

    if (testPoint[1] > 0)
    {
        if(testPoint[0] > 0 && testPoint[1] > 0)
        {
            if (grid[testPoint[0] - 1][testPoint[1] - 1] == genConfig::printChar ||
                    grid[testPoint[0] - 1][testPoint[1] - 1] == genConfig::startPrintChar ||
                    grid[testPoint[0] - 1][testPoint[1] - 1] == genConfig::teleportPrintChar)
            {
                counter++;
            }
        }

        if (grid[testPoint[0]][testPoint[1] - 1] == genConfig::printChar ||
                grid[testPoint[0]][testPoint[1] - 1] == genConfig::startPrintChar ||
                grid[testPoint[0]][testPoint[1] - 1] == genConfig::teleportPrintChar)
        {
            counter++;
        }
    }

    if (testPoint[0] > 0)
    {
        if (grid[testPoint[0] - 1][testPoint[1]] == genConfig::printChar ||
                grid[testPoint[0] - 1][testPoint[1]] == genConfig::startPrintChar ||
                grid[testPoint[0] - 1][testPoint[1]] == genConfig::teleportPrintChar)
        {
            counter++;
        }
    }

    return counter;
}

std::vector<std::vector<char>> rectGen::iteration(std::vector<std::vector<char>> grid,
                            unsigned int startPoint[2], unsigned int nbrOfIt, int seed)
{
    int previousPoint[2], direction, canPrintTrial, errTest = 0;
    std::vector<int> canPrintPercent;
    float progress = 0, percentPrintCondition = 2;

    std::cout << "                                             100%\n";

    //Iterates as many times as the user chose to
    for(unsigned int i = 0; i < nbrOfIt; i++)
    {
        //We store the previous point of iteration so we can come back to it
        //if the current iteration does not follow the rules
        previousPoint[0] = startPoint[0];
        previousPoint[1] = startPoint[1];

        //Simple manipulation of the seed so we have a fresh one each time
        //we start an iteration. Not using rand so we can repeat the pattern
        //if we enter the same seed again
        seed = ((seed>>1) * 11) + 17;

        //We use the seed to set the parameters for the generation
        direction = std::abs(seed % 8);
        canPrintTrial = std::abs(seed % 100);

        //We get the current condition for generation
        canPrintPercent = rectGen::setPrintPercents(grid, startPoint);

        //We try to iterate from the point. Before iterating we
        //test if the conditions allow to go in this direction. If not
        //we skip the iteration.
        switch(direction)
        {
        case 0:
            if (canPrintTrial > canPrintPercent[0])
            {
                startPoint[0] = startPoint[0] - 1;
            }
            break;
        case 1:
            if (canPrintTrial > canPrintPercent[1])
            {
                startPoint[0] = startPoint[0] - 1;
                startPoint[1] = startPoint[1] + 1;
            }
            break;
        case 2:
            if (canPrintTrial > canPrintPercent[2])
            {
                startPoint[1] = startPoint[1] + 1;
            }
            break;
        case 3:
            if (canPrintTrial > canPrintPercent[3])
            {
                startPoint[0] = startPoint[0] + 1;
                startPoint[1] = startPoint[1] + 1;
            }
            break;
        case 4:
            if (canPrintTrial > canPrintPercent[4])
            {
                startPoint[1] = startPoint[1] + 1;
            }
            break;
        case 5:
            if (canPrintTrial > canPrintPercent[5])
            {
                startPoint[0] = startPoint[0] + 1;
                startPoint[1] = startPoint[1] - 1;
            }
            break;
        case 6:
            if (canPrintTrial > canPrintPercent[6])
            {
                startPoint[1] = startPoint[1] - 1;
            }
            break;
        case 7:
            if (canPrintTrial > canPrintPercent[7])
            {
                startPoint[0] = startPoint[0] - 1;
                startPoint[1] = startPoint[1] - 1;
            }
            break;
        }

        //Additional conditions for the iteration to be skipped.
        //basically it prevents it from writing over itself or outside
        //the bounds of the canvas (2D vector), from getting stuck and
        //limits the chance to iterate next to a previous location
        if(startPoint[0] < 0 ||
                startPoint[1] < 0 ||
                startPoint[0] > grid.size() - 1||
                startPoint[1] > grid[0].size() - 1||
                grid[startPoint[0]][startPoint[1]] == genConfig::printChar ||
                grid[startPoint[0]][startPoint[1]] == genConfig::startPrintChar ||
                grid[startPoint[0]][startPoint[1]] == genConfig::teleportPrintChar ||
                rectGen::stuckTest(grid, startPoint) ||
                (rectGen::isCloseToPrint(grid, startPoint)))

        {
            startPoint[0] = previousPoint[0];
            startPoint[1] = previousPoint[1];
            i--;

            //We keep track of the number of times we refuse.
            //It's a way of knowing if we got stuck. If we got stuck,
            //end the generation
            errTest++;

            //If stuck for too long teleports to elsewhere on the canvas
            if (errTest > 100)
            {
                unsigned int teleportPoint[2];
                teleportPoint[0] = seed % grid.size();
                teleportPoint[1] = seed % grid[0].size();
                if(rectGen::stuckTest(grid, teleportPoint) == true || rectGen::isCloseToPrint(grid, teleportPoint) == true)
                {
                    errTest++;
                }
                else
                {
                    startPoint[0] = teleportPoint[0];
                    startPoint[1] = teleportPoint[1];
                }
            }

            if(errTest > 4000)
            {
                std::cout << " Generation stuck, stopping...";
                return grid;
            }
        }

        //if we can generate a the point of iteration, store it and
        //reset the "stuck counter"
        else
        {
            grid[startPoint[0]][startPoint[1]] = genConfig::printChar;
            errTest = 0;
        }

        //Simple pseudo progress bar
        progress = (float)i * 100 / (float)nbrOfIt;
        if(progress == percentPrintCondition)
        {
            std::cout << ".";
            percentPrintCondition = percentPrintCondition + 2;
        }
    }

    //Once we end the generation, we set the final point to finishPrintChar
    //so we can see where the finished
    grid[startPoint[0]][startPoint[1]] = genConfig::finishPrintChar;
    return grid;
}

std::vector<int> rectGen::setPrintPercents(std::vector<std::vector<char>> grid,
        unsigned int testPoint[2])
{
    //Here we calculate the distance between the point and the border in %
    //so we can modify the probability it prints in this direction. It prevents
    //running into the border and sticking there
    std::vector<int> testResult = {0, 0, 0, 0, 0, 0, 0, 0};
    if (testPoint[0] * 100 / grid.size() < 30)
    {
        testResult[7] = 40;
        testResult[0] = 40;
        testResult[1] = 40;
        if (testPoint[0] * 100 / grid.size() < 20)
        {
            testResult[7] = 60;
            testResult[0] = 60;
            testResult[1] = 60;
            if (testPoint[0] * 100 / grid.size() < 10)
            {
                testResult[7] = 80;
                testResult[0] = 80;
                testResult[1] = 80;
            }
        }
    }
    else if (testPoint[0] * 100 / grid.size() > 70)
    {
        testResult[3] = 40;
        testResult[4] = 40;
        testResult[5] = 40;
        if (testPoint[0] * 100 / grid.size() > 80)
        {
            testResult[3] = 60;
            testResult[4] = 60;
            testResult[5] = 60;
            if (testPoint[0] * 100 / grid.size() > 90)
            {
                testResult[3] = 80;
                testResult[4] = 80;
                testResult[5] = 80;
            }
        }
    }

    if (testPoint[1] * 100 / grid[0].size() < 30)
    {
        testResult[7] = 40;
        testResult[6] = 40;
        testResult[5] = 40;
        if (testPoint[1] * 100 / grid[0].size() < 20)
        {
            testResult[7] = 60;
            testResult[6] = 60;
            testResult[5] = 60;
            if (testPoint[1] * 100 / grid[0].size() < 10)
            {
                testResult[7] = 80;
                testResult[6] = 80;
                testResult[5] = 80;
            }
        }
    }
    else if (testPoint[1] * 100 / grid[0].size() > 70)
    {
        testResult[1] = 40;
        testResult[2] = 40;
        testResult[3] = 40;
        if (testPoint[1] * 100 / grid[0].size() > 80)
        {
            testResult[1] = 60;
            testResult[2] = 60;
            testResult[3] = 60;
            if (testPoint[1] * 100 / grid[0].size() > 90)
            {
                testResult[1] = 80;
                testResult[2] = 80;
                testResult[3] = 80;
            }
        }
    }
    return testResult;
}
