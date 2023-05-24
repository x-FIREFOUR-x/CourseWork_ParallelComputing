#pragma once

#include "MergeSortBase.h"

#include <thread>
#include <cmath>

template<class T>
class ThreadMergeSort : public MergeSortBase<T>
{
private:
	int maxDepth;

public:
	void sort(T* arr, const int size, const function<bool(T, T)>& comparator, const int countThread) override
	{
		this->comparator = comparator;
		maxDepth = ceil(log2(countThread));
		T* buff = new T[size];

		thread th([=]() {sortRecursive(arr, size, buff, 1); });
		th.join();

		delete[] buff;
	}

private:
	void sortRecursive(T* arr, const int size, T* buff, int depthRecursive) override
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
			thread th([=, &depthRecursive]() {sortRecursive(arr, size / 2, buff, depthRecursive + 1); });

			sortRecursive(arr + (size / 2), size - (size / 2), buff + (size / 2), depthRecursive + 1);

			th.join();
		}

		this->merge(arr, size, buff);
	}
};
