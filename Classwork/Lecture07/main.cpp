#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Set.h"

int main()
{
	srand(time(NULL));
	ds::da::Set<int> S;
	ds::sn::Set<int> T;

	for(int i = 0;i < 50;i += 1)
	{
		S.Insert((rand() % 25 + 1));
		T.Insert((rand() % 25 + 1));
	}

	std::cout << "|S| = " << S.Size() << "\nS = " << S << "\n"; 
	std::cout << "|T| = " << T.Size() << "\nT = " << T << "\n"; 

	for(int i = 0;i < 10;i += 1)
	{
		S.Remove((rand() % 25 + 1));
		T.Remove((rand() % 25 + 1));
	}
	
	std::cout << "|S| = " << S.Size() << "\nS = " << S << "\n"; 
	std::cout << "|T| = " << T.Size() << "\nT = " << T << "\n"; 

	return 0;
}
