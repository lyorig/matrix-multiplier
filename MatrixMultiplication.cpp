#define DEBUG
//#define HAMMER_TIME

#include <algorithm>
#include <iostream>
#include <vector>
#include "Functions.h"

using namespace std;

int main() {
    
    const lyoVec2D identityMatrix = {{1, 0, 0},
                                     {0, 1, 0},
                                     {0, 0, 1}};

    const lyoVec2D TestMatrix1 = {{30},
                                  {45},
                                  {60}};

    const lyoVec2D TestMatrix2 = {{40, 20},
                                  {30, 50},
                                  {10, 15}};
    
    identityMatrix * TestMatrix1;

    printf("Press enter to advance to the next calculation.\n");
    cin.get();
    
    identityMatrix * TestMatrix2;

    cin.get();
    return 0;
}