#include "stdafx.h"
#include "CardCollection.h"

//Returns the maximum size of the collection
int CardCollection::Size()
{
	return sizeof(cards) / sizeof(*cards);
}
