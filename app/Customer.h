#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "ListItem.h"

class Customer : public ListItem
{
	private:
		//Constants for item times
		static const int SMALL_ITEM_TIME = 1;
		static const int BIG_ITEM_TIME = 2;
		static const int FORV_TIME = 4;
		static const int COUPON_TIME = 5;
		static const int MIN_EXPRESS_ITEMS = 12;
		
		int nbSmall;
		int nbBig;
		int nbFV;
		int nbCoupons;
		int arrivalTime;
		int serviceTime;
		int waitingTime;
		int id;
	
	public:
		//Constructors
		Customer();
		Customer(int arrivalTime, int nbSmall, int nbBig, int nbFV, int nbCoupons);
		
		//
		//Accessors
		//
		bool isExpress();
		int getArrivalTime();
		int getServiceTime();
		int getWaitTime();
		int getId();
		void print();
		void printItems();
		void printTimes();
		
		//
		//Mutators
		//
		void setWaitingTime(int time);
};

#endif