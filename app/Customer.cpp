#include "Customer.h"
	
//initializing static variable:
static int ID = 0;
	
//Constructors
Customer::Customer()
{
	nbSmall = 0;
	nbBig = 0;
	nbFV = 0;
	nbCoupons = 0;
	arrivalTime = 0;
	serviceTime = 0;
	waitingTime = 0;
	id = ++ID;
}
Customer::Customer(int arrivalTime, int nbSmall, int nbBig, int nbFV, int nbCoupons)
{
	this->nbSmall = nbSmall;
	this->nbBig = nbBig;
	this->nbFV = nbFV;
	this->nbCoupons = nbCoupons;
	this->arrivalTime = arrivalTime;
	serviceTime = nbSmall * SMALL_ITEM_TIME + nbBig * BIG_ITEM_TIME + nbFV * FORV_TIME + nbCoupons * COUPON_TIME;
	waitingTime = 0;
	id = ++ID;
}

//
//Accessors
//
bool Customer::isExpress()
{
	if(nbSmall + nbBig + nbFV <= MIN_EXPRESS_ITEMS)
		return true;
	return false;
}

int Customer::getArrivalTime()
{
	return arrivalTime;
}

int Customer::getServiceTime()
{
	return serviceTime;
}

int Customer::getWaitTime()
{
	return waitingTime;
}

int Customer::getId()
{
	return id;
}

void Customer::print()
{
	cout << "Customer " << id <<": Time = "<<arrivalTime<<" nbSmall = "<<nbSmall<<" nbBig = "<<nbBig<< " nbFV = "<<nbFV<<" nbCoupons = "<<nbCoupons<<endl;
}

void Customer::printItems()
{
	if(nbSmall > 0)
		cout<<"SMALL: "<<nbSmall<<" ";
	if(nbBig > 0)
		cout<<"BIG: "<<nbBig<<" ";
	if(nbFV > 0)
		cout<<"FORV: "<<nbFV<<" ";
	if(nbCoupons > 0)
		cout<<"COUPON: "<<nbCoupons<<" ";
}

void Customer::printTimes()
{
	cout<<"Arrival: "<<arrivalTime<<" Complete: "<<arrivalTime+serviceTime+waitingTime<<" Wait: "<<waitingTime<<endl;
}

//
//Mutators
//

//Sets the waitingTime depending on the currentTime
void Customer::setWaitingTime(int currentTime)
{
	waitingTime = currentTime - arrivalTime;
}