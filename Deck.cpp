#include "stdafx.h"
#include "Deck.h"
#include "Exceptions.h"

Deck::Deck()
{
	bottom = 0;
	top = 0;
	totalCards = 0;
}

//Places a card at the bottom of the deck
void Deck::Put(int card)
{
	if (totalCards == Size())
	{
		throw DeckFullException();
	}
	cards[bottom] = card;
	bottom--;
	if (bottom <= 0)
	{
		bottom = Size() - 1;
	}
	totalCards++;
}

//Takes a card from the top of the deck
int Deck::Take()
{
	if (totalCards == 0)
	{
		throw NoCardException();
	}
	top--;
	if (top <= 0)
	{
		top = Size() - 1;
	}
	totalCards--;
	return cards[top];
}