#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

int main()
{
    ds::Array<int> a(10);
    ds::it::Iterator<int>* iter = a.ToIterator();

    srand(time(NULL));

    while(iter->HasNext())
    {
        iter->Next() = rand() % 30 + 1;
    }

    delete iter;
    
    std::cout << a << "\n";

    return 0; 
}