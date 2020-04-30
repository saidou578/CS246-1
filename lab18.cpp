#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int ToInteger(string num) 
{
int num1=0; 
for(int i=0;i<num.length();i++)
{
if(num[i]=='0')num1=num1*10+0;
else if(num[i]=='1')num1=num1*10+1;
else if(num[i]=='2')num1=num1*10+2; 
else if(num[i]=='3')num1=num1*10+3;
else if(num[i]=='4')num1=num1*10+4;
else if(num[i]=='5')num1=num1*10+5;
else if(num[i]=='6')num1=num1*10+6;
else if(num[i]=='7')num1=num1*10+7;
else if(num[i]=='8')num1=num1*10+8;
else if(num[i]=='9')num1=num1*10+9;
else
return -2147483648; 

}
return num1; 
}
string ABStringWithException(int m, int n) 
{
string ab=""; 
if (m>=n) 
{
if (m/n==1) 
{
for(int i=0;i<m+n;i++) 
{
if (i%2==0)
ab+='A'; 
else
ab+='B';
}
}
else if (m/n==2)
{
int c=0;
int i=0;
while(c<m+n)
{
if (i%3==0)
{
ab+='A';
i+=1;
c+=1;
}
else if(i%3==1) 
{
ab+='A';
i+=1;
c+=1;
}
else
{
ab+='B';
i+=1;
c+=1;
}
}
}
}
if(n>m)
{
if (n/m==1) 
{
for(int i=0;i<m+n;i++) 
{
if (i%2==0)
ab+='A'; 
else
ab+='B';
}
}
else if (m/n==2) 
{
int c=0;
int i=0;
while(c<m+n)
{
if (i%3==0)
{
ab+='A';
i+=1;
c+=1;
}
else if(i%3==1) 
{
ab+='A';
i+=1;
c+=1;
}
else
{
ab+='B';
i+=1;
c+=1;
}
}
}

}
return ab; 


}

int main()
{
string a="1234";
cout<<ToInteger(a)<<endl;
cout<<ToInteger("1a");
cout<<endl;
cout<<ABStringWithException(8,3)<<endl;
cout<<ABStringWithException(16,5)<<endl;
cout<<ABStringWithException(3,8)<<endl;

return 0;
}