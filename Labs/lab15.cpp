#include <iostream>

#include <string>

#include <iostream>

#include <string>

using namespace std;

class MyStack

{

private:

int *stackArray;

int stackSize;

int top;

public:

MyStack(int);

MyStack(const MyStack &);

~MyStack();

void Push(int);

void Pop(int &);

bool isEmpty() const;

bool isFull() const;

int Top();

};

MyStack::MyStack(int size)

{

stackArray = new int[size];

stackSize = size;

top = -1;

}

MyStack::~MyStack()

{

delete [] stackArray;

}

void MyStack::Push(int val)

{

if (isFull())

{

cout << "The stack is full.\n";

}

else

{

top++;

stackArray[top] = val;

}

}

void MyStack::Pop(int &val)

{

if (isEmpty())

{

cout << "The stack is empty.\n";

}

else

{

val = stackArray[top];

top--;

}

}

bool MyStack::isFull() const

{

bool status;

if (top == stackSize - 1)

status = true;

else

status = false;

return status;

}

bool MyStack::isEmpty() const

{

bool status;

if (top == -1)

status = true;

else

status = false;

return status;

}

int MyStack:: Top()

{

return top;

}

int main()

{

MyStack stack(10);

stack.Push(10);

stack.Push(20);

stack.Push(30);

stack.Push(40);

int val;

stack.Pop(val);

cout<<"Popped value: "<<val<<endl;

stack.Pop(val);

cout<<"Popped value: "<<val<<endl;

return 0;

}