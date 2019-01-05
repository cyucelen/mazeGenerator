#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "INIReader.h"
#include "cell.h"
#include "grid.h"

int main() {
  INIReader reader("config.ini");
  int width = reader.GetInteger("grid", "width", 10);
  int height = reader.GetInteger("grid", "height", 10);
  int delay = reader.GetInteger("grid", "delay", 10);

  srand(time(NULL));
  initscr();
  cbreak();
  Grid grid = Grid(width, height, delay);
  grid.generateMaze();
  getch();
  endwin();
  return 0;
}