#include "Graph.h"
#include <math.h>
#include <ctime>
#include "IOClass.h"

Graph::Graph(std::string name)
{
	IOClass io;
	adjMatrix = io.read(name, numberOfVertices);
}

Graph::Graph(int n, int** matrix)
{
	numberOfVertices = n;
	adjMatrix = matrix;
}

int Graph::getNumberofVertices()
{
	return numberOfVertices;
}

int** Graph::getAdjMatrix()
{
	return adjMatrix;
}