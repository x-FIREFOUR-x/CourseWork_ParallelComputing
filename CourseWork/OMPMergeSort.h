#ifndef _MSC_VER

#pragma once

#include "MergeSortBase.h"

using namespace std;
class OMPMergeSort : MergeSortBase
{
private:
	const int sizeTask = 1000;

public:
	void sort(int* arr, const int size, const int countThreads = 1) override;

private:
	void sortRecursive(int* arr, int const size, int* buff, int depthRecursive) override;
};

#endif
