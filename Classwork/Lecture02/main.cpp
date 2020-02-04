#include <iostream>
#include "Exception.h"
using namespace std;

void errorMessage(const Exception& ex)
{
    cout << ex << "\n";
}

int main()
{
    Exception exp("Default",__FILE__,__LINE__);
    DivideByZeroException exp2(__FILE__,__LINE__);
    OverflowException exp3(__FILE__,__LINE__);
    UnderflowException exp4(__FILE__,__LINE__);

    cout << exp << "\n";
    cout << exp2 << "\n";
    cout << exp3 << "\n";
    cout << exp4 << "\n";

    //Try the following:
    //errorMessage(exp);
    //errorMessage(exp2);
    //errorMessage(exp3);
    //errorMessage(exp4);
    
    return 0;
}