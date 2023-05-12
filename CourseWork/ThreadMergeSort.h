#pragma once

#include "MergeSortBase.h"

class ThreadMergeSort : MergeSortBase
{
private:
	int maxDepth;

public:
	void sort(int* arr, int const size, const int countThread = 1) override;

private:
	void sortRecursive(int* arr, const int size, int* buff, int depthRecursive) override;
};
