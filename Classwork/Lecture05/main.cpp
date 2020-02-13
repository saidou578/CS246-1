#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"

int main()
{
    srand(time(NULL));

    ds::Vector<int> a(10);
    int arr[10];

    for(int i = 0;i < 10;i += 1)
    {
        arr[i] = rand() % 50 + 1;
    }

    a.Assign(12,10);
    ds::it::Iterator<int>* iter = new ds::it::Iterator<int>(arr,10);
    a.Insert(iter);
    delete iter;

    std::cout << a << "\n";

    return 0; 
}