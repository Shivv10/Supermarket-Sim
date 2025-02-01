#include "ExpressSimulation.h"

//
//Constructor
//
ExpressSimulation::ExpressSimulation() : Simulation()
{
	expressQ = new Queue();
	regularQ = new Queue();
}

//Destructor
ExpressSimulation::~ExpressSimulation()
{
	delete expressQ;
	delete regularQ;
}

//
//Accessors
//

//We should only call this when the customer is first in line (either in express or regular)
string ExpressSimulation::getLane(Customer* c)
{
	if(expressQ->getFirst() == c)
		return "Express";
	else if(regularQ->getFirst() == c)
		return "Regular";
	cout<<"Big problem: customer not found in Queues"<<endl;
	return NULL;
}

//
//Mutators
//
bool ExpressSimulation::enqueueWaitLine(Customer* c)
{
	bool firstInLine = false;
	if(c->isExpress()) //goes to express waiting line
	{
		if(expressQ->isEmpty())
			firstInLine = true;
		expressQ->enqueue(c);
	}
	else
	{
		if(regularQ->isEmpty())
			firstInLine = true;
		regularQ->enqueue(c);
	}
	
	return firstInLine;
}

//To dequeue a customer in the appropriate waiting line --> to be defined in subclasses
//should be called when processing a complete eventPQ, will return the next customer in line or NULL
Customer* ExpressSimulation::dequeueWaitLine(Customer* c)
{
	//first we need to find the lane
	string lane = getLane(c);
	Customer* next = NULL;
	
	if(lane == "Express")
	{
		delete expressQ->dequeue();
		next = dynamic_cast<Customer*>(expressQ->getFirst());
	}
	else if(lane == "Regular")
	{
		delete regularQ->dequeue();
		next = dynamic_cast<Customer*>(regularQ->getFirst());
	}
	else
		cout<<"Problem: customer not in any lane"<<endl;
	
	return next;
}
