// BlackJack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CardDeck.h"
#include "Card.h"
#include "Player.h"
#include "State.h"
#include <cctype>

using namespace std;

int player_cards_value = 0;
int dealer_cards_value = 0;
vector<Card> player_cards;
vector<Card> dealer_cards;

void PrintTable(Player p1, Player dealer)
{
	system("CLS");//system("clear"); //CLS for windows, clear for Linux/OS X
	cout << "Black Jack Game" << endl << endl;

	cout << "Dealer: " << dealer.HandValue() << endl;
	cout << dealer.ShowHand();

	if (dealer.HandValue() >= 17 && dealer.HandValue() < 22) cout << "Dealer Stays";
	if (dealer.HandValue() > 21) cout << "Dealer Busted";
	cout << endl << endl;

	cout << "Player: " << p1.HandValue() << endl;
	cout << p1.ShowHand();
	cout << endl;
}

void PrintResults(Player p1, Player dealer)
{
	if(p1.HandValue() > dealer.HandValue() && p1.HandValue() <= 21)
	{
		cout << "Player 1 wins!!!" << endl;
	}
	else if (p1.HandValue() == dealer.HandValue() && p1.HandValue() <= 21)
	{
		cout << "It's a tie, you get your money back!" << endl;
	}
	else if ((p1.HandValue() < dealer.HandValue() || p1.HandValue() > 21) && dealer.HandValue() <= 21)
	{
		cout << "Dealer wins!!!" << endl;
	}
	else if (p1.HandValue() <= 21 && dealer.HandValue() > 21)
	{
		cout << "Player 1 wins!!!" << endl;
	}
	else
	{
		cout << "All players busted. You lost your money!" << endl;
	}
}

char UserInput(bool running)
{
	char response;
	if (running)
	{
		cout << "Choose your destiny (D = draw, S = stay, Q = Give up and Quit: " << endl;
		cin >> response;
	}
	else
	{
		cout << "What do you want? (P = play, Q = Give up and Quit: " << endl;
		cin >> response;
	}

	return toupper(response);
}

void Winner(Player player)
{
	cout << player.GetName() << " WINS!" << endl;
}

int main()
{
	GameState gameState;
	int nbr_of_decks = 4;
	cout << "Black Jack Game" << endl;
	vector<CardDeck> decks;

	for (int i = 0; i < nbr_of_decks; ++i)
	{
		decks.push_back(CardDeck());
	}

	char input = ' ';
	int card_nbr = 0;

	//combine all decks to one and shuffle
	CardDeck bj_deck = CardDeck(decks);
	bj_deck.Shuffle();

	Player player1 = new Player(true);
	Player dealer = new Player(true);

	gameState = STOP;
	bool gameOn = true;

	while (gameOn)
	{
		while (gameState != STOP)
		{
			//Reset Player Data
			dealer.Reset();
			player1.Reset();

			//Deal two cards
			for (unsigned int i = 0; i != 2; ++i)
			{
				player1.AddCard(bj_deck.GetTopCard());
				dealer.AddCard(bj_deck.GetTopCard());
			}

			//show cards
			PrintTable(player1, dealer);

			//if player gets Black Jack he wins
			if (player1.HandValue() == 21)
			{
				gameState = STOP;
				Winner(player1);
			}

			//set game state to running
			gameState = RUNNING;

			while (gameState == RUNNING)
			{
				//Dealer draws card
				if (dealer.HandValue() < 17)
				{
					dealer.AddCard(bj_deck.GetTopCard());
				}

				if (player1.HandValue() < 21)
				{
					char userAction = UserInput(true);

					switch (userAction)
					{
					case 'Q':
						gameOn = false;
						gameState = STOP;
						break;
					case 'D':
						player1.AddCard(bj_deck.GetTopCard());
						break;
					case 'S':
						gameState = START;
						break;
					}
				}

				PrintTable(player1, dealer);

				if (player1.HandValue() > 21 || dealer.HandValue() > 21) gameState = STOP;
			}
			PrintResults(player1, dealer);
			gameState = STOP;
		}

		input = UserInput(false);

		switch (input)
		{
		case 'Q':
			gameOn = false;
			break;
		case 'P':
			gameState = START;
			break;
		}

	}
    return 0;
}

