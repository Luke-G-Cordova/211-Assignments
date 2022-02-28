// video.cpp
// Cordova, Luke

#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include "shape.h"
#include "grid.h"
using namespace std;
class Square: public Shape{
    public:
        Square(int x, int y, int size):Shape(x, y)
        {m_size = size;}
        void draw(Grid &grid);
    private:
        int m_size;
};
#endif

void Square::draw(Grid &grid){
    for(int x = 0;x<m_size;x++){
        grid.set(m_x+x, m_y, '*');
        grid.set(m_x+x, m_y+m_size-1, '*');
    }
    for(int y = 1;y<m_size-1;y++){
        grid.set(m_x, m_y+y, '*');
        grid.set(m_x+m_size-1, m_y+y, '*');
    }
}