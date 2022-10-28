/*
Ian Fletcher
CST-201
9/24/2022
Singly-Linked List Project
This is my own work combined with some code from the slides from class
*/
#include <iostream>
#include "SLL.h"

using namespace std;

int main()
{
	//creates new SLL object myList
	SLL myList;
	//fills the list using insert
	myList.insert(1);
	myList.insert(5);
	myList.insert(4);
	myList.insert(10);
	myList.insert(2);
	myList.insert(11);
	//displays first and last value in list
	cout << "front: " << myList.front() << endl;
	cout << "back: " << myList.back() << endl;
	//displays lsit
	cout << "myList: ";
	myList.display();
	//deletes the front value and shows the new list
	myList.pop_front();
	cout << "pop_front: ";
	myList.display();
	//deletes the last value and shows the new list
	myList.pop_back();
	cout << "pop_back: ";
	myList.display();
	//creates new SLL object listB and populates it
	SLL listB;
	listB.insert(20);
	listB.insert(2);
	listB.insert(14);
	listB.insert(9);
	listB.insert(4);
	//displays listB
	cout << "listB: ";
	listB.display();
	//merges the two lists and displays the result
	cout << "Merge: ";
	myList.merge(listB);
	myList.display();
	//reverses the order of the list and displays results
	myList.reverse();
	cout << "Reverse: ";
	myList.display();
}