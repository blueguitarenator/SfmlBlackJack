#include "Player.h"
#include "BlackJack.h"
#include "PlayState.h"
#include "Robot.h"
#include <iostream>

using namespace std;
using namespace BlackJack;

Player::Player(const std::string& name, Player* player, Robot* robot)
	:m_name(name), m_nextPlayer(player), m_bank(500.0f), m_isInGame(true), m_robot(robot)
{
}


Player::~Player()
{
}

bool Player::isRobot() const
{
	return m_robot != nullptr;
}

void Player::robotBet()
{
	m_robot->makeBet(this);
}

PlayState* Player::robotPlay(PlayState* play, const Card* dealerCard)
{
	return m_robot->play(play, dealerCard);
}

void Player::incrementBet(int value)
{
	m_bank -= value;
	m_bet += value;
}

int Player::getBet() const
{
	return m_bet;
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

float Player::getBank() const
{
	return m_bank;
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

void Player::setPush()
{
	m_isInGame = false;
	m_winnings = 0.0f;
}

void Player::setBusted()
{
	m_isInGame = false;
	m_bet = -1;
	m_winnings = 0.0f;
}

void Player::setWinnings(float value)
{
	m_isInGame = false;
	m_winnings = value;
}

float Player::getWinnings() const
{
	return m_winnings;
}

void Player::gameOver()
{
	m_myCards.clear();
	m_bank += (m_winnings + (m_bet > 0 ? m_bet : 0));
	m_winnings = 0.0f;
	m_bet = 0;
	m_isInGame = true;
}

bool Player::isInGame() const
{
	return m_isInGame;
}