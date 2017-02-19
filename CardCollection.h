#pragma once
class CardCollection
{
protected:
	//The content array
	static const int cardStack[];

public:
	virtual void Put(int card) = 0;
	virtual int Take() = 0;
	//Returns how many cards are in the collection
	virtual int CardsLeft() = 0;
};