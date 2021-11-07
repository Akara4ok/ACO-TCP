#pragma once
class AntColony
{
public:
	int numberOfVertex;
	int nAnt;
	float alpha, beta;
	float r;
	int Lmin;
	float** t;
	float** n;
	int** d;
public:
	AntColony(int numberOfVertex, int nAnt, float alpha, float beta, float r, float Lmin, int** d);
	int findMinDist(int iterations);
};

