#ifndef ARRIVALEVENT_H_
#define ARRIVALEVENT_H_

#include "Event.h"
#include "Simulation.h"
#include "StartServiceEvent.h"

class ArrivalEvent : public Event
{
	public:
		
		//Constructor
		ArrivalEvent(int time, Customer* customer);
		
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