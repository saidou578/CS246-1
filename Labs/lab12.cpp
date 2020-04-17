#include<bits/stdc++.h>
using namespace std;

template <typename T> set<T> Intersection(const set<T>& A, const set<T>& B){
   set<T> C;
   
   for(auto it:A){
       if(B.find(it)!=B.end())
           C.insert(it);
   }
   return(C);
}

template <typename T> set<T> Union(const set<T>& A, const set<T>& B){
   set<T> C;
   
   for(auto it:A){
       C.insert(it);
   }
   for(auto it:B){
       C.insert(it);
   }
   return(C);
}
int main() {
  
   set<int> A={2,3,4,5};
   set<int> B={3,4,6,7};
   
   set<int> C=Intersection(A,B);
   cout<<"Intersection set- ";
   for(auto it:C)
       cout<<(it)<<" ";
   cout<<"\n";
   cout<<"Union set- ";
   set<int> D=Union(A,B);
   for(auto it:D)
       cout<<(it)<<" ";
   cout<<"\n";
return 0;
}