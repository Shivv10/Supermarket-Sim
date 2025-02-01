#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() : Queue(){};

void PriorityQueue::enqueue(ListItem* li)
{
	if(getFirstNode() == NULL)
	{
		this->Queue::enqueue(li); //calling super version if queue is empty
		return;
	}
	
	OrderedItem* oi = dynamic_cast<OrderedItem*>(li);
	if(!oi)
		cout<<"error with dynamic_cast"<<endl;
	else
	{
		Node* newNode = new Node(oi);
		OrderedItem* oiCurr = dynamic_cast<OrderedItem*>(getFirst());
		if(!oiCurr)
			cout<<"error with dynamic cast"<<endl;
		else if(oi->precedes(oiCurr)) //adding at beginning
		{
			newNode->setNext(getFirstNode());
			setFirstNode(newNode);
			return;
		}
		//Otherwise (if we don't add at the beginning)
		Node* previous = getFirstNode();
		Node* current = getFirstNode()->getNext();
		
		while(current)
		{
			oiCurr = dynamic_cast<OrderedItem*>(current->getItem());
			if(oiCurr == NULL)
				cout<<"error with dynamic cast"<<endl;
			else if	(oi->precedes(oiCurr))
			{
				previous->setNext(newNode);
				newNode->setNext(current);
				return;
			}
			previous = current;
			current = current->getNext();
		}
		//if we get here, need to insert at end, which is what the version from Queue does.
		this->Queue::enqueue(newNode);
	}
}

//Destructor
PriorityQueue::~PriorityQueue(){};
