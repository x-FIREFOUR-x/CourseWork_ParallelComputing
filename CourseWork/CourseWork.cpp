#include <iostream>
#include <algorithm>
#include <omp.h>

#include "DataGenerator.h"
#include "FileWorker.h"
#include "Tester.h"
#include "MergeSort.h"
#include "OMPMergeSort.h"
#include "ThreadMergeSort.h"

using namespace std;
int main(int args, char* argv[])
{
	bool operationSort;
	cout << "Input 0(generate array) or 1(sort array): ";
	cin >> operationSort;

	if (!operationSort)
	{
		string filename = "";
		cout << "Filename: ";
		cin >> filename;

		int size;
		cout << "Size array: ";
		cin >> size;

		int* arr = DataGenerator::randomGenerateArray(size, -1000, 1000);
		FileWorker<int>::writeArray(filename, arr, size);
		delete[] arr;

		return 0;
	}


	string filename;
	cout << "Filename: ";
	cin >> filename;

	int countThreads;
	cout << "Threds: ";
	cin >> countThreads;

	int countTests;
	cout << "Count tests: ";
	cin >> countTests;

	int size = 0;
	int* inputArr = FileWorker<int>::readArray(filename, size);

	Tester tester(inputArr, size);

	// Sequential merge sort
	cout << "\n<Sequential merge sort>" << endl;
	MergeSortBase* mergeSort = new MergeSort();
	tester.testMergeSort(mergeSort, inputArr, size, countTests);

	// Parallel merge sort (Thread)
	cout << "\n<Parallel merge sort (Thread)>" << endl;
	MergeSortBase* threadMergeSort = new ThreadMergeSort();
	tester.testMergeSort(threadMergeSort, inputArr, size, countTests, countThreads);

	// Parallel merge sort (OpenMP)
#ifndef _MSC_VER
	cout << "\n<Parallel merge sort (OpenMP)>" << endl;
	MergeSortBase* ompMergeSort = new OMPMergeSort();
	tester.testMergeSort(ompMergeSort, inputArr, size, countTests, countThreads);
#endif

	delete[] inputArr;

	return 0;
}
