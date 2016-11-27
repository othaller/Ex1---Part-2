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
  /**
   *
   */
    int sizeX;
  /**
   *
   */
    int sizeY;

public:
  /**
   *
   */
  vector <vector<GridPoint*>> map;

    // Creates a 2D grid of points of given size
  /**
   *
   * @param x
   * @param y
   * @return
   */
    Grid(int x, int y);

    // Prints the grid where point (0,0) is on the bottom left
  /**
   *
   */
    void printMap();

    // takes a point, returns a vector of its up to 4 neighbors in clockwise order, from 9 o'clock
  /**
   *
   * @param p
   * @return
   */
    vector<GridPoint*>* getNeighbors(GridPoint p);
  /**
   *
   */
    void initializeGridPoints ();
  /**
   *  Copy function.
   * @return - a copy of itself.
   */
  Map* copy ();
  /**
   * Dconstructor.
   */
  ~Grid();
};

#endif //PART_2_GRID_H
