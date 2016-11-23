//
// Created by Roy Shefi on 23/11/2016.
//

#include <iostream>
#include <vector>
#include "Point.h"
#include "Map.h"
#include "GridPoint.h"
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
