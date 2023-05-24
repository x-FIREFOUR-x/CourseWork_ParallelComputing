#pragma once
#include "MergeSortBase.h"

#include <iostream>
#include <omp.h>
#include <algorithm>

using namespace std;

template <class T>
class Tester
{
private:
	T* correctArray;

public:
	Tester(const T* inputArr, const int sizeArray)
	{
		correctArray = new T[sizeArray];
		copy(inputArr, inputArr + sizeArray, correctArray);
		sort(correctArray, correctArray + sizeArray);
	}

	~Tester()
	{
		delete[] correctArray;
	}

	void testMergeSort(MergeSortBase<T>* mergeSort, const T* inputArr, const int sizeArray, const int countTests = 1, const int countThreads = 1)
	{
		T* arr = new T[sizeArray];

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
};
