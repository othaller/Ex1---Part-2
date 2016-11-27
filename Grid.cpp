//
// Created by Oded Thaller on 22/11/2016.
//
#include "Map.h"
#include "Grid.h"
#include "Bfs.h"
using namespace std;

Grid::Grid(int x, int y) {

    sizeX = x;
    sizeY = y;

    map.resize(x);
    for (int i = 0; i < x; ++i) {
        map[i].resize(y);
    }

    for (int i = 0; i < x; ++i) {

        for (int j = 0; j < y; ++j) {

            map[j][i] = new GridPoint(j, x - 1 - i);
        }
    }
}

  void Grid::printMap() {

    for (int i = 0; i < map.size(); ++i) {

        for (int j = 0; j < map[i].size(); ++j) {

          (*map[j][i]).print();
        }

        cout << "\n";
    }
}

  vector<GridPoint*> *Grid::getNeighbors(GridPoint p) {

    vector <GridPoint*>* vec = new vector <GridPoint*>;

    if (p.getX() > 0) {
      (*vec).push_back(map[p.getX() - 1][ sizeX - p.getY() -1]);
    }
    if (p.getY() < sizeY - 1) {
      (*vec).push_back(map[p.getX()][sizeX -p.getY() - 1 -1]);
    }
    if (p.getX() < sizeX - 1) {
      (*vec).push_back(map[p.getX() + 1][sizeX - p.getY() -1]);
    }
    if (p.getY() > 0) {
      (*vec).push_back(map[p.getX()][sizeX - p.getY() + 1 -1]);
    }

    return vec;
}

// Making evrything false.
void Grid::initializeGridPoints () {
  for (int i = 0; i < map.size(); ++i) {

    for (int j = 0; j < map[i].size(); ++j) {

      (*map[j][i]).initialize();
    }
  }
}
// Copys the grid.
Map* Grid::copy() {
  return new Grid(this->sizeX,this->sizeY);
}


Grid::~Grid() {}
int main(int argc,char *argv[]) {
    Map *m = new Grid(3,3);
    vector<GridPoint> gp;
  // start point/
  int x1;
  int y1;
  // End point.
  int x2;
  int y2;
  // Map size
  int xAx;
  int yAx;
  // NEED TO ADD INPUT FROM USER.

    Bfs b(m);
    // Will help for later.
    // vector<GridPoint>* gp = new vector<GridPoint>;
    b.findShortRoute(new GridPoint(0,0),new GridPoint(2,2),&gp);



}





