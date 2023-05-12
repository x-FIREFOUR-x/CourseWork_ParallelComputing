#ifndef _MSC_VER

#include "OMPMergeSort.h"

#include <iostream>
#include <omp.h>
#include <algorithm>

void OMPMergeSort::sort(int* arr, const int size, const int countThreads)
{
	omp_set_dynamic(0);
	omp_set_num_threads(countThreads);

	double start_time = omp_get_wtime();

	int* buff = new int[size];
	#pragma omp parallel
	{
		#pragma omp single
		sortRecursive(arr, size, buff, 1);
	}

	double end_time = omp_get_wtime();
	cout << (end_time - start_time) << "s omp parallel sort.\n";
}

void OMPMergeSort::sortRecursive(int* arr, int const size, int* buff, int depthRecursive)
{
	if (size == 1)
		return;

	if (size <= sizeTask)
	{
		std::sort(arr, arr + size);
		return;
	}

	#pragma omp task shared(arr) if (size > sizeTask)
	sortRecursive(arr, size / 2, buff, depthRecursive + 1);

	#pragma omp task shared(arr) if (size > sizeTask)
	sortRecursive(arr + (size / 2), size - (size / 2), buff + (size / 2), depthRecursive + 1);

	#pragma omp taskwait
	merge(arr, size, buff);
}

#endif
