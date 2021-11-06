#pragma once
#include<string>

class Graph
{
	int numberOfVertices;
	int** adjMatrix;
public:
	Graph() {};
	Graph(std::string name);
	Graph(int n, int** matrix);
	int getNumberofVertices();
	int** getAdjMatrix();
};

