#include "MergeSort.h"

#include <iostream>
#include <algorithm>

void MergeSort::sort(int* arr, const int size, const int)
{
	int* buff = new int[size];

	sortRecursive(arr, size, buff, 1);

	delete[] buff;
}

void MergeSort::sortRecursive(int* arr, const int size, int* buff, int depthRecursive)
{
	if (size == 1)
		return;

	sortRecursive(arr, size / 2, buff, depthRecursive + 1);
	sortRecursive(arr + (size / 2), size - (size / 2), buff + (size / 2), depthRecursive + 1);

	merge(arr, size, buff);
}
