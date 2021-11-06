#include "IOClass.h"
#include <fstream>
#include <vector>

int** IOClass::read(std::string name, int&n)
{
	std::ifstream fin(name);
	fin >> n;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			fin >> matrix[i][j];
		}
	}
	fin.close();
	return matrix;
}

void IOClass::write(std::string name, float**matrix, int n)
{
	std::ofstream fout(name);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fout << matrix[i][j] << " ";
		}
		fout << "\n";
	}
	fout.close();
}
