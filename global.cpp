#include <math.h>
#include <iostream>
#include "global.h"

int GRIDWIDTH = 20;
int GRIDHEIGHT = 20;

int DELAY = 50000;

Cell* Current;

std::vector<Cell*> GRID;
std::stack<Cell*> CELLSTACK;

int index(int i, int j){
    if(i < 0 || j < 0 || i > GRIDWIDTH - 1 || j > GRIDHEIGHT - 1)
        return -1;
    else
        return i + j * GRIDWIDTH;
}
