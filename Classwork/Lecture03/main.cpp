#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

void RandInts(ds::Array<int>& arr,int lo,int hi)
{
    int mx = (hi >= lo)?(hi):(lo), mn = (lo <= hi)?(lo):(hi);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        iter->Next() = rand() % (mx - mn + 1) + mn;
    }

    delete iter;
} 

void SortedInts(ds::Array<int>& arr,int start)
{
    int prev = start;
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        prev = prev + rand() % 10;
        iter->Next() = prev; 
    }

    delete iter;
}

int main()
{
    ds::Array<int> a(10), b(20);

    srand(time(NULL));

    RandInts(a,1,50);
    SortedInts(b,8);

    std::cout << a << "\n";
    std::cout << b << "\n";
    
    return 0; 
}