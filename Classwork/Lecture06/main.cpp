#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"

/***********************************************
 * Lecture 06: Linked Lists
 * Description: A linked list is a collection 
 * of linked nodes. This version of a linked
 * list uses a singly linked node
 **********************************************/

/***************************************
 * Standard Functions with Linked Lists
 ***************************************/

template<typename T>
void Traverse(ds::Node<T>* root)
{
	//Never Traverse the actual root
	ds::Node<T>* tmp = root;
	std::cout << "[";

	while(tmp != NULL)
	{
		std::cout << *tmp;

		if(tmp->GetLink() != NULL)
		{
			std::cout << ",";
		}
		tmp = tmp->GetLink();
	}
	std::cout << "]";
}

template<typename T>
void AppendToFront(ds::Node<T>*& root,const T& data)
{
	if(root == NULL)
	{
		root = new ds::Node<T>(data);
	}
	else
	{
		ds::Node<T>* tmp = new ds::Node<T>(data);
		tmp->SetLink(root);
	}
}

template<typename T>
void AppendToBack(ds::Node<T>*& root,const T& data)
{
	if(root == NULL)
	{
		root = new ds::Node<T>(data);
	}
	else
	{
		ds::Node<T>* tmp = root;

		while(tmp->GetLink() != NULL)
		{
			tmp = tmp->GetLink();
		}
		tmp->SetLink(new ds::Node<T>(data));
	}
}

template<typename T>
void RemoveFromFront(ds::Node<T>*& root)
{
	if(root != NULL)
	{
		ds::Node<T>* tmp = root;
		root = root->GetLink();
		delete tmp;
		tmp = NULL;
	}
}

template<typename T>
void RemoveFromBack(ds::Node<T>*& root)
{
	if(root != NULL)
	{
		if(root->GetLink() == NULL)
		{
			delete root;
			root = NULL;
			return;
		}
		ds::Node<T>* tmp = root;
		ds::Node<T>* prv = NULL;

		while(tmp->GetLink() != NULL)
		{
			prv = tmp;
			tmp = tmp->GetLink();
		}
		prv->SetLink(NULL);
		delete tmp;
		tmp = NULL;
	}
}

int main()
{
	srand(time(NULL));
	ds::Node<int>* value = NULL;

	for(int i = 0;i < 10;i += 1)
	{
		AppendToBack(value,(rand() % 24 + 5));
		Traverse(value);
		std::cout << "\n";
	}

	while(value->GetLink() != NULL)
	{
		RemoveFromBack(value);
		Traverse(value);
		std::cout << "\n";
	}

	ds::Clear(value);
	return 0;
}
