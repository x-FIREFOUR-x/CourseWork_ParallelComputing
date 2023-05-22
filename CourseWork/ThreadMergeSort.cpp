#include "ThreadMergeSort.h"

#include <thread>
#include <cmath>

void ThreadMergeSort::sort(int* arr, const int size, const int countThread)
{
	maxDepth = ceil(log2(countThread));
	int* buff = new int[size];

	thread th([=](){sortRecursive(arr, size, buff, 1);});
	th.join();

	delete[] buff;
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
		thread th([=, &depthRecursive](){sortRecursive(arr, size / 2, buff, depthRecursive + 1);});

		sortRecursive(arr + (size / 2), size - (size / 2), buff + (size / 2), depthRecursive + 1);

		th.join();
	}
	
	merge(arr, size, buff);
}
