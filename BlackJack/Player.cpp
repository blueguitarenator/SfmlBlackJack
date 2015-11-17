#include "Player.h"
#include "BlackJack.h"
#include <iostream>

using namespace std;
using namespace BlackJack;

Player::Player(const std::string& name, Player* player)
	:m_name(name), m_nextPlayer(player)
{
	m_betDone = false;
	m_playState.init();
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

void Player::setPlayChoice(PlayState::Play play)
{
	m_playState.setChoice(m_bank, play);
}

int Player::busted()
{
	m_playState.setChoice(m_bank, PlayState::Play::Bust);
	return m_bank.getBet();
}

PlayState::Play Player::getPlayChoice() const
{
	return m_playState.getChoice();
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
	m_playState.init();
}