#pragma once
#include <vector>
#include <string>
#include "Card.h"
#include "State.h"

class Player
{
public:
	Player();
	~Player();
	Player(bool ai);
	int HandValue();
	void AddCard(Card card);
	std::string ShowHand();
	PlayerState State();
	void Reset();
	std::string GetName();
	void SetName(std::string newName);

protected:

private:
	std::string name;
	PlayerState state;
	bool ai;
	int hand_value;
	std::vector<Card> player_hand;
	int CalculateHandValue(std::vector<Card> hand);
};

