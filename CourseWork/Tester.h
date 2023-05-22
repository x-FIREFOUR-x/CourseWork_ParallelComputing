#pragma once
#include "MergeSortBase.h"

using namespace std;
class Tester
{
private:
	int* correctArray;

public:
	Tester(const int* inputArr, const int sizeArray);
	~Tester();

	void testMergeSort(MergeSortBase* mergeSort, const int* inputArray, const int sizeArray, const int countTests = 1, const int countThreads = 1);
};
