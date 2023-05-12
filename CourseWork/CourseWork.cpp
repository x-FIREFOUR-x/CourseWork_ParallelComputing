#include <iostream>

#include "DataGenerator.h"
#include "FileWorker.h"
#include "MergeSort.h"
#include "OMPMergeSort.h"

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
	MergeSort mergeSort;
	mergeSort.sort(arr, size);

#ifndef _MSC_VER
	int sizeOMP = 0;
	int* arrayOMP = FileWorker<int>::readArray(filename, sizeOMP);

	OMPMergeSort ompMergeSort;
	ompMergeSort.sort(arrayOMP, sizeOMP, countThread);

	bool eq = std::equal(arrayOMP, arrayOMP + sizeOMP, arr, arr + size);
	cout << "Is equal: " << eq << endl;
#endif
	
	return 0;
}

