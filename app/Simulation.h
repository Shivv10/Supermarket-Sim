#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iomanip>
#include <fstream>
#include <sstream>

//#include "Event.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "ArrivalEvent.h"

class Simulation
{
	private:
		PriorityQueue* eventPQ;
		ifstream myFile;
		int totalNbCust;
		int totalWaitTime;
		int totalServiceTime;
		
	public:
		//
		//Constructor
		//
		Simulation();
		
		//Destructor
		virtual ~Simulation();
		
		//
		//Accessors
		//
		void printEventPQ();
		//To check in which lane the customer is --> to be defined in subclasses
		virtual string getLane(Customer* c) = 0;
		
		void printSummary();
		
		//
		//Mutators
		//
		virtual void run();
		void scheduleEvent(Event* e);
		void openFile(string filename);
		void closeFile();
		void readLineInMyFile();
		//To enqueue in the appropriate waiting line --> to be defined in subclasses
		//bool will tell if the customer can be serviced right now (true if can be serviced)
		virtual bool enqueueWaitLine(Customer* c) = 0;
		//To dequeue a customer in the appropriate waiting line --> to be defined in subclasses
		//should be called when processing a complete eventPQ, will return the next customer in line or NULL
		virtual Customer* dequeueWaitLine(Customer* c) = 0;
		
		void incrementNbCust();
		void addWaitTime(int time);
		void addServiceTime(int time);
};

#endif