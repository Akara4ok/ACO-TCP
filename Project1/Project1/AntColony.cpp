#include "AntColony.h"
#include <vector>
#include <cmath>
#include <ctime>
#include <iostream>

AntColony::AntColony(int numberOfVertex, int nAnt, float alpha, float beta, float r, float Lmin, int** d)
{
	srand(time(NULL));
	this->numberOfVertex = numberOfVertex;
	this->nAnt = nAnt;
	this->alpha = alpha;
	this->beta = beta;
	this->r = r;
	this->Lmin = Lmin;
	this->d = d;
	
	n = new float* [numberOfVertex];
	for (int i = 0; i < numberOfVertex; i++)
	{
		n[i] = new float[numberOfVertex];
		for (int j = 0; j < numberOfVertex; j++)
		{
			if (d[i][j] != 0)
				n[i][j] = (float)1 / d[i][j];
			else
				n[i][j] = 0;
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

void output(float** t, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << t[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int AntColony::findMinDist(int iterations)
{
	bool* visited = new bool[numberOfVertex];

	for (int it = 0; it < iterations; it++)
	{
		float** deltaT = new float* [numberOfVertex];
		for (int i = 0; i < numberOfVertex; i++)
		{
			deltaT[i] = new float[numberOfVertex];
			for (int j = 0; j < numberOfVertex; j++)
			{
				deltaT[i][j] = 0;
			}
		}
		for (int k = 0; k < nAnt; k++)
		{
			for (int i = 0; i < numberOfVertex; i++)
				visited[i] = false;
			int current = 0;
			int L = 0;
			int unvisited = numberOfVertex;
			std::vector<int> path;
			while (unvisited > 0)
			{
				path.push_back(current);
				visited[current] = true;
				unvisited--;
				std::vector<std::pair<int, float>> p;
				float s = 0;
				int ind = 0;
				for (int j = 0; j < numberOfVertex; j++)
				{
					if (!visited[j])
					{
						std::pair<int, float> vertexProbability;
						vertexProbability.first = j;
						vertexProbability.second = pow((t[current][j]), alpha) * pow((n[current][j]), beta);
						p.push_back(vertexProbability);
						s = s + p.back().second;
					}
				}
				for (int j = 0; j < p.size(); j++)
					p[j].second = (float)p[j].second / s;

				float num = (float)(rand() % 100) / 100;

				float interval = 0;
				for (int j = 0; j < p.size(); j++)
				{
					if (p[j].second + interval > num)
					{
						ind = p[j].first;
						break;
					}
					else
					{
						interval = interval + p[j].second;
					}
				}
				L = L + d[current][ind];
				current = ind;
			}
			for (int i = 0; i < path.size() - 1; i++)
			{
				deltaT[path[i]][path[i + 1]] = deltaT[path[i]][path[i + 1]] + (float)Lmin / L;
			}
		}

		for (int i = 0; i < numberOfVertex; i++)
		{
			for (int j = 0; j < numberOfVertex; j++)
			{
				t[i][j] = (1 - r) * t[i][j] + deltaT[i][j];
			}
		}
		//output(t, numberOfVertex);
		for (int i = 0; i < numberOfVertex; i++)
		{
			delete[] deltaT[i];
		}
		delete[] deltaT;
		int i = 0;
		int current = 0;
		int L = 0;
		while (i < numberOfVertex - 1)
		{
			float max = -1;
			int ind = 0;
			std::cout << current << " ";
			for (int j = 0; j < numberOfVertex; j++)
			{
				if (t[current][j] > max)
				{
					max = t[current][j];
					ind = j;
				}
			}
			L = L + d[current][ind];
			current = ind;
			i++;
		}
		L = L + d[current][0];
		std::cout << "0" << "\n" << L << "\n";
	}
	return 0;
}
