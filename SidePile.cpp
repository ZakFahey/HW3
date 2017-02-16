#include "stdafx.h"
#include "SidePile.h"
#include "Exceptions.h"

SidePile::SidePile()
{
	top = 0;
}

//Places a card at the top of the pile
void SidePile::Put(int card)
{
	if (top >= Size() - 1)
	{
		throw DeckFullException();
	}
	cards[top] = card;
	top++;
}

//Takes a card from the top of the pile
int SidePile::Take()
{
	if (top == 0)
	{
		throw NoCardException();
	}
	top--;
	return cards[top];
}