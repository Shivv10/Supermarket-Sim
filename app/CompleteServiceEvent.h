#ifndef COMPLETESERVICEEVENT_H_
#define COMPLETESERVICEEVENT_H_

// #include "StartServiceEvent.h"
#include "Event.h"
#include "Simulation.h"

class StartServiceEvent;

class CompleteServiceEvent : public Event
{
	private:
		string lane;
	public:
		
		//Constructor
		CompleteServiceEvent(int time, Customer* customer, string lane);
		
		//
		//Accessors
		//
		virtual void print();
		
		//
		//Mutators
		//
		virtual void processEvent(Simulation* sim);
};

#endif