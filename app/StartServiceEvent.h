#ifndef STARTSERVICEEVENT_H_
#define STARTSERVICEEVENT_H_

using namespace std;

#include "CompleteServiceEvent.h"
#include "Simulation.h"

class StartServiceEvent : public Event
{
	private:
		string lane;
	public:
		
		//Constructor
		StartServiceEvent(int time, Customer* customer, string lane);
		
		//
		//Accessors
		//
		virtual void print();
		string getLane();
		
		//
		//Mutators
		//
		virtual void processEvent(Simulation* sim);
};

#endif