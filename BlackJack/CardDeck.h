#pragma once
#include "Card.h"
#include <vector>

class CardDeck
{
public:
	CardDeck();
	~CardDeck();
	CardDeck(std::vector<CardDeck> deck_list);
	std::vector<Card> GetCards();
	void Shuffle();
	void ShowCards();
	Card GetTopCard();
protected:

private:
	std::vector<Card> cards;
};

