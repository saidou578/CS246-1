#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,i,j,value=0;
cout<<"Enter the size of the array\n";
cin>>n;
  
int arr1[n], arr2[n];
  
cout<<"Enter the array 1 elements\n";
for(i=0;i<n;i++)
{
cin>>arr1[i];
}
cout<<"Enter the array 2 elements\n";
for(i=0;i<n;i++)
{
cin>>arr2[i];
}

sort(arr1,arr1+n);
sort(arr2,arr2+n);
  
i =0,j=0;
while(i<n && j<n)
{
if(arr1[i] == arr2[j])
{
value++;
i++;
j++;
}
else if(arr1[i] < arr2[j])
{
i++;
}
else
{
j++;
}
}
  
cout<<"Number of common values in two arrays: "<<value;
return 0;
}