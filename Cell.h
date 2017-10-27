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

    int geti();
    int getj();
    bool isVisited();
    void setWalls();
    void setVisited(bool);
    void setTopWall(bool);
    void setRightWall(bool);
    void setBottomWall(bool);
    void setLeftWall(bool);
};