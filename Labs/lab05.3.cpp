using namespace std;
#define MAX 100000
int main()
{
int n,i,j,value=0,target;
cout<<"Enter the size of the array\n";
cin>>n;
int arr[n];
  
cout<<"Enter the array elements\n";
for(i=0;i<n;i++)
{
cin>>arr[i];
}
cout<<"Enter the target value\n";
cin>>target;
  
int map_of_element[MAX] = {0};
for (i = 0; i < n; i++)
map_of_element[arr[i]] = 1;
  
for (i = 0; i < n; i++)
{
int x = arr[i];
if (x - target >= 0 && map_of_element[x - target])
value++;
if (x + target < MAX && map_of_element[x + target])
value++;
map_of_element[x] = false;
}
cout<<"Number of pairs with difference equal to "<<target<<": "<<value;
return 0;
}