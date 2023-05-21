#include <iostream>
#include <algorithm>

#include "DataGenerator.h"
#include "FileWorker.h"
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

	int countThread;
	cout << "Threds: ";
	cin >> countThread;

	int countTest;
	cout << "Count tests: ";
	cin >> countTest;

	int size = 0;
	int* inputArr = FileWorker<int>::readArray(filename, size);

	int* correctArr = new int[size];
	copy(inputArr, inputArr + size, correctArr);
	sort(correctArr, correctArr + size);


	// Sequential merge sort
	int* arr1 = new int[size];
	bool sortSequentialCorrect = true;
	double timeSequential = 0;
	for (size_t i = 0; i < countTest; i++)
	{
		copy(inputArr, inputArr + size, arr1);

		MergeSort mergeSort;
		timeSequential += mergeSort.sort(arr1, size);

		if (!std::equal(arr1, arr1 + size, correctArr, correctArr + size))
			sortSequentialCorrect = false;
	}
	cout << endl << timeSequential / countTest << "s non parallel sort.\n";
	cout << "Correct: " << sortSequentialCorrect << endl;
	delete[] arr1;


	// Parallel merge sort (Thread)
	int* arr2 = new int[size];
	bool sortThreadCorrect = true;
	double timeThread = 0;
	for (size_t i = 0; i < countTest; i++)
	{
		copy(inputArr, inputArr + size, arr2);

		ThreadMergeSort threadMergeSort;
		timeThread += threadMergeSort.sort(arr2, size, countThread);

		if (!std::equal(arr2, arr2 + size, correctArr, correctArr + size))
			sortThreadCorrect = false;
	}
	cout << endl << timeThread / countTest << "s thread parallel sort.\n";
	cout << "Correct: " << sortThreadCorrect << endl;
	delete[] arr2;


	// Parallel merge sort (OpenMP)
#ifndef _MSC_VER
	int* arr3 = new int[size];
	bool sortOMPCorrect = true;
	double timeOMP = 0;
	for (size_t i = 0; i < countTest; i++)
	{
		copy(inputArr, inputArr + size, arr3);

		OMPMergeSort ompMergeSort;
		timeOMP += ompMergeSort.sort(arr3, size, countThread);

		if (!std::equal(arr3, arr3 + size, correctArr, correctArr + size))
			sortOMPCorrect = false;
	}
	cout << endl << timeOMP / countTest << "s OpenMP parallel sort.\n";
	cout << "Correct: " << sortOMPCorrect << endl;
	delete[] arr3;
#endif

	delete[] inputArr;
	delete[] correctArr;
	
	return 0;
}

