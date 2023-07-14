#include "RecursiveLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

bool RecursiveLinkedList::add(string value)
{
	Node *addNode = new Node;
	addNode->value = value;
	addNode->next = NULL;

	if (curr == NULL)
	{
		curr = addNode;
		last = addNode;
		size1=size1+1;
	}
	else
	{
		last->next = addNode;
		last = addNode;
		size1=size1+1;
	}
	return true;
}

int RecursiveLinkedList::size()
{
	return size1;
}

bool RecursiveLinkedList::isEmpty()
{
	if(size1 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string RecursiveLinkedList::get(int atIndex)
{
	if ((atIndex > size1-1) || (atIndex<0))
	{
		return "";
	}

	return this->getHelper(atIndex, curr);
}

string RecursiveLinkedList::getHelper(int atIndex, RecursiveLinkedList::Node *node)
{
	if (atIndex == 0)
	{
		return node->value;
	}

	else
	{
		return this->getHelper(atIndex-1, node->next);
	}
}

bool RecursiveLinkedList::insert(string value, int atIndex)
{
	if ((atIndex > size1-1) || (atIndex<0))
	{
		return false;
	}

	if (atIndex == 0)
	{
		Node *addVal = new Node;
		addVal->value = value;
		addVal->next = curr;
		curr = addVal;
		size1=size1+1;
		return true;
	}

	return this->insertHelper(value, atIndex - 1, curr);
}

bool RecursiveLinkedList::insertHelper(string value, int atIndex, RecursiveLinkedList::Node *node)
{
	if (atIndex == 0)
	{
		Node *insertNode = new Node;
		insertNode->value = value;
		insertNode->next = node->next;
		node->next = insertNode;
		size1 = size1+1;
		return true;
	}
	else
	{
		return this->insertHelper(value, atIndex - 1, node->next);
	}
}

string RecursiveLinkedList::remove(int atIndex)
{
	Node *temporarycurr = curr;
	string storage;

	if ((atIndex > size1-1) || (atIndex < 0))
	{
		return "";
	}

	if (atIndex == 0)
	{
		storage = temporarycurr->value;
		curr = curr->next;
		delete temporarycurr;
		size1 = size1-1;

		if (curr == NULL)
		{
			last = NULL;
		}
		return storage;
	}
	return this->removeHelper(atIndex - 1, curr);
}

string RecursiveLinkedList::removeHelper(int atIndex, RecursiveLinkedList::Node *node)
{
	string storage;
	if (atIndex == 0)
	{
		storage = node->next->value;
		delete node->next;
		node->next = node->next->next;
		size1 = size1-1;

		if (node->next == NULL)
		{
			last = node;
		}
		return storage;
	}

	else
	{
		return this->removeHelper(atIndex-1, node->next);
	}
}

void RecursiveLinkedList::clear()
{
	size1 = 0;
	curr = NULL;
}

string RecursiveLinkedList::set(int atIndex, string value)
{
	if ((atIndex > size1-1) || (atIndex < 0))
	{
		return "";
	}
	else
	{
		return this->setHelper(atIndex, value, curr);
	}
}

string RecursiveLinkedList::setHelper(int atIndex, string value, RecursiveLinkedList::Node *node)
{
	string save;
	if (atIndex == 0)
	{
		save = node->value;
		node->value = value;
		return save;
	}
	else
	{
		return setHelper(atIndex - 1, value, node->next);
	}
}

bool RecursiveLinkedList::contains(string value)
{
	return containsHelper(value, curr);
}

bool RecursiveLinkedList::containsHelper(string value, RecursiveLinkedList::Node *node)
{
	if (node == NULL)
	{
		return false;
	}

	else
	{
		if (node->value == value)
		{
			return true;
		}
		else
		{
			node = node->next;
			return this->containsHelper(value, node);
		}
	}
}

bool RecursiveLinkedList::remove(string value)
{
	Node *temporarycurr = curr;
	string storage;

	if (temporarycurr == NULL)
	{
		return false;
	}

	if (temporarycurr->value == value)
	{
		curr = curr->next;
		delete temporarycurr;
		size1 = size1-1;

		if (curr == NULL)
		{
			last = NULL;
		}
		return true;
	}
	return this->removeHelper(value, curr);
}

bool RecursiveLinkedList::removeHelper(string value, RecursiveLinkedList::Node *node)
{
	if (node == NULL)
	{
		return false;
	}

	if ((node->next != NULL) && (node->next->value == value))
	{
		delete node->next;
		node->next = node->next->next;
		size1 = size1-1;

		if (node->next == NULL)
		{
			last = node;
		}
		return true;
	}
	return this->removeHelper(value, node->next);
}

int RecursiveLinkedList::indexOf(string value)
{
	return this->indexOfHelper(value, curr, -1);
}

int RecursiveLinkedList::indexOfHelper(string value, RecursiveLinkedList::Node *node, int size1)
{
	if (node == NULL)
	{
		return -1;
	}
	else
	{
		size1 = size1+1;

		if (node->value == value)
		{
			return size1;
		}
		else
		{
			node = node->next;
			return this->indexOfHelper(value, node, size1);
		}
	}
}

int RecursiveLinkedList::lastIndexOf(string value)
{
	return this->lastIndexOfHelper(value, curr, -1, -1);
}

int RecursiveLinkedList::lastIndexOfHelper(string value, RecursiveLinkedList::Node *node, int size1, int lastNode)
{
	if (node == NULL)
	{
		return lastNode;
	}
	else
	{
		size1 = size1+1;
		if (node->value == value)
		{
			lastNode = size1;
		}
		node = node->next;
		return this->lastIndexOfHelper(value, node, size1, lastNode);
	}
}
