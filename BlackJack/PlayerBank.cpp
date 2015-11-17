#include "PlayerBank.h"



PlayerBank::PlayerBank()
	:m_bank(500), m_bet(0)
{
}


PlayerBank::~PlayerBank()
{
}

void PlayerBank::setWinnings(float value)
{
	m_winnings = value;
}

void PlayerBank::incrementBet(int value)
{
	m_bank -= value;
	m_bet += value;
}

void PlayerBank::decrementBet(int value)
{
	m_bank -= value;
}

int PlayerBank::getBet() const
{
	return m_bet;
}

int PlayerBank::getBank() const
{
	return m_bank + m_bet + m_winnings;
}

int PlayerBank::busted()
{
	int value = m_bet;
	m_bet = 0;
	return value;
}

void PlayerBank::gameOver()
{
	m_bank += m_bet;
	m_bank += m_winnings;
	m_winnings = 0.0f;
	m_bet = 0;
}