#include "Player.h"
#include "BlackJack.h"
#include "PlayState.h"
#include <iostream>

using namespace std;
using namespace BlackJack;

Player::Player(const std::string& name, Player* player)
	:m_name(name), m_nextPlayer(player)
{
}


Player::~Player()
{
}

void Player::incrementBet(int value)
{
	m_bet += value;
}

int Player::getBet() const
{
	return m_bank.getBet();
}

Player* Player::getNextPlayer() 
{ 
	if (m_nextPlayer != nullptr)
	{
		m_nextPlayer->setIsActive(true);
	}
	m_isActive = false;
	return m_nextPlayer; 
}

PlayState* Player::getPlayState() const
{ 
	return m_playState; 
}

PlayState* Player::getBetState() const
{ 
	return m_betState; 
}

void Player::initPlayState(PlayState* playState)
{
	m_playState = playState;
}

void Player::initBetState(PlayState* playState)
{
	m_betState = playState;
}

int Player::getBank() const
{
	return m_bank.getBank();
}

void Player::pushCard(const Card* card)
{
	m_myCards.push_back(card);
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
}