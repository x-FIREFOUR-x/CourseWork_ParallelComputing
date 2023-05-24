#pragma once

#include "MergeSortBase.h"

using namespace std;
template <class T>
class MergeSort : public MergeSortBase<T>
{
public:
	void sort(T* arr, const int size, const int = 1) override
	{
		T* buff = new T[size];

		sortRecursive(arr, size, buff, 1);

		delete[] buff;
	}

private:
	void sortRecursive(T* arr, const int size, T* buff, int depthRecursive) override
	{
		if (size == 1)
			return;

		sortRecursive(arr, size / 2, buff, depthRecursive + 1);
		sortRecursive(arr + (size / 2), size - (size / 2), buff + (size / 2), depthRecursive + 1);

		this->merge(arr, size, buff);
	}
};
