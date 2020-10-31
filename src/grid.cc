#include "grid.h"
#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <thread>
#include "cell.h"

Grid::Grid(int width, int height, int renderDelay) {
  this->width = width;
  this->height = height;
  this->renderDelay = renderDelay;
  window = newwin(height * 2 + 10, width * 2 + 10, 0, 0);
  createCells();
  current = &cells[0];
}

void Grid::createCells() {
  for (int row = 0; row < height; row++) {
    for (int column = 0; column < width; column++) {
      cells.push_back(Cell(row, column));
    }
  }
}

void Grid::generateMaze() {
  while (true) {
    current->setVisited(true);
    Cell *next = findNextCell();

    if (next != NULL) {
      next->setVisited(true);
      backtrace.push(current);
      current->removeWalls(*next);
      current = next;
    } else if (backtrace.size() > 0) {
      current = backtrace.top();
      backtrace.pop();
    } else if (backtrace.size() == 0) {
      break;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(renderDelay));
    werase(window);
    render();
  }
}

void Grid::render() {
  for (Cell c : cells) {
    c.show(window);
    wmove(window, (current->getRow()) + 1,
          ((current->getColumn()) + 2) + (current->getColumn()));
  }
  refresh();
  wrefresh(window);
}

Cell *Grid::findNextCell() {
  std::vector<Cell *> availableNeighbors = getAvailableNeighbors();
  if (availableNeighbors.size() > 0) {
    return availableNeighbors.at(rand() % availableNeighbors.size());
  }

  return NULL;
}

std::vector<Cell *> Grid::getAvailableNeighbors() {
  std::vector<Cell *> neighbors;

  int currentRow = current->getRow();
  int currentColumn = current->getColumn();

  int neighborIndexes[4] = {
      calculateIndex(currentRow - 1, currentColumn),
      calculateIndex(currentRow, currentColumn + 1),
      calculateIndex(currentRow + 1, currentColumn),
      calculateIndex(currentRow, currentColumn - 1),
  };

  for (int i : neighborIndexes) {
    if (i != -1 && !cells[i].isVisited()) {
      neighbors.push_back(&cells[i]);
    }
  }

  return neighbors;
}

int Grid::calculateIndex(int row, int column) {
  if (row < 0 || column < 0 || column > width - 1 || row > height - 1)
    return -1;
  else
    return column + row * width;
}
