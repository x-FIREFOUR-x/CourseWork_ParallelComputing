#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <omp.h>

#include "DataGenerator.h"
#include "FileWorker.h"
#include "MergeSort.h"

using namespace std;
int main()
{
	/*
	vector<int> array = DataGenerator::randomGenerateArray(1000000, -5, 15);
	FileWorker<int>::writeArray("file1m.txt", array);

	vector<int> array2 = DataGenerator::randomGenerateArray(10000000, -5, 15);
	FileWorker<int>::writeArray("file10m.txt", array2);

	vector<int> array3 = DataGenerator::randomGenerateArray(100000000, -5, 15);
	FileWorker<int>::writeArray("file100m.txt", array3);
	*/

	
	vector<int> array = FileWorker<int>::readArray("file100m.txt");
	vector<int> array2 = FileWorker<int>::readArray("file100m.txt");
	vector<int> array3 = FileWorker<int>::readArray("file100m.txt");
	vector<int> array4 = FileWorker<int>::readArray("file100m.txt");

	
	auto start_time = std::chrono::high_resolution_clock::now();
	MergeSort::sort(array, 0, array.size() - 1);
	auto end_time = std::chrono::high_resolution_clock::now();
	cout << (end_time - start_time) / std::chrono::milliseconds(1) << "ms to run.\n";

	MergeSort::ompParallelSort(array2, 0, array2.size() - 1, 2);

	MergeSort::ompParallelSort(array3, 0, array3.size() - 1, 4);

	MergeSort::ompParallelSort(array4, 0, array4.size() - 1, 8);
	
	bool t = array == array2;
	cout << t << endl;


 	vector<int> p = { 20, 20, 20 };
	
}

