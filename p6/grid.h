// video.cpp
// Cordova, Luke

#ifndef GRID_H
#define GRID_H
#include <iostream>
// #include "shape.h"
using namespace std;

class Grid{
    public:
        Grid();
        void set(int x, int y, char c);
        void print();

    private:
        const int HEIGHT = 24;
        const int WIDTH = 60;
        char m_grid[24][60];
};


#endif