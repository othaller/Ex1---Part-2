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

  // Creates the map.
    map.resize(x);
    for (int i = 0; i < x; ++i) {
        map[i].resize(y);
    }

    for (int i = 0; i < x; ++i) {

        for (int j = 0; j < y; ++j) {

            map[i][j] = new GridPoint(i, j);

        }
    }
}
  void Grid::printMap() {

    for (int i = sizeY - 1; i >= 0; --i) {

        for (int j = 0; j < sizeX ; ++j) {

          (*map[j][i]).print();
        }

        cout << "\n";
    }
}

  vector<GridPoint*> *Grid::getNeighbors(GridPoint p) {

    vector <GridPoint*> *vec = new vector <GridPoint*>;

      // Order of the clock - Right.
      if (p.getX() > 0) {
          (*vec).push_back(map[p.getX() - 1][p.getY()]);
      }
      // Up.
      if (p.getY() > 0) {
          (*vec).push_back(map[p.getX()][p.getY() - 1]);
      }
      // Left.
      if (p.getY() < sizeY - 1) {
          (*vec).push_back(map[p.getX()][p.getY() + 1]);
      }
      // Down.
      if (p.getX() < sizeX - 1) {
        (*vec).push_back(map[p.getX() + 1][p.getY()]);
      }


    return vec;
}

// Making everything false - NOT visited.
void Grid::initializeGridPoints () {
  for (int i = 0; i < map.size(); ++i) {

    for (int j = 0; j < map[i].size(); ++j) {

      (*map[i][j]).initialize();
    }
  }
}

// Copys the grid.
Map* Grid::copy() {
  return new Grid(this->sizeX,this->sizeY);
}
// De- constructor.
Grid::~Grid() {}

int main() {

    int sizeX, sizeY, startX, startY, endX, endY;
    char underScore[3];
    char comma[2];
    // Get user input.
    cin >> sizeX >> underScore[0] >> sizeY >> comma[0];
    cin >> startX >> underScore[1] >> startY >> comma[1];
    cin >> endX >> underScore[2] >> endY;

    Map *m = new Grid(sizeX, sizeY);
    // Will be useful in the futere.
    vector<GridPoint> gp;
    Bfs b(m);
    // Find the route.
    b.findShortRoute(new GridPoint(startX,startY),new GridPoint(endX,endY),&gp);


}