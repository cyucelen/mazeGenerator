#include <math.h>
#include <fstream>
#include <iostream>
#include "global.h"
#include <cstdlib>

int GRIDWIDTH = 20;
int GRIDHEIGHT = 20;

int DELAY = 50000;

void getConfig() {
    std::ifstream conf("../config.txt");

    if(!conf) {
        std::cerr << "Config file could not found!" << std::endl;
        std::cout << "Maze Generator will use default values!" << std::endl;
    }else {
        while(conf){
            std::string strInput;
            getline(conf, strInput);
            int signPos, value;
            std::cout << "!!!" << strInput << std::endl;
            if(strInput.find("WIDTH") != std::string::npos){
                signPos = (int) strInput.find("=");
                GRIDWIDTH = stoi(strInput.substr(signPos + 1));
            }else if(strInput.find("HEIGHT") != std::string::npos){
                signPos = (int) strInput.find("=");
                GRIDHEIGHT =  stoi(strInput.substr(signPos + 1));
            }else if(strInput.find("DELAY") != std::string::npos){
                signPos = (int) strInput.find("=");
                DELAY = stoi(strInput.substr(signPos + 1));
            }
        }
    }


}

Cell* Current;

std::vector<Cell*> GRID;
std::stack<Cell*> CELLSTACK;

int index(int i, int j){
    if(i < 0 || j < 0 || i > GRIDWIDTH - 1 || j > GRIDHEIGHT - 1)
        return -1;
    else
        return i + j * GRIDWIDTH;
}
