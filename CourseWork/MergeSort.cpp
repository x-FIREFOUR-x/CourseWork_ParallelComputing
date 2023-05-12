#include "MergeSort.h"

#include <omp.h>
#include <iostream>
#include <algorithm>

void MergeSort::sort(int* arr, const int size, const int)
{
	double start_time = omp_get_wtime();

	int* buff = new int[size];
	sortRecursive(arr, size, buff);

	double end_time = omp_get_wtime();
	cout << (end_time - start_time) << "s non parallel sort.\n";
}

void MergeSort::sortRecursive(int* arr, const int size, int* buff)
{
	if (size == 1)
		return;

	sortRecursive(arr, size / 2, buff);
	sortRecursive(arr + (size / 2), size - (size / 2), buff + (size / 2));

	merge(arr, size, buff);
}
