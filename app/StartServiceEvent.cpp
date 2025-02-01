#include "StartServiceEvent.h"

//Constructor
StartServiceEvent::StartServiceEvent(int time, Customer* customer, string lane) : Event(time, customer)
{
	this->lane = lane;
}

//
//Accessors
//
void StartServiceEvent::print()
{
	Event::print();
	cout<<" begins service in "<<lane<<" lane"<<endl;
}

string StartServiceEvent::getLane()
{
	return lane;
}

//
//Mutators
//
void StartServiceEvent::processEvent(Simulation* sim)
{	
	getCustomer()->setWaitingTime(getTime());
	sim->addWaitTime(getCustomer()->getWaitTime());
	
	int servTime = getCustomer()->getServiceTime();
	
	sim->addServiceTime(servTime);
	
	int compTime = getTime() + servTime;
	CompleteServiceEvent* cse = new CompleteServiceEvent(compTime, getCustomer(), lane);
	sim->scheduleEvent(cse);
	
	//at the end, print the start service event:
	print();
}
