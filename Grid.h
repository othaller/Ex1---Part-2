//
// Created by Oded Thaller on 22/11/2016.
//

#ifndef PART_2_GRID_H
#define PART_2_GRID_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "Map.h"
#include"GridPoint.h"

using namespace std;

class Grid: public Map {

private:
    vector <vector<GridPoint>> map;
    int sizeX;
    int sizeY;

public:
    // Creates a 2D grid of points of given size
    Grid(int x, int y);

    // Prints the grid where point (0,0) is on the bottom left
    void printMap();

    // takes a point, returns a vector of its up to 4 neighbors in clockwise order, from 9 o'clock
    vector<GridPoint> getNeighbors(GridPoint p);
    void initializeGridPoints ();
  ~Grid();
};

#endif //PART_2_GRID_H