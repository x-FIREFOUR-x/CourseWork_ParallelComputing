#include <iostream>
#include <vector>
#include <algorithm>

#include "DataGenerator.h"
#include "FileWorker.h"
#include "MergeSort.h"

using namespace std;
int main()
{
	vector<int> array = DataGenerator::randomGenerateArray(10, -5, 15);
 
	FileWorker<int>::writeArray("file.txt", array);

	vector<int> array2 = FileWorker<int>::readArray("file.txt");

	MergeSort::sort(array2, 0, array2.size() - 1);

	vector<int> p = { 20, 20, 20 };
}

