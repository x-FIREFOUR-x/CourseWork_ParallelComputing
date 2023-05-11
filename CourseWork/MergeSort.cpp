#include "MergeSort.h"

#include <omp.h>
#include <iostream>
#include <algorithm>

int MergeSort::sizeTask = 2500000;

void MergeSort::sort(int* arr, int const size)
{
	double start_time = omp_get_wtime();

	int* buff = new int[size];
	sortRecursive(arr, size, buff);

	double end_time = omp_get_wtime();
	cout << (end_time - start_time) << "s to run.\n";
}

void MergeSort::merge(int* arr, int const size, int* buff)
{
	int mid = size / 2;

	int indexLeftArray = 0;
	int indexRightArray = mid;

	int indexBuff = 0;
	while (indexLeftArray < mid && indexRightArray < size)
	{
		if (arr[indexLeftArray] < arr[indexRightArray])
		{
			buff[indexBuff] = arr[indexLeftArray];
			indexLeftArray++;
			indexBuff++;
		}
		else
		{
			buff[indexBuff] = arr[indexRightArray];
			indexRightArray++;
			indexBuff++;
		}
	}

	while (indexLeftArray < mid)
	{
		buff[indexBuff] = arr[indexLeftArray];
		indexLeftArray++;
		indexBuff++;
	}

	while (indexRightArray < size)
	{
		buff[indexBuff] = arr[indexRightArray];
		indexRightArray++;
		indexBuff++;
	}
	memcpy(arr, buff, size * sizeof(int));
}

void MergeSort::sortRecursive(int* arr, int const size, int* buff)
{
	if (size == 1)
		return;

	sortRecursive(arr, size / 2, buff);
	sortRecursive(arr + (size / 2), size - (size / 2), buff + (size / 2));

	merge(arr, size, buff);
}

void MergeSort::ompSort(int* arr, int const size, int countThreads)
{
	omp_set_dynamic(0);
	omp_set_num_threads(countThreads);

	double start_time = omp_get_wtime();

	int* buff = new int[size];

	#pragma omp parallel
	{
		#pragma omp single
		ompSortRecursive(arr, size, buff);
	}
	double end_time = omp_get_wtime();
	cout << (end_time - start_time) << "ms to run.\n";
}


void MergeSort::ompSortRecursive(int* arr, int const size, int* buff)
{
	if (size == 1)
		return;

	if (size <= sizeTask)
	{
		std::sort(arr, arr + size);
		return;
	}

	
	#pragma omp task shared(arr) if (size > sizeTask)
	sortRecursive(arr, size / 2, buff);

	#pragma omp task shared(arr) if (size > sizeTask)
	sortRecursive(arr + (size / 2), size - (size / 2), buff + (size / 2));

	#pragma omp taskwait
	merge(arr, size, buff);
}



