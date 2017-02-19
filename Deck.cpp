#include "stdafx.h"
#include "Deck.h"
#include "Exceptions.h"

Deck::Deck(int a, int z)
{
	bottom = 0;
	top = (z - a) + 1;
	totalCards = top;

	int index = 0;
	for (a; a <= z; a++)
	{
		cards[index] = cardStack[a];
		index++;
	}
}

//Places a card at the bottom of the deck
void Deck::Put(int card)
{
	if (totalCards == sizeof(cards))
	{
		throw DeckFullException();
	}
	cards[bottom] = card;
	bottom--;
	if (bottom <= 0)
	{
		bottom = sizeof(*cards) - 1;
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
		top = sizeof(*cards) - 1;
	}
	totalCards--;
	return cards[top];
}

//Peek the top card
int Deck::Peek()
{
	return cards[top-1];
}