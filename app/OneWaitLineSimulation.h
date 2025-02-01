#ifndef ONEWAITLINESIMULATION_H_
#define ONEWAITLINESIMULATION_H_

#include <iostream>

#include "Simulation.h"
#include "Queue.h"

using namespace std;

class OneWaitLineSimulation : public Simulation
{
	private:
		Queue* waitLine;  //only one wait line
		Customer* inLane1; //current customer serviced in lane 1
		Customer* inLane2; //current customer serviced in lane 2
		
	public:
		//
		//Constructor
		//
		OneWaitLineSimulation();
		
		//Destructor
		virtual ~OneWaitLineSimulation();
		
		//
		//Accessors
		//
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