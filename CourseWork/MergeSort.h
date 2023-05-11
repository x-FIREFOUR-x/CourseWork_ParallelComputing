#pragma once

#include <vector>

using namespace std;
class MergeSort
{
private:
	static int sizeTask;

public:
	static void sort(int* arr, int const size);

private:
	static void merge(int* arr, int const size, int* buff);

	static void sortRecursive(int* arr, int const size, int* buff);


#ifndef _MSC_VER

public:
	static void ompSort(int* arr, int const size, int countThreads = 4);

private:
	static void ompSortRecursive(int* arr, int const size, int* buff);

#endif



	
};

