#include<iostream>
using namespace std;
#define MAX_size 10

class Deque

{
    int  array[MAX_size];

    int  front;

    int  rear;

    int  size;

public :
    Deque(int size)

    {
        front = -1;

        rear = 0;

        this->size = size;

    }

void  InsertFirst(int key);

void  InsertLast(int key);

void  RemoveFirst();

void  RemoveLast();

void  display();   

bool  isEmpty(){
    return (front == -1);  
}
};
void Deque::InsertFirst(int key)
{
 if (front==0 ) {
cout << "Overflow!!\n" << endl;
return;
}
if (front == -1)
{
 front = 0;
 rear = 0;
}
else 
front = front-1;
array[front] = key ;
}

void Deque ::InsertLast(int key)

{
 if (rear == size-1) {  
cout << " Overflow!!\n " << endl;
 return;
}
if (front == -1) {
front = 0;
rear = 0;
}
else        
rear = rear+1;
array[rear] = key ;
}
void Deque ::RemoveFirst()
{
if (isEmpty())
{
cout << "Queue Underflow!!\n" << endl;
return ;
}
if (front == rear)
{
front = -1;
rear = -1;
 }
else
front = front+1;
}
void Deque::RemoveLast()
{

    if (isEmpty())

    {

        cout << " Underflow!!\n" << endl ;

        return ;

    }

    if (front == rear)

    {

        front = -1;

        rear = -1;

    }

    else

        rear = rear-1;

}
void Deque::display()
{
if (isEmpty())
 {
cout << " Underflow!!\n" << endl ;
return ;
}
cout<<"Queue elements are : ";
for(int i=front;i<=rear;i++)
{
cout<<array[i]<<" ";
 }
cout<<endl;
}

int main()

{
Deque dq(5);
dq.InsertLast(1);
dq.InsertLast(3);
dq.display();
dq.RemoveLast();
dq.display();
dq.InsertLast(5);
dq.display();
dq.RemoveFirst();
dq.InsertFirst(19);
dq.InsertLast(10);
dq.RemoveFirst();
dq.InsertFirst(20);
dq.display();
return 0;

}