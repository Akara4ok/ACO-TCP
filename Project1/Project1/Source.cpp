#include <iostream>
#include "Graph.h"
#include "IOClass.h"
#include "AntColony.h"

int main()
{
	Graph g("D:\\tests\\input.txt");
	IOClass io;
	io.write("D:\\tests\\output.txt", g.getAdjMatrix(), g.getNumberofVertices());
	return 0;
}