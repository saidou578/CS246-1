/**********************************************************
 * Lecture 04: Non-Recursive Sorting Functions
 * Sorting the is the process of organizing content in a
 * monotonic order. When data is sorted it is possible 
 * to define more efficient algorithms to solve some 
 * problems.
 **********************************************************/ 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

void RandInts(ds::Array<int>& arr,int lo,int hi)
{
    int mx = (hi >= lo)?(hi):(lo);
    int mn = (lo <= hi)?(lo):(hi);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        iter->Next() = rand() % (mx - mn + 1) + mn;
    }

    delete iter;
} 

//There are three sorting algorithms we will implement

/**********************************************************
 * BubbleSort() - sorts content by moving the largest
 * value of the unsorted portion of the array to the
 * last position of the unsorted portion of the array
 * with a series of adjacent element swaps.
 *********************************************************/ 
template <typename T>
void BubbleSort(ds::Array<T>& data)
{
    return;
}

/**********************************************************
 * SelectionSort() - sorts content by swapping the 
 * contents of the element with the minimum value in the
 * unsorted portion of the array with the last elmenet
 * of the sorted portion of the array.
 *********************************************************/ 
template <typename T>
void SelectionSort(ds::Array<T>& data)
{
    return;
}

/**********************************************************
 * InsertionSort() - sorts content by continually swapping 
 * the content of the first element of the unsorted 
 * portion of the array with the sorted portion of the 
 * array until the content is correct position in the 
 * sorted portion of the array.  
 **********************************************************/ 
template <typename T>
void InsertionSort(ds::Array<T>& data)
{
    return;
}

int main()
{    
    srand(time(NULL));

    ds::Array<int> data[3] = {ds::Array<int>(15), ds::Array<int>(15), ds::Array<int>(15)};

    for(int i = 0;i < 3;i += 1)
    {
        RandInts(data[i],10,99);
        std::cout << "Data of Array " << (i + 1) << ":\n" << data[i] << "\n\n";
    }

    return 0; 
}