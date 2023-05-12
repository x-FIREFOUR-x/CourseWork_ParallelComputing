#include "ThreadMergeSort.h"

#include <omp.h>
#include <iostream>
#include <algorithm>
#include <thread>
#include <cmath>

void ThreadMergeSort::sort(int* arr, const int size, const int countThread)
{
	double start_time = omp_get_wtime();

	maxDepth = ceil(log2(countThread));

	int* buff = new int[size];
	sortRecursive(arr, size, buff, 1);

	double end_time = omp_get_wtime();
	cout << (end_time - start_time) << "s thread parallel sort.\n";
}

void ThreadMergeSort::sortRecursive(int* arr, const int size, int* buff, int depthRecursive)
{
	if (size == 1)
		return;

	if (depthRecursive > maxDepth)
	{
		sortRecursive(arr, size / 2, buff, depthRecursive + 1);

		sortRecursive(arr + (size / 2), size - (size / 2), buff + (size / 2), depthRecursive + 1);
	}
	else
	{
		auto lamda = [=, &depthRecursive]()
		{
			sortRecursive(arr, size / 2, buff, depthRecursive + 1);
		};

		thread th(lamda);

		sortRecursive(arr + (size / 2), size - (size / 2), buff + (size / 2), depthRecursive + 1);

		th.join();
	}
	
	merge(arr, size, buff);
}

