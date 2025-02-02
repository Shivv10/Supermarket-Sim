#include "ExpressSimulation.h"
#include "OneWaitLineSimulation.h"

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout<<"USAGE: a2.exe filename simulationType"<<endl;
		cout<<"where simulationType is either 1 (express lane) or 2 (one waiting line)."<<endl;
		return 0;
	}

	string filename = "input.txt";

	string version = argv[2];
	Simulation* sim;
	
	cout<<"Simulation begins..."<<endl;
	
	if(version == "1")
		sim = new ExpressSimulation;
	else if(version == "2")
		sim = new OneWaitLineSimulation;
	else
	{
		cout<<"The simulation type: "<<version<<" is invalid. Please use either 1 or 2."<<endl;
		return 0;
	}
	
	sim->openFile(filename);
	sim->readLineInMyFile();
	
	sim->run();
	
	sim->closeFile();
	cout<<"... simulation ended."<<endl;
	
	sim->printSummary();
	
	//Freeing memory
	delete sim;
	return 0;
}
