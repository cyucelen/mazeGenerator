#include "cell.h"
#include <stdlib.h>
#include <iostream>

Cell::Cell(int row, int column) {
  this->row = row;
  this->column = column;
  visited = false;
  setWalls();
}

void Cell::setWalls() {
  for (int i = 0; i < 4; i++) walls[i] = true;
}

void Cell::setVisited(bool b) { visited = b; }
bool Cell::isVisited() { return visited; }

int Cell::getRow() { return row; }
int Cell::getColumn() { return column; }

void Cell::removeWalls(Cell &next) {
  int x = column - next.column;
  int y = row - next.row;

  if (x == 1) {
    walls[LEFT] = false;
    next.walls[RIGHT] = false;
  } else if (x == -1) {
    walls[RIGHT] = false;
    next.walls[LEFT] = false;
  } else if (y == 1) {
    walls[TOP] = false;
    next.walls[BOTTOM] = false;
  } else if (y == -1) {
    walls[BOTTOM] = false;
    next.walls[TOP] = false;
  }
}

void Cell::show(WINDOW *win) {
  if (walls[0]) {
    wmove(win, row, (column + 2) + (column));
    whline(win, '_', 1);
  }

  if (walls[1]) {
    wmove(win, row + 1, (column + 3) + (column));
    wvline(win, '|', 1);
  }

  if (walls[2]) {
    wmove(win, row + 1, (column + 2) + (column));
    whline(win, '_', 1);
  }

  if (walls[3]) {
    wmove(win, row + 1, (column + 1) + (column));
    wvline(win, '|', 1);
  }
}

void Cell::print() {
  std::cout << "row : " << row << " | ";
  std::cout << "column : " << column << std::endl;
}