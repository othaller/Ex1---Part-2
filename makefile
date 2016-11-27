a.out: Grid.o Bfs.o GridPoint.o Map.h Point.o
	g++ Grid.o Bfs.o GridPoint.o Map.h Point.o

Grid.o: Grid.cpp Grid.h
	g++ -c Grid.cpp

Bfs.o: Bfs.cpp Bfs.h
	g++ -c Bfs.cpp

GridPoint.o: GridPoint.cpp GridPoint.h
	g++ -c GridPoint.cpp

Point.o: Point.cpp Point.h
	g++ -c Point.cpp