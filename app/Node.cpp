#include "Node.h"

//
//Constructors
//
Node::Node()
{
	item = NULL;
	next = NULL;
}

Node::Node(ListItem* li)
{
	item = li;
	next = NULL;
}

Node::Node(ListItem* li, Node* n)
{
	item = li;
	next = n;
}

//
//Accessors
//
ListItem* Node::getItem()
{
	return item;
}

Node* Node::getNext()
{
	return next;
}

void Node::print()
{
	item->print();
	if(next != NULL)
		next->print();
}

//
//Mutators
//
void Node::setNext(Node* n)
{
	next = n;
}