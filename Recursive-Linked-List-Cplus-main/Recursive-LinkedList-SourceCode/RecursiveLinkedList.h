#pragma once
#include "../SimpleList.h"

class RecursiveLinkedList : public SimpleList
{
public:
	int size();
	bool isEmpty();
	bool add(string value);
	bool insert(string value, int atIndex);
	string get(int atIndex);
	string remove(int atIndex);
	void clear();
	string set(int atIndex, string value);
	bool contains(string value);
	bool remove(string value);
	int indexOf(string value);
	int lastIndexOf(string value);

private:
	class Node
	{

	public:
		string value;
		Node* next;
	};

	int size1;
	Node* curr;
	Node* last;

	string getHelper(int atIndex, Node* node);
	bool insertHelper(string value, int atIndex, Node* node);
	string removeHelper(int atIndex, Node* node);
	string setHelper(int atIndex, string value, Node *node);
	bool containsHelper(string value, Node* node);
	bool removeHelper(string value, Node* node);
	int indexOfHelper(string value, Node* node, int cnt);
	int lastIndexOfHelper(string value, Node* node, int cnt, int lastNode);
};
