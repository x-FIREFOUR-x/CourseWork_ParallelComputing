#include <iostream>
#include <vector>

#include "DataGenerator.h"
#include "FileWorker.h"

using namespace std;
int main()
{
	vector<int> array = DataGenerator::randomGenerateArray(10, -5, 15);
 
	FileWorker<int>::writeArray("file.txt", array);

	vector<int> array2 = FileWorker<int>::readArray("file.txt");
}

