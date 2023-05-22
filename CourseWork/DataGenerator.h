#pragma once

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;
class DataGenerator
{
public:
	static vector<int> randomGenerateVector(int size, int minValue, int maxValue);

	static int* randomGenerateArray(int size, int minValue, int maxValue);
};
