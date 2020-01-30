#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
    Rational a,b(-8),c(5,10),d(b),e,f(16,-2);

    e = c;

    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << d << "\n";
    cout << e << "\n";
    cout << f << "\n";
    cout << "Total Rational Numbers: " << Rational::GetCount() << "\n";
    return 0;
}