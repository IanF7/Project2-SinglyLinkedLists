#ifndef SLL_H
#define SLL_H

#include <iostream>

using namespace std;

class SLL
{
	private:
		int listCount = 0;
	public:
		SLL();
		struct node
		{
			int data;
			struct node* next;
		};
		struct node* head = NULL;
		int size();
		void setListCount(int listCount);
		int getItem(int pos);
		int front();
		int back();
		void insert(int val);
		void pop_front();
		void pop_back();
		bool empty();
		void reverse();
		void merge(SLL listB);
		void display();
		void insertFront(int newData);
};

#endif
