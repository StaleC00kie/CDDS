#pragma once
#include <iostream>

namespace CDDS 
{
	class DoubleLinkedList
	{
	private:

		struct Node
		{
			Node(const int& _data, Node* _next = nullptr, Node* _prev = nullptr)
			{
				data = _data;
				next = _next;
				prev = _prev;
			}

			int data;
			struct Node* next{ nullptr };
			struct Node* prev{ nullptr };
		};

		class Iterator
		{
		public:

			bool IsValid()
			{
				return node != nullptr;
			}

			int GetCurrent()
			{
				return node->data;
			}

		private:
			Node* node = nullptr;
		};

		public:

			DoubleLinkedList();
			~DoubleLinkedList();

			// Add data to the front of the list
			void pushFront(int newData);
			// Add data to the end of the list
			void pushBack(int newData);
			void insert(Node* node, int newData);
			// Check if list is empty
			bool isEmpty() const;
			// Get the number of nodes in the list
			unsigned int count() const;

			// Get the data at the head of the list
			int& first() const;

			// Get the data at the tail of the list
			int& last() const;

			// Free all memory in the list and reset
			void clear();

			void Draw();
			void Update();




	private:
		Node* head = nullptr;
		Node* tail = nullptr;

	};



}


