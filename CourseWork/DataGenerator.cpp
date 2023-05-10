#include "DataGenerator.h"

vector<int> DataGenerator::randomGenerateArray(int size, int minValue, int maxValue)
{
    srand(time(NULL));

	vector<int> array;
	for (int i = 0; i < size; i++)
	{
		array.push_back(rand() % (maxValue + 1) + minValue);
	}

	return array;
}
