#pragma once
#include "CardCollection.h"

class Deck : public CardCollection
{
private:
	//The index where cards are put
	int bottom;
	//The index where cards are taken
	int top;
	//The number of cards in the deck
	int totalCards;
protected:
	//The content array
	int cards[52];

public:
	Deck(int,int);
	//Places a card at the bottom of the deck
	void Put(int card);
	//Takes a card from the top of the deck
	int Take();
	//Peek the top card
	int Peek();
	//Returns how many cards are in the deck
	int CardsLeft() { return totalCards; }
};