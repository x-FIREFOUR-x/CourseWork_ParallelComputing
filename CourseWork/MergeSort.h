#pragma once

#include <vector>

using namespace std;
class MergeSort
{
private:
	static int sizeTask;

public:
	static void sort(vector<int>& arr, int const begin, int const end);

	static void ompParallelSort(vector<int>& arr, int const begin, int const end, int countThreads = 4);

private:
	static void merge(vector<int>& arr, int const begin, int const mid, int const end);

	static void ompSort(vector<int>& arr, int const begin, int const end);
};

