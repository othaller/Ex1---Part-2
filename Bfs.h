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
 private:Map *m;
 private:vector<GridPoint>* temp;
 public:
  Bfs(Map *map);
  void findShortRoute (GridPoint s, GridPoint  f, vector<GridPoint>* gp);
};

#endif //PART_2_BFS_H
