#pragma once

#include <string>
#include <vector>
#include <fstream>

using namespace std;
template <class T>
class FileWorker
{
private:
	static string fileDir;

public:
	static vector<T> readArray(string filename);

	static void writeArray(string filename, vector<T> array);

};

template<class T>
string FileWorker<T>::fileDir = "Data\\";

template<class T>
vector<T> FileWorker<T>::readArray(string filename)
{
    ifstream file(fileDir + filename);

    int size = 0;
    file >> size;

    vector<T> array;
    int element;
    for (size_t i = 0; i < size; i++)
    {
        file >> element;
        array.push_back(element);
    }

    return array;
}

template<class T>
void FileWorker<T>::writeArray(string filename, vector<T> array)
{
    ofstream file(fileDir + filename);

    file << array.size() << "\n";
    for (auto element : array)
    {
        file << element << " ";
    }

    file.close();
}


