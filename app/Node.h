#ifndef NODE_H_
#define NODE_H_

#include "ListItem.h"

//Interface
class Node
{
	private:
		ListItem* item;
		Node* next;
	
	public:
	
		//
		//Constructors
		//
		Node();
		Node(ListItem* li);
		Node(ListItem* li, Node* n);
		
		//
		//Accessors
		//
		ListItem* getItem();
		Node* getNext();
		void print();
		
		//
		//Mutators
		//
		void setNext(Node* n);
};

#endif