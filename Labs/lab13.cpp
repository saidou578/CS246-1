#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;

void ReverseContent(ifstream & in , ofstream & out)
{
   if(!in)
       {
           cout<<"Error while reading file \n";
           return;
       }
   if(!out)
   {
       cout<<"Error while writing to file\n";
       return ;
   }
  
   string text;
   string line;
   
   while(getline(in,line))
   {
       text=text+line+'\n';
   }
  
   
   int len = text.length();
   
   for(int i=len-2;i>=0;--i)
   {
       out<<text[i];
   }
  
  
}
bool IsPattern(string str)
{
int count=0;
int len = str.length();
if(len ==0) 
   return true;
if(len ==1 )
   return false;
if(str[0]!='a') 
   return false;
int i=0;

while(str[i]=='a'&&i<len)
{
   count++;
   i++;  
}  
while(str[i]=='b'&&i<len)
{
   count--;
   i++;
}
if(count==0)
   return true;
return false;
}
int main()
{
   string pat = "aaaaaabbbbbb";
   ifstream in("input.txt");
   ofstream out("output.txt");
   if(IsPattern(pat))
   {
       cout<<"String : "<<pat<< " is a^nb^n pattern\n";
   }
   else
   {
           cout<<"String : "<<pat<< " is not a^nb^n pattern\n";  
   }
   ReverseContent(in,out);
   cout<<"TEXT WRITTEN TO FILE IN REVERSE ORDER\n";
   return 0;
}
