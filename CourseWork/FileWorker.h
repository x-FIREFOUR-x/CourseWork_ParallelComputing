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
	static vector<T> readArray(const string filename);

	static void writeArray(const string filename, vector<T> array);

    static T* readArray(const string filename, int& size);

    static void writeArray(const string filename, const T* array, const int size);

};

#ifndef _MSC_VER
template<class T>
string FileWorker<T>::fileDir = "..\\CourseWork\\Data\\";
#else
template<class T>
string FileWorker<T>::fileDir = "Data\\";
#endif

template<class T>
vector<T> FileWorker<T>::readArray(const string filename)
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
void FileWorker<T>::writeArray(const string filename, const vector<T> array)
{
    ofstream file(fileDir + filename);

    file << array.size() << "\n";
    for (auto element : array)
    {
        file << element << " ";
    }

    file.close();
}


template<class T>
T* FileWorker<T>::readArray(const string filename, int& size)
{
    ifstream file(fileDir + filename);

    if (!file.is_open())
    {
        cout << "Failed open file";
        return nullptr;
    }
        

    file >> size;

    T* array = new T[size];
    int element;
    for (size_t i = 0; i < size; i++)
    {
        file >> element;
        array[i] = element;
    }

    return array;
}

template<class T>
void FileWorker<T>::writeArray(const string filename, const T* array, const int size)
{
    ofstream file(fileDir + filename);

    file << size << "\n";
    for (size_t i = 0; i < size; i++)
    {
        file << array[i] << " ";
    }

    file.close();
}


