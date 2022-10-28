#include <iostream>
#include <vector>
#include "SLL.h"

using namespace std;

//default constructor
SLL::SLL()
{
	this->listCount = listCount;
}

//getter for listCount
int SLL::size()
{
	return listCount;
}

//setter for listCount
void SLL::setListCount(int listCount)
{
	this->listCount = listCount;
}

//getItem method that returns an int and takes an int [O(n)]
int SLL::getItem(int pos)
{
	//creates a node pointer temp and sets it equal to head
	struct node* temp = head;
	//sets temp equal to the next value until loop reaches pos
	for (int i = 1; i < pos; i++)
	{
		temp = temp->next;
	}
	//returns the value of temp
	return int(temp->data);
}

//front method that returns an int [O(1)]
int SLL::front()
{
	//creates a node pointer temp and sets it equal to head
	struct node* temp = head;
	//returns value of temp
	return int(temp->data);
}

//back method that returns an int [O(n)]
int SLL::back()
{
	//creates a node pointer temp and sets it equal to head
	struct node* temp = head;
	//sets temp equal to the next value until the next value of temp is null
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	//returns value of temp
	return int(temp->data);
}

//pop_front method [O(1)]
void SLL::pop_front()
{
	//creates node pointer temp and sets it equal to head
	struct node* temp = head;
	//sets head equal to the temp pointer to next
	head = temp->next;
	//deletes temp
	delete temp;
	//lowers listCount by 1
	setListCount(size() - 1);
}

//pop_back method [O(n)]
void SLL::pop_back()
{
	//creates node pointer temp and sets it equal to head
	struct node* temp = head;
	//creates new node pointer previous
	struct node* previous = new node;
	//runs while temp is not null
	while (temp->next != NULL)
	{
		//sets previous equal to temp and then temp equal to the next value
		previous = temp;
		temp = temp->next;
	}
	//deletes temp
	delete(temp);
	//sets the pointer to NULL to close list
	previous->next = NULL;
	//lowers listCount by 1
	setListCount(size() - 1);
}

//insert method that returns void and takes an int [O(1)] or [O(n)]
void SLL::insert(int val)
{
	//creates node pointer newNode
	struct node* newNode = new node;
	//creates node pointer temp and sets it equal to head
	struct node* temp = head;
	//sets newNode's value to val
	newNode->data = val;
	//creates bool insert and sets it to false to control if statement
	bool insert = false;
	//checks if the list is empty or the value of node is less than the value of temp
	if (empty() || newNode->data < temp->data )
	{
		//runs insertFront method given val
		insertFront(val);
	}
	//if empty returns false, runs while loop until the next value of temp is NULL
	else if (!empty())
	{
		while (temp->next != NULL)
		{
			//checks if the value of newNode is less than the next value of temp
			if (newNode->data < temp->next->data)
			{
				//sets newNode pointer equal to temp pointer
				newNode->next = temp->next;
				//sets temp eqaul to newNode
				temp->next = newNode;
				//changes insert to true and break loop
				insert = true;
				break;
			}
			//sets temp equal to temp->next
			temp = temp->next;
		}
		//checks if insert is false and if so sets temp->next to newNode
		if (!insert)
		{
			newNode->next = temp->next;
			temp->next = newNode;
		}
		//adds 1 to listCount
		setListCount(size() + 1);
	}
}

//display method (O[n])
void SLL::display()
{
	//creates node pointer temp and sets it equal to head
	struct node* temp = head;
	//runs while temp isn't NULL
	while (temp != NULL)
	{
		//prints out the value of temp and updates temp to the next value
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "" << endl;
}

//empty method that returns bool [O(1)]
bool SLL::empty()
{
	//creates bool emptyList and sets it equal to false
	bool emptyList = false;
	//creates node pointer temp and sets it equal to head
	struct node* temp = head;
	//checks if temp is NULL and if so sets emptyList to true
	if (temp == NULL)
	{
		emptyList = true;
	}
	//returns emptyList
	return emptyList;
}

//reverse function [O(n + m)]
void SLL::reverse()
{
	//creates node pointer newNode
	struct node* newNode = new node;
	//creates a vector of ints called backwards
	vector<int> backwards;
	//creates int initalSize and sets it equal to size
	int initialSize = size();
	//sets every value in the list as a value in backwards
	for (int i = 1; i <= size(); i++)
	{
		backwards.push_back(getItem(i));
	}
	//inserts every value of backwards back into the list
	for (int i = 0; i < backwards.size(); i++)
	{
		insertFront(backwards[i]);
	}
	//deletes all the values at the back half of the lsit
	for (int i = size(); i > initialSize; i--)
	{
		pop_back();
	}
}

//merge method that takes in a SLL object and returns void [O(n)]
void SLL::merge(SLL listB)
{
	//runs while i is less than the size of listB and inserts all values into the original list
	for (int i = 1; i <= listB.size(); i++)
	{
		insert(listB.getItem(i));
	}
}

//insertFront function that takes in an int and returns void
void SLL::insertFront(int newData)
{
	//creates a node pointer newNode
	struct node* newNode = new node;
	//sets the value and address of newNode to newData and head respectively
	newNode->data = newData;
	newNode->next = head;
	//sets head equal to newNode
	head = newNode;
	//adds 1 to listCount
	setListCount(size() + 1);
}



