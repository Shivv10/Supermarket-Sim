#include "OneWaitLineSimulation.h"

//
//Constructor
//
OneWaitLineSimulation::OneWaitLineSimulation() : Simulation()
{
	waitLine = new Queue;
	inLane1 = NULL;
	inLane2 = NULL;
}

//Destructor
OneWaitLineSimulation::~OneWaitLineSimulation()
{
	delete waitLine;
}

//
//Accessors
//
string OneWaitLineSimulation::getLane(Customer* c)
{
	if(inLane1 == c)
		return "1st";
	else if(inLane2 == c)
		return "2nd";
	cout<<"Error: Customer not found in any lane"<<endl;
	return NULL;
}

//
//Mutators
//
bool OneWaitLineSimulation::enqueueWaitLine(Customer* c)
{
	if(inLane1 == NULL)  //service immediately in lane 1
	{
		inLane1 = c;
		return true;
	}
	else if(inLane2 == NULL)  //service immediately in lane 2
	{
		inLane2 = c;
		return true;
	}
	else
		waitLine->enqueue(c);  //enqueue in the wait line otherwise
	return false;
}

//To dequeue a customer in the appropriate waiting line --> to be defined in subclasses
//should be called when processing a complete eventPQ, will return the next customer in line or NULL
Customer* OneWaitLineSimulation::dequeueWaitLine(Customer* c)
{
	if(inLane1 == c)  //c was in lane 1
	{
		delete inLane1;
		inLane1 = dynamic_cast<Customer*>(waitLine->dequeue());  //dequeue will return NULL if no one is waiting in line
		return inLane1;
	}
	else if(inLane2 == c)  //c was in lane 2
	{
		delete inLane2;
		inLane2 = dynamic_cast<Customer*>(waitLine->dequeue());  //dequeue will return NULL if no one is waiting in line
		return inLane2;
	}
	else
		cout<<"Problem: customer not in any lane"<<endl;
	return NULL;
}