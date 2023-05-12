#include "MergeSortBase.h"

#include <iostream>
#include <algorithm>

void MergeSortBase::merge(int* arr, const int size, int* buff)
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
