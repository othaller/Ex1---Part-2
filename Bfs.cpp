//
// Created by Roy Shefi on 23/11/2016.
//

#include "Bfs.h"
#include <list>
#include<iostream>

using namespace std;
// Mark all the vertices as not visited
Bfs::Bfs (Map* map) {
  m = map;
  (*m).initializeGridPoints();
}

vector<GridPoint> Bfs::findShortRoute(GridPoint s, GridPoint f) {
  // Create a queue for BFS
  list<GridPoint> queue;
  vector<GridPoint> route;
  vector<GridPoint> routeIfFaild;
  routeIfFaild.push_back(s);


  // Mark the current node as visited and enqueue it
  s.changeState();
  queue.push_back(s);

  // 'i' will be used to get all adjacent vertices of a vertex
  list<int>::iterator i;

  while(!queue.empty()) {
      // Dequeue a vertex from queue and print it
      s = queue.front();

    route.push_back(s);

      queue.pop_front();

      // Get all adjacent vertices of the dequeued vertex s
      // If a adjacent has not been visited, then mark it visited
      // and enqueue it
    temp = (*m).getNeighbors(s);
      for (int i = 0; i < temp.size(); ++i) {
        if (!temp.at(i).getState()) {

          temp.at(i).changeState();
          queue.push_back(temp.at(i));
          if (f.isEqual(temp.at(i))) {
            route.push_back(temp.at(i));
            return route;
          }
        }
      }
    }
  return routeIfFaild;
};
