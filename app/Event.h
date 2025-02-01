#ifndef EVENT_H_
#define EVENT_H_

#include <iostream>
#include "OrderedItem.h"
#include "Customer.h"

class Simulation;

class Event : public OrderedItem
{
	private:
		int time;
		Customer* customer;
	
	public:
		
		//Constructor
		Event(int time, Customer* customer);
		
		//
		//Accessors
		//
		virtual void print();
		int getTime();
		Customer* getCustomer();
		//Required from OrderedItem
		bool precedes(OrderedItem* oi);
		
		//
		//Mutators
		//
		virtual void processEvent(Simulation* sim) = 0;
};

#endif