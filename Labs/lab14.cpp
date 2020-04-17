#include <iostream>
#include <string>



using namespace std;

string ToTernary(int n){

if (n>=0) {

int x=0, power = 1;

while(n>2){
x = (power*(n%3)) + x;
n = n/3;
power *= 10;
}
x = power*n + x;
return to_string(x);
}

else
return "0";
}

int main(){
int x;
cout<<"Enter decimal number: "; cin >> x;
cout << "Function ToTernary() returns " << ToTernary(x) << endl;
return 0;
}