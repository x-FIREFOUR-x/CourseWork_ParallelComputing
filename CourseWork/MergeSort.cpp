#include "MergeSort.h"

void MergeSort::sort(vector<int>& array, int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	sort(array, begin, mid);
	sort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

void MergeSort::merge(vector<int>& array, int const begin, int const mid, int const end)
{
	vector<int> mergeArray;

	int indexLeftArray = begin;
	int indexRightArray = mid + 1;

	while (indexLeftArray <= mid && indexRightArray <= end)
	{
		if (array[indexLeftArray] < array[indexRightArray])
		{
			mergeArray.push_back(array[indexLeftArray]);
			indexLeftArray++;
		}
		else
		{
			mergeArray.push_back(array[indexRightArray]);
			indexRightArray++;
		}
	}

	for (int i = indexLeftArray; i <= mid; i++)
	{
		mergeArray.push_back(array[i]);
	}

	for (int i = indexRightArray; i <= end; i++)
	{
		mergeArray.push_back(array[i]);
	}


	std::copy(mergeArray.begin(), mergeArray.end(), array.begin() + begin);
	//array = mergeArray;
}
