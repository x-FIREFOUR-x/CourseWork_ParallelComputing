#include <iostream>
#include <omp.h>


#include "DataGenerator.h"
#include "FileWorker.h"
#include "MergeSort.h"

using namespace std;
int main(int *args, char *argv[])
{
	cout << _OPENMP;

	/*
	//vector<int> array = DataGenerator::randomGenerateArray(1000000, -5, 15);
	//FileWorker<int>::writeArray("file1m.txt", array);

	//vector<int> array2 = DataGenerator::randomGenerateArray(10000000, -5, 15);
	//FileWorker<int>::writeArray("file10m.txt", array2);

	//vector<int> array3 = DataGenerator::randomGenerateArray(100000000, -5, 15);
	//FileWorker<int>::writeArray("file100m.txt", array3);
	

	int size = 0;
	int* array = FileWorker<int>::readArray("file10m.txt", size);
	//int* array2 = FileWorker<int>::readArray("file10m.txt", size);
	int* array3 = FileWorker<int>::readArray("file10m.txt", size);
	//int* array4 = FileWorker<int>::readArray("file10m.txt", size);

	
	MergeSort::sort(array, size);
	
	//MergeSort::ompSort(array2, size, 1);

	MergeSort::ompSort(array3, size, 4);

	//MergeSort::ompSort(array4, size, 8);
	*/
	
	omp_set_num_threads(4);
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		printf("Hello (%d)", id);
		printf("World (%d)\n", id);
	}
	return 0;
	
}

