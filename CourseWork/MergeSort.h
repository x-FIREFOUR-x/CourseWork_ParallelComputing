#pragma once

#include "MergeSortBase.h"

using namespace std;
class MergeSort : MergeSortBase
{
public:
	void sort(int* arr, int const size, const int countThread = 1) override;

private:
	void sortRecursive(int* arr, const int size, int* buff, int depthRecursive) override;
};
