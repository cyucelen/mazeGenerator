#pragma once
#include <vector>
#include "Cell.h"
#include "ncurses.h"
#include <stack>

extern int GRIDWIDTH;
extern int GRIDHEIGHT;

extern std::vector<Cell*> GRID;
extern Cell* Current;
extern WINDOW *win;

extern int index(int,int);

extern std::stack<Cell*> CELLSTACK;