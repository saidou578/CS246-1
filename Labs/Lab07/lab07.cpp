#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"

/*********************************************************
 * Function A 
 * Description:  
 * Runtime:
 *********************************************************/
int A(ds::Vector<int>& data)
{
    if(data.Length() <= 1)
    {
        return 0;
    }
    int mn = (data[0] <= data[1])?(data[0]):(data[1]);
    int mx = data[0] + data[1] - mn;
    int n = data.Length();
    int i = 0;

    while(i < n)
    {
        if(mx < data[i])
        {
            mx = data[i];
        }
        else if(mn > data[i])
        {
            mn = data[i];
        }
        i += 1;
    }
    return (mx - mn);
}

/*********************************************************
 * Function B 
 * Description:  
 * Runtime:
 *********************************************************/
std::string B(int dy)
{
    int os = 5;
    std::string wkdy[7] = {"Sunday"};
    wkdy[1] = "Monday";
    wkdy[2] = "Tuesday";
    wkdy[3] = "Wednesday";
    wkdy[4] = "Thursday";
    wkdy[5] = "Friday";
    wkdy[6] = "Saturday";

    if(dy <= 0 || dy > 29)
    {
        return "Not a valid day";
    }
    return wkdy[(os + dy) % 7];
}

/*********************************************************
 * Function C 
 * Description:  
 * Runtime:
 *********************************************************/
bool C(int n)
{
    int p = (n < 0)?(-1 * n):(n);

    for(int i = 2;i * i <= p;i += 1)
    {
        if(p % 1 != 0)
        {
            return false;
        }
    }
    return (p > 1);
}

/*********************************************************
 * Function D 
 * Description:  
 * Runtime:
 *********************************************************/
void D(ds::Vector<int>& data,int n)
{
    if(n >= 1)
    {
        for(int i = 1;i <= n;i += 1)
        {
            for(int j = 1;j <= n;j += 1)
            {
                data.Insert(i * j);
            }
        }
    }
}

/*********************************************************
 * Function E 
 * Description:  
 * Runtime:
 *********************************************************/
int E(int n)
{
    return (n > 0)?(n * (n + 1) * (2 * n + 1)/6):(0);
}

/*********************************************************
 * Function F
 * Description:  
 * Runtime:
 *********************************************************/
std::string F(int n)
{
    if(n <= 0)
    {
        return "0";
    }
    std::string cur = "";
    char dc;
    int di;

    while(n > 0)
    {
        di = n % 10;
        dc = (char)('0' + di);
        cur = dc + cur;
        n /= 10;
    }
    return cur;
}

int main()
{
    std::cout << F(3320);
    return 0; 
}
