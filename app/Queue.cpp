#include "Queue.h"

//Constructor
Queue::Queue()
{
	first = NULL;
	last = NULL;
}

//Destructor
Queue::~Queue(){}

//
//Accessors
//
void Queue::print()
{
	if(first != NULL)
		first -> print();
}

bool Queue::isEmpty()
{
	if(first == NULL)
		return true;
	return false;
}

Node* Queue::getFirstNode()
{
	return first;
}

Node* Queue::getLastNode()
{
	return last;
}

//Returns the first ListItem in Queue, without dequeuing
ListItem* Queue::getFirst()
{
	if(first == NULL)
		return NULL;
	return first->getItem();
}

//
//Mutators
//

void Queue::setFirstNode(Node* n)
{
	first = n;
}

void Queue::setLastNode(Node* n)
{
	last = n;
}

void Queue::enqueue(Node* n)
{
	//Queue is empty
	if(last == NULL)
	{
		first = n;
		last = n;
	}
	else
	{
		last -> setNext(n);
		last = n;
	}
}

//enqueue operation (adds at the end of the queue)
void Queue::enqueue(ListItem* li)
{
	Node* newNode = new Node(li);
	enqueue(newNode);  //Calling other version of enqueue
}

//dequeue removes the first node and returns the ListItem that was contained in that node
ListItem* Queue::dequeue()
{
	if(first == NULL)
		return NULL;
	
	ListItem* theItem = first -> getItem();
	Node* temp = first;
	first = first -> getNext();
	delete temp;
	
	if(first == NULL) //we removed the last node
		last = NULL;
		
	return theItem;
}
