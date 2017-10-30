#pragma once
#include <vector>
#include "Cell.h"
#include "ncurses.h"
#include <stack>

extern int GRIDWIDTH;
extern int GRIDHEIGHT;

extern int DELAY;

extern std::vector<Cell*> GRID;
extern Cell* Current;
extern WINDOW *win;

extern std::stack<Cell*> CELLSTACK;

extern int index(int,int);
extern void getConfig();