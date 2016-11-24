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

void Bfs::findShortRoute(GridPoint s, GridPoint f,vector<GridPoint> *gp) {
  // Create a queue for BFS
  list<GridPoint> queue;
  vector<GridPoint> route;
  vector<GridPoint> routeIfFaild;
  routeIfFaild.push_back(s);
  GridPoint start = s;
  GridPoint t = s;
  vector<GridPoint> queue2;
  int a =0;



  // Mark the current node as visited and enqueue it
  (s).changeState();
  queue.push_back(s);



  cout << "BFS finds all paths to target: \n";
  while(!queue.empty()) {
    // Dequeue a vertex from queue and print it
    s = queue.front();
    queue.pop_front();


    // Get all adjacent vertices of the dequeued vertex s
    // If a adjacent has not been visited, then mark it visited
    // and enqueue it

    temp = ((*m).getNeighbors(s));
    cout << "\n";
    cout << "Mark: \n";
    cout << "\n";



    for (int i = 0; i < (*temp).size(); ++i) {
      if (!(*temp).at(i).getState()) {
        (*temp).at(i).changeState();
        (*temp).at(i).assignFather(&s);

        cout << "Son: ";
        (*temp).at(i).print();
        cout << " ";
        cout << "Father: ";
        s.print();
        cout << "\n";

        queue.push_back((*temp).at(i));
      }

      // Problen is in here.
      if (f.isEqual((*temp).at(i))) {
        f = (*temp).at(i);
        a =1;
        break;
      }
    }
    if (a == 1) { break;}
  }
          // Starting point test.
            cout << "\n";
            cout << "\n";
            cout << "start: ";
          s.print();
          cout<<"\n";
          cout << "end: ";
          // finishing test.
          f.print();
          cout<<"\n";

          // only the last one works :(
          cout << "Father of end: ";
          f.fa->print();
          cout<<"\n";
  //  This is the problem!!!!!!!
  GridPoint *gre = f.fa;
  // this shold be next in the path! but it prints (4,5) (itself).
  gre->printFather();

          // ((f.fa).fa)->print();
          //GridPoint* tr;
          queue2.push_back(f);
          /**
          while (1) {
            if (&f != 0) {
              f = *f.fa;
              queue2.push_back(f);

            } else break;
          }
          */
          //gp = &queue2;
         // f.print();
          //f.printFather();
              //cout<<"\n";
          //s = t;
          //s.print();
          //cout<<"\n";

          //s.getRouteToStart(&(temp.at(i)),gp);
          //cout << "Route size:"<<route.size()<< endl;
            return ;


};
