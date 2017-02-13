#include "stdafx.h"
#include "Deck.h"
#include "Exceptions.h"

Deck::Deck()
{
	bottom = 0;
	top = 0;
}

//Places a card at the bottom of the deck
void Deck::Put(int card)
{
	if (CardsLeft() == Size())
	{
		throw DeckFullException();
	}
	cards[bottom] = card;
	bottom--;
	if (bottom <= 0)
	{
		bottom = Size() - 1;
	}
}

//Takes a card from the top of the deck
int Deck::Take()
{
	if (top == bottom)
	{
		throw NoCardException();
	}
	top--;
	if (top <= 0)
	{
		top = Size() - 1;
	}
	return cards[top];
}

//Returns how many cards are in the deck
int Deck::CardsLeft()
{
	if (top >= bottom)
	{
		return top - bottom;
	}
	return top - bottom + Size();
}
