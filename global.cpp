#include <math.h>
#include <iostream>
#include "global.h"

int GRIDWIDTH = 20;
int GRIDHEIGHT = 20;

Cell* Current;

int index(int i, int j){
    if(i < 0 || j < 0 || i > GRIDHEIGHT -1 || j > GRIDWIDTH - 1)
        return -1;
    else
        return i + (j * GRIDHEIGHT);
}

std::vector<Cell*> GRID;
std::stack<Cell*> CELLSTACK;