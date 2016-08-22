#include <iostream>
#include "generator.h"

using namespace std;

int main()
{
    cout << "Started program" << endl;
    int seed, height, length, nbrOfIt;
    char input;
    while (true)
    {
        cin >> seed >> height >> length >> nbrOfIt;
        rectGen rect(seed, height, length, nbrOfIt);
        cout << "\n\n\nrestart ?\t";
        cin >> input;
        if (input != 'y')
        {
            return 0;
        }
    }

}
