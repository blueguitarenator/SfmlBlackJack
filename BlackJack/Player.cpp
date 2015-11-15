#include "Player.h"
#include <iostream>

using namespace std;
using namespace BlackJack;

Player::Player(const std::string& name, Player* player)
	:m_name(name), m_nextPlayer(player)
{
	m_bet = 0;
	m_betDone = false;
	m_playChoice = Play::Unknown;
}


Player::~Player()
{
}

void Player::addHumanBet(int value)
{
	if (value == DONE_BET)
	{
		m_betDone = true;
	}
	else
	{
		m_bet += value;
	}
}

void Player::pushCard(const Card* card)
{
	m_myCards.push_back(card);
}

bool Player::makeBetDone()
{
	if (m_betDone)
	{
		m_betDone = false;
		return true;
	}
	return false;
}

void Player::setPlayChoice(Play play)
{
	m_playChoice = play;
	if (m_playChoice == Play::Double)
	{
		m_bet *= 2;
	}

}

Play Player::getPlayChoice()
{
	return m_playChoice;
}

void Player::clearCards()
{
	m_myCards.clear();
}

const std::vector<const Card*>* Player::getMyCards() const
{
	return &m_myCards;
}