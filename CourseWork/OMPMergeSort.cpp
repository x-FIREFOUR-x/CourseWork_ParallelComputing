#ifndef _MSC_VER

#include "OMPMergeSort.h"

#include <omp.h>

void OMPMergeSort::sort(int* arr, const int size, const int countThreads)
{
	int* buff = new int[size];

	omp_set_dynamic(0);
	omp_set_num_threads(countThreads);
	#pragma omp parallel
	{
		#pragma omp single
		sortRecursive(arr, size, buff, 1);
	}

	delete[] buff;
}

void OMPMergeSort::sortRecursive(int* arr, int const size, int* buff, int depthRecursive)
{
	if (size <= sizeTask)
	{
		mergeSort.sort(arr, size);
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
