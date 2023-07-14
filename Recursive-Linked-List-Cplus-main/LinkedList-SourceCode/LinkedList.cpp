#include "LinkedList.h"
#include<iostream>
#include<string>
using namespace std;

bool LinkedList::add(string value)
{
	Node* newNode = new Node;
	Node* curr = headptr;
	newNode->data = value;
	newNode->next = NULL;

	if(curr == NULL)
	{
		headptr = newNode;
		size1 = size1 + 1;
		return true;
	}
	else
	{
		while(curr -> next != NULL)
		{
			curr = curr -> next;
		}
		curr -> next = newNode;
		size1 = size1 + 1;
		return true;
	}
	return false;
}

int LinkedList::size()
{
	return size1;
}

bool LinkedList::isEmpty()
{
	if (size1 == 0 && headptr == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string LinkedList::get(int atIndex)
{
	int currIndex=0;
	Node* curr = headptr;

	while ((curr != NULL) && (currIndex < atIndex))
	{
		curr = curr->next;
		currIndex = currIndex+1;
	}
	if((curr != NULL) && (currIndex == atIndex))
	{
		return curr->data;
	}
	else
	{
		return "";
	}
}

bool LinkedList::insert(string value, int atIndex)
{

	Node* add = new Node;
	add->data = value;
	Node* curr = headptr;
	Node* before = curr;
	int presentIndex = 0;
	if ((headptr == NULL) && (atIndex == 0))
	{
		headptr = add;
		add->next = NULL;
		size1 = size1 + 1;
		return true;
	}
	else if ((headptr != NULL) && (atIndex == 0))
	{
		add->next = curr;
		headptr = add;
		size1 = size1 + 1;
		return true;
	}
	else if ((headptr->next == NULL) && (atIndex == 1))
	{
		headptr->next = add;
		add->next = NULL;
		size1 = size1 + 1;
		return true;
	}
	else if ((headptr->next == NULL) && (atIndex == 0))
	{
		add->next = curr;
		headptr = add;
		size1 = size1 + 1;
		return true;
	}
	else if (headptr->next != NULL)
	{
		while ((curr != NULL) && (presentIndex<atIndex))
		{
			before = curr;
			curr = curr->next;
			presentIndex = presentIndex + 1;
		}

		if ((before != NULL) && (atIndex == presentIndex))
		{
			before->next = add;
			add->next = curr;
			size1 = size1 + 1;
			return true;
		}

		else
		{
			return false;;
		}
	}

	else
	{
		return false;
	}
}

string LinkedList::remove(int atIndex)
{
	Node *curr = headptr;
	string save;
	int currIndex = -1;

	if (atIndex < 0 || atIndex > size1 - 1)
	{
		return "";
	}

	if (atIndex == 0)
	{
		save = curr->data;
		headptr = headptr->next;
		delete curr;
		size1 = size1 - 1;
		return save;
	}

	while (curr != NULL)
	{
		currIndex = currIndex + 1;

		if (currIndex == atIndex - 1)
		{
			save = curr->next->data;
			delete curr->next;
			curr->next = curr->next->next;
			size1 = size1 - 1;
			return save;
		}
		else
		{
			curr = curr->next;
		}
	}
	return "";
}

void LinkedList::clear()
{
	headptr = NULL;
	size1=0;
}

string LinkedList::set(int atIndex, string value)
{
	string old;
	int currentIndex = 0;
	Node* curr = headptr;
	while ((curr != NULL) && (currentIndex < atIndex))
	{
		curr = curr->next;
		currentIndex = currentIndex + 1;
	}
	if ((curr != NULL) && (currentIndex == atIndex))
	{
		old=curr->data;

		curr->data = value;
		return old;
	}
	return "";
}

bool LinkedList::contains(string value)
{
	Node* curr = headptr;

	while (curr != NULL)
	{
		if (curr->data == value)
		{
			return true;
		}
		curr = curr->next;
	}
	return false;
}

bool LinkedList::remove(string value)
{
	Node* curr = headptr;
	Node* prev = NULL;
	while ((curr != NULL) && (curr->data != value))
	{
		prev = curr;
		curr = curr->next;
	}
	if ((prev == NULL) && (curr != NULL))
	{
		headptr = headptr->next;
		delete curr;
		curr = NULL;
		size1 = size1 - 1;
		return true;
	}
	else if (curr != NULL)
	{
		prev->next = curr->next;
		delete curr;
		curr = NULL;
		size1 = size1 - 1;
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedList::indexOf(string value)
{
	Node* curr = headptr;
	if(headptr == NULL)
	{
		return -1;
	}
	else
	{
		for(int i=0; i<size1; i++)
		{
			if(curr->data == value)
			{
				return i;
			}
			curr=curr->next;
		}

	}
	return -1;
}

int LinkedList::lastIndexOf(string value)
{
	Node *curr = headptr;
	int storage = -1;
	for(int i=0; i<size1; i++)
	{
		if (curr->data == value)
		{
			storage = i;
		}
		curr=curr->next;
	}
	return storage;

}
