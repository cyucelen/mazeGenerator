#ifndef GRID_H
#define GRID_H

#include <stack>
#include <vector>
#include "cell.h"
#include "ncurses.h"

class Grid {
 private:
  WINDOW *window;
  int width;
  int height;
  int renderDelay;

  std::vector<Cell> cells;
  std::stack<Cell *> backtrace;
  Cell *current;

  void createCells();
  int calculateIndex(int i, int j);
  std::vector<Cell *> getAvailableNeighbors();
  Cell *findNextCell();
  void render();

 public:
  Grid(int width, int height, int renderDelay);
  void generateMaze();
};

#endif