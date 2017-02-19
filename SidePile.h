#pragma once
#include "Deck.h"

class SidePile : public CardCollection
{
private:
	//The index where cards are taken and put
	int top;
	//Individual decks
	int cards[52];

public:
	SidePile();
	//Places a card at the top of the pile
	void Put(int card);
	//Takes a card from the top of the pile
	int Take();
	//Returns how many cards are in the pile
	int CardsLeft() { return top; }
};