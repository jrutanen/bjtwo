#include "stdafx.h"
#include "Player.h"
#include <iostream>


Player::Player()
{
}

Player::Player(bool computer)
{
	ai = computer;
}

Player::~Player()
{
}

void Player::AddCard(Card card)
{
	player_hand.push_back(card);
	hand_value = CalculateHandValue(player_hand);
}

std::string Player::ShowHand()
{
	std::string cards;

	for (int i = 0; i < player_hand.size(); ++i)
	{
		cards.push_back(player_hand.at(i).suite);
		cards.push_back(player_hand.at(i).value + 48);
		cards.append(" ");
	}
	return cards;
}

int Player::HandValue()
{
	return hand_value;
}

int Player::CalculateHandValue(std::vector<Card> cards)
{
	int value = 0;
	int ace_count = 0;
	for (int i = 0; i < cards.size(); ++i)
	{
		if (cards.at(i).value == 1)
		{
			value += 11;
			++ace_count;
		}
		else if (cards.at(i).value > 10)
		{
			value += 10;
		}
		else
		{
			value += cards.at(i).value;
		}
	}

	while (value > 21 && ace_count > 0)
	{
		value -= 10;
		--ace_count;
	}
	return value;
}