#include "Tester.h"

#include <iostream>
#include <omp.h>
#include <algorithm>

Tester::Tester(const int* inputArr, const int sizeArray)
{
	correctArray = new int[sizeArray];
	copy(inputArr, inputArr + sizeArray, correctArray);
	sort(correctArray, correctArray + sizeArray);
}

Tester::~Tester()
{
	delete[] correctArray;
}

void Tester::testMergeSort(MergeSortBase* mergeSort, const int* inputArr, const int sizeArray, const int countTests, const int countThreads)
{
	int* arr = new int[sizeArray];

	bool sortThreadCorrect = true;
	double timeAllWork = 0;
	for (size_t i = 0; i < countTests; i++)
	{
		copy(inputArr, inputArr + sizeArray, arr);

		double startTime = omp_get_wtime();

		mergeSort->sort(arr, sizeArray, countThreads);

		double timeCurrentTest = omp_get_wtime() - startTime;
		cout << "   test" << i + 1 << " time: " << timeCurrentTest << "s.\n";

		timeAllWork += timeCurrentTest;

		if (!std::equal(arr, arr + sizeArray, correctArray, correctArray + sizeArray))
			sortThreadCorrect = false;
	}

	cout << "  -------------------------\n";
	cout << "   Average time: " << timeAllWork / countTests << "s.\n";
	cout << "   Correct: " << sortThreadCorrect << endl;

	delete[] arr;
}
