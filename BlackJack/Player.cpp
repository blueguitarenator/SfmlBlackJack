#include "Player.h"
#include <iostream>

using namespace std;
using namespace BlackJack;

Player::Player(const std::string& name, Player* player)
	:m_name(name), m_nextPlayer(player)
{
	m_bet = 0;
	m_betDone = false;
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

void Player::setNoChoice()
{
	//m_choice = HitChoice::NoChoice;
}

void Player::setStayChoice()
{
	//m_choice = HitChoice::Stay;
}

void Player::makeHitChoice(const Card* dealerShowCard)
{
	//cout << "Player: " << m_name << ". (H) Hit, (S) Stay" << endl;
	//m_choice = HitChoice::MakingChoice;
//	m_choice = BlackJack::Stay;
}

//BlackJack::HitChoice Player::getHitChoice() const
//{
//	return m_choice;
//}

void Player::clearCards()
{
	m_myCards.clear();
}

const std::vector<const Card*>* Player::getMyCards() const
{
	return &m_myCards;
}