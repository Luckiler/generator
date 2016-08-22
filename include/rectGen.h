#ifndef RECTGEN_H
#define RECTGEN_H
#include <vector>

class rectGen
{
    public:
        rectGen(int seed, int height, int length, int nbrOfIt);

    private:
        void print2DVector(std::vector<std::vector<char>> grid);
        bool stuckTest(std::vector<std::vector<char>> grid, int testPoint[2]);
        bool isCloseToPrint(std::vector<std::vector<char>> grid, int testPoint[2]);
        int neighborScan(std::vector<std::vector<char>> grid, int testPoint[2]);
        std::vector<std::vector<char>> iteration(std::vector<std::vector<char>> grid,
                                                 int startPoint[2], int nbrOfIt, int seed);
        std::vector<int> setPrintPercents(std::vector<std::vector<char>> grid,
                                          int testPoint[2]);

};

#endif // RECTGEN_H
