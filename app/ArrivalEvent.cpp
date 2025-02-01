#include "ArrivalEvent.h"

		
//Constructor
ArrivalEvent::ArrivalEvent(int time, Customer* customer) : Event(time, customer){}

//
//Accessors
//
void ArrivalEvent::print()
{
	Event::print();
	cout<<" arrives: ";
	getCustomer()->printItems();
	cout<<"Service time: "<<getCustomer()->getServiceTime()<<endl;
}

//
//Mutators
//
void ArrivalEvent::processEvent(Simulation* sim)
{
	sim->incrementNbCust(); //for stats
	
	bool firstInLine = sim->enqueueWaitLine(getCustomer());
	
	//The customer we just added is the first in line and will be serviced immediately
	if(firstInLine)
	{
		StartServiceEvent* start = new StartServiceEvent(getTime(), getCustomer(), sim->getLane(getCustomer())); //time is the same as arrival time
		sim->scheduleEvent(start);
	}
	
	//Must read next line in file
	sim->readLineInMyFile();
	
	//at the end, print the arrival event:
	print();
}
