//
// Created by Roy Shefi on 23/11/2016.
//

#include <iostream>
#include "Point.h"
#include "Map.h"

using namespace std;

GridPoint::GridPoint(int a, int b) {
  visited = false;
  this->x = a;
  this->y = b;
}

GridPoint::GridPoint() {
  this->x = 0;
  this->y = 0;

}

bool GridPoint::isEqual(GridPoint a) {
  return a.getX() == this->getX() && a.getY() == this->getY();
}

void GridPoint::getRouteToStart(GridPoint* g,vector<GridPoint>* an ) {

  (*an).push_back(*g);
  if ((g) == 0) {
    return;
  }

  getRouteToStart((*g).fa,an);
}
