#ifndef RECTGEN_H
#define RECTGEN_H
#include <vector>
#include "genConfig.h"
#include "menu.h"

class rectGen
{
public:
    rectGen();
    void initialize(unsigned int avoidRadius);
    static int height,
               length,
               seed;
    static unsigned int nbrOfIt;
private:
    void print2DVector(std::vector<std::vector<char>> grid);

    bool stuckTest(std::vector<std::vector<char>> grid, unsigned int testPoint[2]);
    bool isCloseToPrint(std::vector<std::vector<char>> grid, unsigned int testPoint[2]);
    int neighborScan(std::vector<std::vector<char>> grid, unsigned int testPoint[2]);
    std::vector<std::vector<char>> iteration(std::vector<std::vector<char>> grid,
                                unsigned int startPoint[2]);
    std::vector<unsigned int> setPrintPercents(std::vector<std::vector<char>> grid,
                                      unsigned int testPoint[2]);

    menu menu;

};

#endif // RECTGEN_H
