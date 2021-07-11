#include "DoubleLinkedList.h"
#include <iostream>
#include "raylib.h"
using namespace std;

CDDS::DoubleLinkedList::DoubleLinkedList()
{

}

CDDS::DoubleLinkedList::~DoubleLinkedList()
{
	// Free allocated memory
	clear();
}

void CDDS::DoubleLinkedList::pushFront(int newData)	
{
	Node* node = new Node(newData, head);

	if (head != nullptr)
	{
		head->prev = node;
	}

	head = node;

	if (tail == nullptr)
	{
		tail = node;
	}
}

void CDDS::DoubleLinkedList::pushBack(int newData)
{
	Node* node = new Node(newData, nullptr, tail);

	if (tail != nullptr)
	{
		tail->next = node;
	}

	tail = node;

	if (head == nullptr)
	{
		head = node;
	}
}

void CDDS::DoubleLinkedList::insert(Node* _node, int newData)
{
	Node* node = new Node(newData);

	node->data = newData;
	node->next = node;

	if (_node != nullptr)
	{
		node->prev = _node->prev;
		
		if (_node->prev != nullptr)
		{
			_node->prev->next = node;
			_node->prev = node;
		}
	}
	
	if (head = _node)
	{
		head = node;
	}

	if (tail == nullptr)
	{
		tail = node;
	}
}

bool CDDS::DoubleLinkedList::isEmpty() const
{
	return (head == nullptr) && (tail == nullptr);
}

unsigned int CDDS::DoubleLinkedList::count() const
{
	unsigned int counter = 0;

	Node* node = head;
	while (node != nullptr)
	{
		counter++;
		node = node->next;
	}
	return counter;
}

int& CDDS::DoubleLinkedList::first() const
{
	if (isEmpty())
	{
		throw std::exception("List is empty");
	}

	return head->data;
}

int& CDDS::DoubleLinkedList::last() const
{
	if (isEmpty())
	{
		throw std::exception("List is empty");
	}

	return tail->data;
}

void CDDS::DoubleLinkedList::clear()
{
	Node* node = head;
	Node* nextNode;

	while (node != nullptr)
	{
		nextNode = node->next;
		delete node;

		node = nextNode;
	}

	head = tail = nullptr;
}

