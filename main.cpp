#include <iostream>
#include <vector>
#include "Cell.h"
#include "global.h"
#include "unistd.h"
#include <stdlib.h>
#include <time.h>

WINDOW *win;

void setup() {

    std::cout << "Setup Started.." << std::endl;
    initscr();
    cbreak();
    win = newwin(GRIDHEIGHT + 1, GRIDWIDTH * 2 + 10, 0, 0);
    for(int j = 0; j < GRIDHEIGHT; j++){
        for(int i = 0; i < GRIDWIDTH; i++){
            Cell *temp = new Cell(i, j);
            GRID.push_back(temp);
        }
    }
    Current = GRID[0];
}

void draw() {
    std::cout << "Draw Started.." << std::endl;
    while(true){
        Current->setVisited(true);
        Cell *next = Current -> checkNeighbors();
        if(next != NULL){
            next->setVisited(true);
            CELLSTACK.push(Current);
            Current->removeWalls(*next);
            Current = next;
        }else if(CELLSTACK.size() > 0){
            Current = CELLSTACK.top();
            CELLSTACK.pop();
        }else if(CELLSTACK.size() == 0){
            break;
        }
        usleep(DELAY);
        werase(win);
        for(int i = 0; i < GRID.size(); i++){
            GRID[i]->show();
        }
    }
}

int main() {
    std::cout << "Main started.." << std::endl;
    getConfig();
    srand(time(NULL));
    setup();
    draw();
    getch();
    endwin();
    return 0;
}