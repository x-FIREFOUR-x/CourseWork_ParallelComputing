#pragma once

using namespace std;
class MergeSortBase
{
public:
	virtual void sort(int* arr, const int size, int countThreads = 1) = 0;

protected:
	void merge(int* arr, const int size, int* buff);

	virtual void sortRecursive(int* arr, const int size, int* buff) = 0;

};
