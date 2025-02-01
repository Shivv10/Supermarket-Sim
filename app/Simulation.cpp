#include "Simulation.h"

//
//Constructor
//
Simulation::Simulation()
{
	eventPQ = new PriorityQueue();
	totalNbCust = 0;
	totalWaitTime = 0;
	totalServiceTime = 0;
}

//Destructor
Simulation::~Simulation()
{
	delete eventPQ;
}

//
//Accessors
//
void Simulation::printEventPQ()
{
	eventPQ->print();
}

void Simulation::printSummary()
{
	cout<<"######  Summary  ######"<<endl;
	cout<<"- Total number of customers: "<<totalNbCust<<endl;
	cout<<"- Service time: total = "<<totalServiceTime<< ", average = "<<totalServiceTime/(double)totalNbCust<<endl;
	cout<<"- Waiting time: total = "<<totalWaitTime<<", average = "<<totalWaitTime/(double)totalNbCust<<endl;
}

//
//Mutators
//
void Simulation::run()
{
	while(!eventPQ->isEmpty())
	{
		Event* nextEvent = dynamic_cast<Event*>(eventPQ->dequeue());
		if(!nextEvent)
			cout<<"Problem casting to Event*"<<endl;
		nextEvent->processEvent(this);
		delete nextEvent;
	}
}

void Simulation::scheduleEvent(Event* e)
{
	eventPQ->enqueue(e);
}

//Opens the file and sets the "myFile" field
void Simulation::openFile(string filename)
{
	myFile.open(filename);
}

//Closes the file
void Simulation::closeFile()
{
	myFile.close();
}

//Reads and processes the next line in the file
void Simulation::readLineInMyFile()
{
	string line;
	if(getline(myFile, line))
	{
		stringstream ss(line);
		string token;
		int counter = 0;
		int time = 0;
		string event = "";
		string typeItem = "";
		int nbSmall = 0, nbBig = 0, nbFV = 0, nbCoupons = 0;
		while(getline(ss, token, ' '))
		{
			//cout<<"Token: "<<token<<endl;
			if(counter == 0) //reading time
				time = stoi(token);
			else if(counter == 1) //reading event
				event = token;
			else if(counter%2 == 0) //argument > 1 and even --> type of item
				typeItem = token;
			else //argument > 2 and uneven --> nb of item
			{
				if(typeItem == "SMALL")
					nbSmall = stoi(token);
				else if(typeItem == "BIG")
					nbBig = stoi(token);
				else if(typeItem == "FORV")
					nbFV = stoi(token);
				else if(typeItem == "COUPON")
					nbCoupons = stoi(token);
				else
					cout<<"Problem: type of item unrecognized"<<endl;
			}
			counter++;
		}
		if(event == "ARRIVE")
		{
			//Build Customer object with all information
			Customer* custom = new Customer(time, nbSmall, nbBig, nbFV, nbCoupons);
			//custom->print();
			ArrivalEvent* e = new ArrivalEvent(time, custom);
			this->scheduleEvent(e);
		}
		else
			cout<<"Event in file not recognized"<<endl;
	}
}

void Simulation::incrementNbCust()
{
	totalNbCust++;
}

void Simulation::addWaitTime(int time)
{
	totalWaitTime += time;
}

void Simulation::addServiceTime(int time)
{
	totalServiceTime += time;
}
