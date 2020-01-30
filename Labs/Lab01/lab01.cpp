/******************************************
 * Lab 01: String Manipulation
 * Before you begin compile the code to
 * make sure the code is working properly.
 *****************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

std::string RandStr(int n)
{
    int l = (n <= 0)?(20):(n);
    std::string values = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*(){}:;,.?";
    std::string result = "";
    int m = values.length();
    for(int i = 0;i < l;i += 1)
    {
        result += values[rand() % m];
    }

    return result;
}

int main()
{
    srand(time(NULL));
    std::string str = RandStr((rand() % 41 + 20));

    std::cout << "The random string generated is\n" << str << "\n";

    return 0;
}