//
// Created by Roy Shefi on 23/11/2016.
//

#include "Bfs.h"
#include <list>
#include<iostream>
#include <vector>


using namespace std;
// Mark all the vertices as not visited
Bfs::Bfs (Map* map) {
  m = map;
  (*m).initializeGridPoints();
}

void Bfs::findShortRoute(GridPoint* s, GridPoint *f,vector<GridPoint> *gp) {
  // Create a queue for BFS
  list<GridPoint*> queue;
  vector<GridPoint> route;
  vector<GridPoint> routeIfFaild;
  routeIfFaild.push_back(*s);
  GridPoint *start = s;
  //GridPoint t = s
  vector<GridPoint> queue2;
  int a =0;
int e =1;
  int b =0;


  // Mark the current node as visited and enqueue it
  (*s).changeState();
  int x =(*start).x;
  queue.push_back(start);

temp = new vector<vector<GridPoint>*>;
    temp->resize(100000);

  (*temp).at(0) =  new vector<GridPoint>;
  ((*temp).at(0))->push_back(*s);
  ((*temp).at(0))->at(0).changeState();


  cout << "BFS finds all paths to target: \n";
  while(!queue.empty()) {
    (*temp).at(e) =  new vector<GridPoint>;
    // Dequeue a vertex from queue and print it
    s = queue.front();
    queue.pop_front();
if (e != 1) {
  for (int i = 0; i < (*(temp->at(e - 1))).size(); ++i) {
    if ((*s).isEqual((*(temp->at(e - 1))).at(i))) {
      b = i;
      break;
    }
  }
}

    // Get all adjacent vertices of the dequeued vertex s
    // If a adjacent has not been visited, then mark it visited
    // and enqueue it

    temp->at(e)= ((*m).getNeighbors(*s));

    cout << "\n";
    cout << "Mark: \n";
    cout << "\n";

    for (int i = 0; i < (*(temp->at(e))).size(); ++i) {
      // Null pointer
      if (!(((*(temp->at(e))).at(i)).getState())) {
        ((*(temp->at(e))).at(i)).changeState();
        ((*(temp->at(e))).at(i)).assignFather(&((*(temp->at(e - 1))).at(b)));
        cout << "Son: ";
        ((*(temp->at(e))).at(i)).print();
        cout << " ";
        cout << "Father: ";
        ((*(temp->at(e))).at(i)).printFather();
        cout << "\n";
        queue.push_back(&((*(temp->at(e))).at(i)));
      }

      // Problen is in here.
      if ((*f).isEqual(((*(temp->at(e))).at(i)))) {
        *f = ((*(temp->at(e))).at(i));
        a =1;
        break;
      }
    }
    ++e;
    if (a == 1) { break;}
  }
          // Starting point test.
            cout << "\n";
            cout << "\n";
            cout << "start: ";
  (*s).print();
          cout<<"\n";
          cout << "end: ";
          // finishing test.
  (*f).print();
          cout<<"\n";

          // only the last one works :(
          cout << "Father of end: ";
  (*f).fa->print();
          cout<<"\n";
  //GridPoint *gre = ;
  // this shold be next in the path! but it prints (4,5) (itself).
  //cout<<"this is good if it ISNT '(4,5)': ";
  //(*gre).printFather();
for (int i = 0; i<e-1; ++i) {
  for (int j = 0; j < ((*(temp->at(e -1)))).size(); ++j) {
    cout << "temp at: " <<"i = "<< i << " ,j = "<<j;

    (*(*temp).at(i)).at(j).print();
    cout << " Father: ";
    (*(*temp).at(i)).at(j).printFather();
    cout << "\n";

  }
}

  // ((f.fa).fa)->print();
  //GridPoint* tr;
  queue2.push_back(*f);
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
  return;

};
