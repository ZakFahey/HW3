#pragma once
class CardCollection
{
protected:
	//The content array
	int cards[52];
	//Returns the maximum size of the collection
	int Size();

public:
	virtual void Put(int card) = 0;
	virtual int Take() = 0;
	//Returns how many cards are in the collection
	virtual int CardsLeft() = 0;
};