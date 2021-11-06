#include "AntColony.h"

AntColony::AntColony(int numberOfVertex, int nAnt, float alpha, float beta, float r, float Lmin, int** d)
{
	this->numberOfVertex = numberOfVertex;
	this->nAnt = nAnt;
	this->alpha = alpha;
	this->beta = beta;
	this->r = r;
	this->Lmin = Lmin;
	
	n = new float* [numberOfVertex];
	for (int i = 0; i < numberOfVertex; i++)
	{
		n[i] = new float[numberOfVertex];
		for (int j = 0; j < numberOfVertex; j++)
		{
			if (d[i][j] != 0)
				n[i][j] = (float)1 / d[i][j];
			else
				n[i][j] = 100;
		}
	}

	t = new float* [numberOfVertex];
	for (int i = 0; i < numberOfVertex; i++)
	{
		t[i] = new float[numberOfVertex];
		for (int j = 0; j < numberOfVertex; j++)
		{
			t[i][j] = 1;
		}
	}
}
