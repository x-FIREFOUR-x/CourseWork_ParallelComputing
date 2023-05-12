#include <iostream>

#include "DataGenerator.h"
#include "FileWorker.h"
#include "MergeSort.h"
#include "OMPMergeSort.h"
#include "ThreadMergeSort.h"

using namespace std;
int main(int args, char *argv[])
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

		return 0;
	}


	string filename;
	cout << "Filename: ";
	cin >> filename;

	int countThread;
	cout << "Threds: ";
	cin >> countThread;

	int size = 0;
	int* arr = FileWorker<int>::readArray(filename, size);


	int* arr1 = new int[size];
	copy(arr, arr + size, arr1);

	MergeSort mergeSort;
	mergeSort.sort(arr1, size);


	int* arr2 = new int[size];
	copy(arr, arr + size, arr2);

	ThreadMergeSort threadMergeSort;
	threadMergeSort.sort(arr2, size, countThread);

	bool sortThreadCorrect = std::equal(arr1, arr1 + size, arr2, arr2 + size);
	cout << "Is equal: " << sortThreadCorrect << endl;


#ifndef _MSC_VER
	int* arr3 = new int[size];
	copy(arr, arr + size, arr3);

	OMPMergeSort ompMergeSort;
	ompMergeSort.sort(arr3, size, countThread);

	bool sortOMPCorrect = std::equal(arr1, arr1 + size, arr3, arr3 + size);
	cout << "Is equal: " << sortOMPCorrect << endl;
#endif
	
	return 0;
}

