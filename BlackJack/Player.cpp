#include "Player.h"
#include <iostream>

using namespace std;
using namespace BlackJack;

Player::Player(const std::string& name, Player* player)
	:m_name(name), m_nextPlayer(player)
{
	m_betDone = false;
	m_playChoice = Play::Unknown;
}


Player::~Player()
{
}

int Player::getBet() const
{
	return m_bank.getBet();
}

int Player::getBank() const
{
	return m_bank.getBank();
}

void Player::addHumanBet(int value)
{
	if (value == DONE_BET)
	{
		m_betDone = true;
	}
	else
	{
		//m_bet += value;
		m_bank.incrementBet(value);
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
		m_bank.incrementBet(m_bank.getBet());
	}
}

int Player::busted()
{
	m_playChoice = Play::Bust;
	return m_bank.busted();
}

Play Player::getPlayChoice() const
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

void Player::setWinnings(float value)
{
	m_bank.setWinnings(value);
}

float Player::getWinnings() const
{
	return m_bank.getWinnings();
}

void Player::gameOver()
{
	m_myCards.clear();
	m_bank.gameOver();
	m_playChoice = Play::Unknown;
}