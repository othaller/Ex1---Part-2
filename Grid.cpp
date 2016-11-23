//
// Created by Oded Thaller on 22/11/2016.
//
#include "Map.h"
#include "GridPoint.h"
#include "Grid.h"
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

            map[j][i] = GridPoint(j, x - 1 - i);
        }
    }
}

  void Grid::printMap() {

    for (int i = 0; i < map.size(); ++i) {

        for (int j = 0; j < map[i].size(); ++j) {

            map[j][i].print();
        }

        cout << "\n";
    }
}

  vector<GridPoint> Grid::getNeighbors(GridPoint p) {

    vector <GridPoint> vec;

    if (p.getX() > 0) {
        vec.push_back(GridPoint(p.getX() - 1, p.getY()));
    }
    if (p.getY() < sizeY - 1) {
        vec.push_back(GridPoint(p.getX(), p.getY() + 1));
    }
    if (p.getX() < sizeX - 1) {
        vec.push_back(GridPoint(p.getX() + 1, p.getY()));
    }
    if (p.getY() > 0) {
        vec.push_back(GridPoint(p.getX(), p.getY() - 1));
    }

    return vec;
}

int main(int argc,char *argv[]) {
    Map *m = new Grid(3,3);
    m->printMap();
  }

