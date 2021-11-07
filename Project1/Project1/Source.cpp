#include <iostream>
#include "Graph.h"
#include "IOClass.h"
#include "AntColony.h"

int main()
{
	Graph g("D:\\tests\\input.txt");
	AntColony ants(5, 10, 2, 3, 0.2, 34, g.getAdjMatrix());
	ants.findMinDist(10);
	//IOClass io;
	//io.write("D:\\tests\\output.txt", g.getAdjMatrix(), g.getNumberofVertices());
	return 0;
}