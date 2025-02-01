#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Queue.h"
#include "OrderedItem.h"

class PriorityQueue : public Queue
{
	public:
		//Constructors
		PriorityQueue();
		virtual void enqueue(ListItem* li);
		
		//Destructor
		virtual ~PriorityQueue();
};

#endif
