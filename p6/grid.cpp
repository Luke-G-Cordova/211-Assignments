// video.cpp
// Cordova, Luke
#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid(){
    for(int y = 0;y<HEIGHT;y++){
        for(int x = 0;x<WIDTH;x++){
            m_grid[y][x] = ' ';
        }
    }
}
void Grid::set(int x, int y, char c){
    if(y < HEIGHT && x < WIDTH){
        m_grid[y][x] = c;
    }
}
void Grid::print(){
    for(int y = 0;y<HEIGHT;y++){
        for(int x = 0;x<WIDTH;x++){
            cout<<m_grid[y][x];
        }
        cout<<endl;
    }
}