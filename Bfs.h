//
// Created by Roy Shefi on 23/11/2016.
//

#ifndef PART_2_BFS_H
#define PART_2_BFS_H
#include "Map.h"
#include <iostream>
#include <vector>
#include "Point.h"
#include "GridPoint.h"
using namespace std;
class Bfs {
  // A copy of the map given to the algorithm.
 private:Map *m;
// Holds the BFS routes crated.
 private:vector<vector<GridPoint*>*> *rouets;

 public:
  // Constructor.
  Bfs(Map *map);
  // Finds the shortest routes between two Grid points in the map.
  void findShortRoute (GridPoint* s, GridPoint  *f, vector<GridPoint>* gp);
};

#endif //PART_2_BFS_H
