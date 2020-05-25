#include <iostream>
using namespace std;


int frequentElement(int arr[], int n)
{

int count[] = {0};
  
for(int i=0;i<n;i++)
{
count[arr[i]]++;
}
  

int maxIndex = 0;
for(int i=1;i<n;i++)
{

if(count[i] > count[maxIndex])
maxIndex = i; 
}

return maxIndex;
}


int numberCommonValues(int arr1[], int n1, int arr2[], int n2)
{
int count = 0;
  

for(int i=0;i<n1;i++)
{
int x = arr1[i];
  

for(int j=0;j<n2;j++)
{
if(arr2[j] == x)
{
count++; 
break; 
}
}
}
return count;
}

int numberPairs(int arr[], int n, int x)
{


  
int count = 0;
  
int left = 0;
int right = 0;
  
while(right < n)
{

if(arr[right] - arr[left] == x)
{
count++;
left++;
right++;
}
else if(arr[right] - arr[left] > x)
left++;
else
right++;
}  
return count;
}


int main()
{


int arr[] = {6,5,6,8,0,2,6,8,4,1};
int n = sizeof(arr)/sizeof(arr[0]); 
  

int MFE = frequentElement(arr, n);
  
cout<<"Given array is: \n";
for(int i=0;i<n;i++)
{
cout<<arr[i]<<" ";
}
cout<<"\nMost frequent element is: "<<MFE<<endl;
  

int arr1[] = {3,7,0,9,1,6};
int arr2[] = {6,1,8,4,0,3};
int n1 = sizeof(arr1)/sizeof(arr1[0]);
int n2 = sizeof(arr2)/sizeof(arr2[0]);
  

int commonElements = numberCommonValues(arr1,n1,arr2,n2);
  
cout<<"\nGiven array 1: \n";
for(int i=0;i<n1;i++)
{
cout<<arr1[i]<<" ";
}
cout<<"\nGiven array 2: \n";
for(int i=0;i<n2;i++)
{
cout<<arr2[i]<<" ";
}
cout<<"\nNumber of common elements are: "<<commonElements<<endl;
  

int sortedArray[] = {1,2,3,4,5,6,7,8,9,10,16,19};
n = sizeof(sortedArray)/sizeof(sortedArray[0]);
int target = 4;
int pairs = numberPairs(sortedArray, n, target);
  
cout<<"\n\nGiven sorted array is: \n";
for(int i=0;i<n;i++)
{
cout<<sortedArray[i]<<" ";
}
cout<<"\nNumber of pairs with difference "<<target<<" is: ";
cout<<pairs<<endl;
  
return 0;
}