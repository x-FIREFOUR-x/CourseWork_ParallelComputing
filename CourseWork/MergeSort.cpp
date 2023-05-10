#include "MergeSort.h"

#include <omp.h>
#include <iostream>

int MergeSort::sizeTask = 100;

void MergeSort::sort(vector<int>& arr, int const begin, int const end)
{
	if (begin == end)
		return;

	int mid = begin + (end - begin) / 2;
	sort(arr, begin, mid);
	sort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}

void MergeSort::ompParallelSort(vector<int>& arr, int const begin, int const end, int countThreads)
{
	omp_set_dynamic(0);
	omp_set_num_threads(countThreads);

	double start_time2 = omp_get_wtime();
	#pragma omp parallel
	{
		#pragma omp single
		ompSort(arr, begin, end);
	}
	double end_time2 = omp_get_wtime();
	cout << (end_time2 - start_time2) << "ms to run.\n";
}

void MergeSort::merge(vector<int>& arr, int const begin, int const mid, int const end)
{
	vector<int> mergeArray;

	int indexLeftArray = begin;
	int indexRightArray = mid + 1;

	while (indexLeftArray <= mid && indexRightArray <= end)
	{
		if (arr[indexLeftArray] < arr[indexRightArray])
		{
			mergeArray.push_back(arr[indexLeftArray]);
			indexLeftArray++;
		}
		else
		{
			mergeArray.push_back(arr[indexRightArray]);
			indexRightArray++;
		}
	}

	for (int i = indexLeftArray; i <= mid; i++)
	{
		mergeArray.push_back(arr[i]);
	}

	for (int i = indexRightArray; i <= end; i++)
	{
		mergeArray.push_back(arr[i]);
	}

	std::copy(mergeArray.begin(), mergeArray.end(), arr.begin() + begin);
}

void MergeSort::ompSort(vector<int>& arr, int const begin, int const end)
{
	int size = end - begin + 1;

	if (begin == end)
		return;

	int mid = begin + (end - begin) / 2;

	#pragma omp task shared(arr) if (size > sizeTask)
	ompSort(arr, begin, mid);

	#pragma omp task shared(arr) if (size > sizeTask)
	ompSort(arr, mid + 1, end);

	#pragma omp taskwait
	merge(arr, begin, mid, end);
}
