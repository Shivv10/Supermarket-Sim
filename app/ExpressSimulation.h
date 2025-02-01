#ifndef EXPRESSSIMULATION_H_
#define EXPRESSSIMULATION_H_

#include <iostream>

#include "Simulation.h"
#include "Queue.h"

using namespace std;

class ExpressSimulation : public Simulation
{
	private:
		Queue* expressQ;
		Queue* regularQ;
		
	public:
		//
		//Constructor
		//
		ExpressSimulation();
		
		//Destructor
		virtual ~ExpressSimulation();
		
		//
		//Accessors
		//
		// void printCurrentState();
		virtual string getLane(Customer* c);
		
		//
		//Mutators
		//
		virtual bool enqueueWaitLine(Customer* c);
		//To dequeue a customer in the appropriate waiting line --> to be defined in subclasses
		//should be called when processing a complete eventPQ, will return the next customer in line or NULL
		virtual Customer* dequeueWaitLine(Customer* c);
};

#endif