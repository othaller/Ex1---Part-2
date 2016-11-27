//
// Created by Roy Shefi on 23/11/2016.
//
#ifndef PART_2_MAP_H
#define PART_2_MAP_H
#include "GridPoint.h"
#include <iostream>
#include <vector>

using namespace std;
//interface
class Map {

 public:
  /**
   * Returns the neighbors of the GridPoint in clock order.
   * @return The neighbors of the GridPoint in clock order.
   */
  virtual vector<GridPoint*> *getNeighbors(GridPoint) =0;
  /**
   * Prints the map. Will be useful in the futere.
   */
  virtual void printMap() =0;
  /**
   * Initializes the points on the map to false - not visited.
   */
  virtual void initializeGridPoints() =0;
  /**
   * Creates a copy of the map.
   * @return a copy of the map.
   */
  virtual Map* copy() =0;
  /**
   * A de-constructer.
   */
  virtual ~Map() {};
};
#endif //PART_2_MAP_H
