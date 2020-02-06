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

void SortedInts(ds::Array<int>& arr,int start,bool dup)
{
    int prev = start;
    int c = (dup)?(0):(1);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        prev = prev + rand() % 10 + c;
        iter->Next() = prev; 
    }

    delete iter;
}

int main()
{
    ds::Array<int> a(10), b(20);

    srand(time(NULL));

    RandInts(a,1,50);
    SortedInts(b,8,false);

    std::cout << a << "\n";
    std::cout << b << "\n";

    return 0; 
}