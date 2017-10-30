#pragma once

class Cell {
private:
    int i, j;
    bool walls[4];
    bool visited;

public:
    Cell(int i, int j);

    Cell* checkNeighbors();
    void print();
    void show();
    void removeWalls(Cell&);

    void setWalls();
    void setVisited(bool);
};