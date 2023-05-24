#ifndef _MSC_VER

#pragma once

#include "MergeSortBase.h"
#include "MergeSort.h"

#include <omp.h>

using namespace std;

template <class T>
class OMPMergeSort : public MergeSortBase<T>
{
private:
	const int sizeTask = 1000;
	MergeSort<T> mergeSort;

public:
	void sort(T* arr, const int size, const int countThreads = 1) override
	{
		T* buff = new T[size];

		omp_set_dynamic(0);
		omp_set_num_threads(countThreads);
		#pragma omp parallel
		{
			#pragma omp single
			sortRecursive(arr, size, buff, 1);
		}

		delete[] buff;
	}

private:
	void sortRecursive(T* arr, int const size, T* buff, int depthRecursive) override
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
		this->merge(arr, size, buff);
	}
};

#endif
