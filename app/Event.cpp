#include "Event.h"
	
//Constructor
Event::Event(int time, Customer* customer)
{
	this->time = time;
	this->customer = customer;
}

//
//Accessors
//
int Event::getTime()
{
	return time;
}

Customer* Event::getCustomer()
{
	return customer;
}

void Event::print()
{
	cout<<"Time "<<getTime()<<": Customer "<<getCustomer()->getId();
}

//Required from OrderedItem
bool Event::precedes(OrderedItem* oi)
{
	Event* otherEvent = dynamic_cast<Event*>(oi);
	
	if(!otherEvent)
		cout<<"error with dynamic cast"<<endl;
	else
	{
		if(this->time < otherEvent->time)
			return true;
		else if(this->time == otherEvent->time)
			return this->customer->getId() < otherEvent->customer->getId();
	}
	return false;
}