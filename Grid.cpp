//
// Created by Oded Thaller on 22/11/2016.
//

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

            map[j][i] = Point(j, x - 1 - i);
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

vector<Point> Grid::getNeighbors(Point p) {

    vector <Point> vec;

    if (p.getX() > 0) {
        vec.push_back(Point(p.getX() - 1, p.getY()));
    }
    if (p.getY() < sizeY - 1) {
        vec.push_back(Point(p.getX(), p.getY() + 1));
    }
    if (p.getX() < sizeX - 1) {
        vec.push_back(Point(p.getX() + 1, p.getY()));
    }
    if (p.getY() > 0) {
        vec.push_back(Point(p.getX(), p.getY() - 1));
    }

    return vec;
}