#include "stdafx.h"
#include "Deck.h"
#include "SidePile.h"
#include <iostream>

using namespace std;

int main();

//Determines the player's/computer's action (true/false = player/computer)
int playerAction(bool);
//Prints out results and returns winner (true/false = player/computer)
bool printResults(int, int, int, int);
//Distribute winnings
void winnings(int, int, int, int);


//Rounds won
int playerWins = 0;
int compWins = 0;

//Declare decks and piles
Deck PlayerDeck(0, 25);
Deck CompDeck(26, 51);
SidePile PlayerPile;
SidePile CompPile;

int main()
{
	// true = # of rounds & false = out of cards
	bool style;
	// max # of rounds
	int maxRounds = 0;
	// current round number
	int round = 0;

	char choose;
	do
	{
		cout << "What style would you like to play?" << endl;
		cout << "1. # of Rounds" << endl;
		cout << "2. Out of Cards" << endl;
		cin >> choose;
	} while (choose != '1' && choose != '2');
	switch (choose)
	{
	case '1':
		style = true;
		break;
	case '2':
		style = false;
		break;
	}
	if (style)
	{
		cout << "Enter Max Rounds: ";
		cin >> maxRounds;
	}

	do
	{
		round++;
		cout << endl << "ROUND " << round << endl << endl;

		int playerDeckCard;
		int playerPileCard;
		int compDeckCard;
		int compPileCard;

		//Player's turn
		cout << "Player's Turn:" << endl;
		switch (playerAction(true))
		{
		case '1':
			playerDeckCard = PlayerDeck.Take();
			playerPileCard = 0;
			break;
		case '3':
			playerDeckCard = PlayerDeck.Take();
			playerPileCard = PlayerPile.Take();
			break;
		case '4':
			PlayerPile.Put(PlayerDeck.Take());
			playerDeckCard = PlayerDeck.Take();
			playerPileCard = 0;
			break;
		}

		//Computer's/Player 2's turn
		cout << "Computer's Turn:" << endl;
		switch (playerAction(false))
		{
		case '1':
			compDeckCard = CompDeck.Take();
			compPileCard = 0;
			break;
		case '3':
			compDeckCard = CompDeck.Take();
			compPileCard = CompPile.Take();
			break;
		case '4':
			CompPile.Put(CompDeck.Take());
			compDeckCard = CompDeck.Take();
			compPileCard = 0;
			break;
		}

		winnings(playerDeckCard, playerPileCard, compDeckCard, compPileCard);

		if (PlayerDeck.CardsLeft() == 0)
		{
			cout << "PLAYER WINS!" << endl;
			return 0;
		}
		else if (CompDeck.CardsLeft() == 0)
		{
			cout << "COMPUTER WINS!" << endl;
			return 0;
		}
	} while (round == 0 || round < maxRounds);

	//Determines match winner
	if (playerWins > compWins)
	{
		cout << "PLAYER WINS!" << endl;
	}
	else if (playerWins < compWins)
	{
		cout << "COMPUTER WINS!" << endl << endl;
	}
	else
	{
		cout << "Matches Tied!" << "Tie goes to computer." << endl;
	}

    return 0;
}

//Determines the player's/computer's action
int playerAction(bool deck)
{
	char choose;
	do
	{
		cout << "1. Play deck" << endl;
		cout << "2. Peek deck" << endl;
		cout << "3. Pull from pile" << endl;
		cout << "4. Push card to pile" << endl;
		cin >> choose;
		if (choose == '2')
		{
			if (deck)
			{
				cout << endl << "Your top card is: " << PlayerDeck.Peek() << endl;
			}
			else
			{
				cout << endl << "Your top card is: " << CompDeck.Peek() << endl;
			}
		}
		cout << endl;
	} while (choose != '1' && choose != '3' && choose != '4');
	return choose;
}

//Prints out results and returns winner
bool printResults(int pdc, int ppc, int cdc, int cpc)
{
	//Prints cards played
	cout << "Player Played: ";
	if (ppc == 0)
	{
		cout << pdc << endl;
	}
	else
	{
		cout << pdc << "&" << ppc << endl;
	}
	cout << "Computer Played: ";
	if (cpc == 0)
	{
		cout << cdc << endl;
	}
	else
	{
		cout << cdc << "&" << cpc << endl;
	}

	//Calculates totals
	int pt = pdc + ppc;
	int ct = cdc + cpc;

	//Determines round winner
	if (pt > ct)
	{
		cout << "Player Wins!" << endl << endl;
		return true;
	}
	else if (pt < ct)
	{
		cout << "Computer Wins!" << endl << endl;
		return false;
	}
	else
	{
		cout << "Round Tied!" << "Tie goes to computer." << endl << endl;
		return false;
	}
}

void winnings(int pdc, int ppc, int cdc, int cpc)
{
	bool winner = printResults(pdc, ppc, cdc, cpc);
	if (winner)
	{
		PlayerDeck.Put(cdc);
		if (cpc != 0)
		{
			PlayerDeck.Put(cpc);
		}
		playerWins++;
	}
	else
	{
		CompDeck.Put(pdc);
		if (ppc != 0)
		{
			CompDeck.Put(ppc);
		}
		compWins++;
	}
}