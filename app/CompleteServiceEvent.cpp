#include "CompleteServiceEvent.h"

//Constructor
CompleteServiceEvent::CompleteServiceEvent(int time, Customer* customer, string lane) : Event(time, customer)
{ 
	this->lane = lane;
}

//
//Accessors
//
void CompleteServiceEvent::print()
{
	Event::print();
	cout<<" completes service in "<<lane<<" lane. ";
	getCustomer()->printTimes();
}

//
//Mutators
//
void CompleteServiceEvent::processEvent(Simulation* sim)
{
	//Display a summary of that customer
	print();
	
	Customer* next = sim->dequeueWaitLine(getCustomer());

	if(next)
	{
		StartServiceEvent* sse = new StartServiceEvent(getTime(), next, lane);  //same lane as the one of the completed customer
		sim->scheduleEvent(sse);
	}
}