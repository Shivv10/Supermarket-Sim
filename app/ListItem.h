#ifndef LISTITEM_H_
#define LISTITEM_H_

#include <iostream>
using namespace std;

class ListItem
{
	public:
		virtual void print() = 0;
		
		//Destructor
		virtual ~ListItem(){};
};

#endif