#pragma once
#include <vector>
#include <string>
#include "Card.h"

class Player
{
public:
	Player();
	~Player();
	Player(bool ai);
	int HandValue();
	void AddCard(Card card);
	std::string ShowHand();

protected:

private:
	bool ai;
	int hand_value;
	std::vector<Card> player_hand;
	int CalculateHandValue(std::vector<Card> hand);
};

