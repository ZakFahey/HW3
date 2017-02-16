#pragma once
#include "CardCollection.h"

class SidePile : public CardCollection
{
private:
	//The index where cards are taken and put
	int top;

public:
	SidePile();
	//Places a card at the top of the pile
	void Put(int card);
	//Takes a card from the top of the pile
	int Take();
	//Returns how many cards are in the pile
	int CardsLeft() { return top; }
};