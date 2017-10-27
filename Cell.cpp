#include <iostream>
#include <stdlib.h>
#include "global.h"
#include "Cell.h"

Cell::Cell(int i, int j) {
    this -> i = i;
    this -> j = j;
    visited = false;
    setWalls();
}

void Cell::setWalls() {
    for(int i = 0; i < 4; i++)
        walls[i] = true;
}

void Cell::setVisited(bool b) {
    visited = b;
}

void Cell::print() {
    std::cout << "i : " << i  << " | ";
    std::cout << "j : " << j << std::endl;
}

void Cell::removeWalls(Cell &next) {
    int x = i - next.geti();
    int y = j - next.getj();

    if(x == 1){
        walls[3] = false;
        next.setRightWall(false);
    }else if(x == -1){
        walls[1] = false;
        next.setLeftWall(false);
    }else if(y == 1){
        walls[0] = false;
        next.setBottomWall(false);
    }else if(y == -1){
        walls[2] = false;
        next.setTopWall(false);
    }
}

void Cell::setTopWall(bool b) {
    walls[0] = b;
}

void Cell::setRightWall(bool b) {
    walls[1] = b;
}

void Cell::setBottomWall(bool b) {
    walls[2] = b;
}

void Cell::setLeftWall(bool b) {
    walls[3] = b;
}

Cell* Cell::checkNeighbors() {
    std::vector<Cell*> neighbors;

    int topIndex    = index(i    , j - 1);
    int rightIndex  = index(i + 1, j    );
    int bottomIndex = index(i    , j + 1);
    int leftIndex   = index(i - 1, j    );

    //std::cout<< topIndex << " " << rightIndex << " " << bottomIndex << " " << leftIndex;

    if(topIndex != -1){
        Cell *top = GRID[topIndex];
        if(!top->visited){
            neighbors.push_back(top);
        }
    }

    if(rightIndex != -1){
        Cell *right = GRID[rightIndex];
        if(!right->visited){
            neighbors.push_back(right);
        }
    }

    if(bottomIndex != -1){
        Cell *bottom = GRID[bottomIndex];
        if(!bottom->visited){
            neighbors.push_back(bottom);
        }
    }

    if(leftIndex != -1){
        Cell *left = GRID[leftIndex];
        if(!left->visited){
            neighbors.push_back(left);
        }
    }

    Cell *c = NULL;

    if(neighbors.size() > 0){
        int r = (rand() % neighbors.size());
        return neighbors.at(r);
    }else{
        return c;
    }

}

void Cell::show() {

    if(walls[0]){
        wmove(win, j , (i + 2) + (i));
        whline(win, '_', 1);
    }
    if(walls[1]){
        wmove(win, j + 1, (i + 3) + (i));
        wvline(win, '|', 1);
    }
    if(walls[2]){
        wmove(win, j + 1, (i + 2) + (i));
        whline(win, '_', 1);
    }
    if(walls[3]){
        wmove(win, j + 1, (i + 1) + (i));
        wvline(win, '|', 1);
    }
    // i + 2 + (i) next
    // j + 1 next
    wmove(win, (Current->j) + 1, ((Current ->i) + 2) + (Current->i));
    refresh();
    wrefresh(win);

 }

int Cell::geti() {
    return i;
}

int Cell::getj(){
    return j;
};

bool Cell::isVisited() {
    return visited;
}

