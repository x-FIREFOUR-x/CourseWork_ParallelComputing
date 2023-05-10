#pragma once

#include <vector>

using namespace std;
class MergeSort
{
public:
	static void sort(vector<int>& array, int const begin, int const end);

private:
	static void merge(vector<int>& array, int const begin, int const mid, int const end);
};

