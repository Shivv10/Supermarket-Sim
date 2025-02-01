#ifndef QUEUE_H_
#define QUEUE_H_

#include "Node.h"

using namespace std;

class Queue
{
	private:
		Node* first;
		Node* last;
	
	public:
		//Constructor
		Queue();
		
		//Destructor
		virtual ~Queue();
		
		//
		//Accessors
		//
		void print();
		bool isEmpty();
		Node* getFirstNode();
		Node* getLastNode();
		ListItem* getFirst(); //Returns the first ListItem in Queue, without dequeuing
		
		//
		//Mutators
		//
		void setFirstNode(Node* n);
		void setLastNode(Node* n);
		virtual void enqueue(Node* n);
		virtual void enqueue(ListItem* li);
		ListItem* dequeue(); 
		
};

#endif
