#pragma once
#include <string>

class IOClass
{
public:
	IOClass() {};
	int** read(std::string name, int&n);
	void write(std::string name, int**matrix, int n);
};

