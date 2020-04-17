#include<iostream>
using namespace std;

template <class T>
struct Node{
   T data;
   struct Node* next;
   struct Node* prev;
};


template <class T>
void ReverseTraverse(Node<T>* root){
   if(root == NULL)return;
   ReverseTraverse(root->next);
   cout<<root->data<<" ";
}

template <class T>
void sortedHepler(Node<T>* head, Node<T>* newNode)
{
Node<T>* current;
if (*head == NULL) *head = newNode;
  
else if ((*head)->data >= newNode->data) {
newNode->next = *head;
newNode->next->prev = newNode;
*head = newNode;
}
  
else {
current = *head;
while (current->next != NULL &&current->next->data < newNode->data)
current = current->next;

newNode->next = current->next;
if (current->next != NULL) newNode->next->prev = newNode;
  
current->next = newNode;
newNode->prev = current;
}
}

template <class T>
void InsertionSort(Node<T>* root){
   Node<T>* sorted = NULL;
Node<T>* current = root;
while (current != NULL) {
Node<T>* next = current->next;
current->prev = NULL;
       current->next = NULL;
sortedHepler(&sorted, current);
current = next;
}

root = sorted;
}