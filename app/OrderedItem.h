#ifndef ORDEREDITEM_H_
#define ORDEREDITEM_H_

#include "ListItem.h"
using namespace std;

class OrderedItem : public ListItem
{
	public:
		virtual bool precedes(OrderedItem* oi) = 0;
};

#endif