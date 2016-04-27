// BlackJack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CardDeck.h"
#include "Card.h"
#include "Player.h"

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
	if (p1.HandValue() >= 18 && p1.HandValue() < 22) cout << "Player Stays";
	if (p1.HandValue() > 21) cout << "Player Busted";
	cout << endl;
}


int main()
{
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

	while (true)
	{
		bool game = true;
		//Dealer draws card
		if (dealer.HandValue() < 17)
		{
			dealer.AddCard(bj_deck.GetTopCard());
		}
		//player draws card
		if (player1.HandValue() < 18)
		{
			player1.AddCard(bj_deck.GetTopCard());
		}

		PrintTable(player1, dealer);

		if (dealer_cards_value > 21 || player_cards_value > 21) break;
		cout << "Type in key for new card" << endl;
		cin >> input;
		//        if(input == 'Q') game = false;
	}
    return 0;
}

