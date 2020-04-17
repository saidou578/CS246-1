#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,i,ma=0,value,x;
cout<<"Enter the size of the array\n";
cin>>n;
  
int freq[] = {0};
for(i=0;i<n;i++)
{
cin>>x;
freq[x]++;
}
for(i=0; i<n; i++)
{
if(freq[i] > ma)
{
ma = freq[i];
value = i;
}
}
cout<<"Maximum frequency value: "<<value;
return 0;
}



