#ifndef CELL_H
#define CELL_H

#include "ncurses.h"

class Cell {
 private:
  int row, column;
  bool walls[4];
  bool visited;
  enum direction { TOP, RIGHT, BOTTOM, LEFT };

 public:
  Cell(int i, int j);

  Cell *checkNeighbors();
  void print();
  void show(WINDOW *);
  void removeWalls(Cell &);

  void setWalls();
  void setVisited(bool);
  bool isVisited();

  int getRow();
  int getColumn();
};

#endif