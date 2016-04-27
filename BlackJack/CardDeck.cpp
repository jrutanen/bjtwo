#include "stdafx.h"
#include "CardDeck.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
//#include <math>


CardDeck::CardDeck()
{
	char suites[4];
	suites[0] = 'S';
	suites[1] = 'H';
	suites[2] = 'D';
	suites[3] = 'C';

	//add 52 cards into the deck
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j < 14; ++j)
		{
			Card new_card;
			new_card.value = j;
			new_card.suite = suites[i];
			cards.push_back(new_card);
		}
	}
}

CardDeck::CardDeck(std::vector<CardDeck> deck_list)
{
	for (unsigned int i = 0; i < deck_list.size(); ++i)
	{
		//cards.insert(cards.end(), deck_list.at(i).begin, deck_list.at(i).end);
		std::vector<Card> deck_cards = deck_list.at(i).GetCards();
		cards.insert(cards.end(), deck_cards.begin(), deck_cards.end());
	}
}


CardDeck::~CardDeck()
{
}

std::vector<Card> CardDeck::GetCards()
{
	return cards;
}

void CardDeck::Shuffle()
{
	std::vector<Card> shuffled_deck;
	std::vector<Card> temp_deck;
	temp_deck = cards;
	int card_pos = -1;

	// seed the random number generator
	srand(time(NULL));

	for (unsigned int i = 0; i < cards.size(); ++i)
	{
		//if there is more than one card to select from
		if (temp_deck.size() > 1)
		{
			card_pos = rand() % (temp_deck.size() - 1);
			shuffled_deck.push_back(temp_deck.at(card_pos));
			temp_deck.erase(temp_deck.begin() + card_pos);
		}
		else
		{
			shuffled_deck.push_back(temp_deck.front());
		}
	}
	cards = shuffled_deck;
}

void CardDeck::ShowCards()
{
	for (unsigned int i = 0; i < cards.size(); ++i)
	{
		std::cout << cards.at(i).suite << cards.at(i).value;
		if (i != cards.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

Card CardDeck::GetTopCard()
{
	Card top_card = cards.at(0);
	cards.erase(cards.begin());
	return top_card;
}