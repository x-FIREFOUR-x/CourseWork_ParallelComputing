#pragma once

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

template <class T>
class MergeSortBase
{
protected:
	bool (*comparator)(T, T);

public:
	virtual void sort(T* arr, const int size, bool(*comparator)(T, T), int countThreads = 1) = 0;

protected:
	void merge(T* arr, const int size, T* buff)
	{
		int mid = size / 2;

		int indexLeftArray = 0;
		int indexRightArray = mid;

		int indexBuff = 0;
		while (indexLeftArray < mid && indexRightArray < size)
		{
			if (comparator(arr[indexLeftArray], arr[indexRightArray]))
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

	virtual void sortRecursive(T* arr, const int size, T* buff, int depthRecursive) = 0;
};
