#include<iostream>
#include<vector>

using namespace std;
class Point{
   public:
       double x,y;
};
bool IsLine(vector<Point>& coors){
   if(coors.size() == 1)return true;
  
   double slope = (coors[1].y - coors[0].y)/(coors[1].x - coors[0].x);
   double currentSlope;
   for(int i=0;i<coors.size()-1;i++){
       for(int j=i+1;j<coors.size();j++){
           currentSlope = (coors[i].y - coors[j].y)/(coors[i].x - coors[j].x);
           if(currentSlope!=slope)return false;
       }
   }
   return true;
}
template <typename T>
Node<T>* MiddleNode(Node<T>* root){
   if(root==NULL || root->next == NULL)return NULL;
   Node<T> *slowPtr = root;
Node<T> *fastPtr = root;
  
while (fastPtr != NULL && fastPtr->next != NULL)
{
fastPtr = fastPtr->next->next;
slowPtr = slowPtr->next;
}
  
return slowPtr;
  
}