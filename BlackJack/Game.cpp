#include "Game.h"
#include "PokerTable.h"

#include <iostream>
#include <string>

using namespace std;
using namespace BlackJack;


Game::Game(sf::RenderWindow& window)
	:m_pokerTable(window, m_player1, m_player2, m_player3, m_dealer),
	m_player1("One", &m_player2),
	m_player2("Two", &m_player3),
	m_player3("Three", nullptr),
	m_dealer(&m_shoe, &m_player1, &m_player2, &m_player3)
{
	m_shoe.addDeck(&m_deck[0]);
	m_shoe.addDeck(&m_deck[1]);
	m_shoe.addDeck(&m_deck[2]);
	m_shoe.addDeck(&m_deck[3]);
	m_shoe.addDeck(&m_deck[4]);
	m_shoe.addDeck(&m_deck[5]);
	m_currentPlayer = nullptr;
}

Game::~Game()
{
}

void Game::paint(State state)
{
	m_pokerTable.drawTable(state);
	m_pokerTable.drawCards(state);
	m_pokerTable.display();
}

void Game::setPlayerPlay(Play play)
{
	m_currentPlayer->setPlayChoice(play);
}

bool Game::playHit()
{
	if (m_currentPlayer->getPlayChoice() == Play::Hit)
	{
		m_dealer.hit(m_currentPlayer);
		m_currentPlayer->setPlayChoice(Play::Unknown);
		return true;
	}
	return false;
}

bool Game::playDouble()
{
	if (m_currentPlayer->getPlayChoice() == Play::Double)
	{
		m_dealer.hit(m_currentPlayer);
		m_currentPlayer->setPlayChoice(Play::Stay);
		return true;
	}
	return false;
}

bool Game::playDone()
{
	if (m_currentPlayer == nullptr)
	{
		m_currentPlayer = &m_player1;
	}
	else
	{
		if (m_currentPlayer->getPlayChoice() == Play::Stay)
		{
			m_currentPlayer = m_currentPlayer->getNextPlayer();
			if (m_currentPlayer == nullptr)
			{
				return true;
			}
		}
	}
	return false;
}

bool Game::placeBetsDone()
{
	if (m_currentPlayer == nullptr)
	{
		m_currentPlayer = &m_player1;
	}
	else
	{
		if (m_currentPlayer->makeBetDone())
		{
			m_currentPlayer = m_currentPlayer->getNextPlayer();
			if (m_currentPlayer == nullptr)
			{
				return true;
			}
		}
	}
	return false;
}

void Game::setPlayerBet(int value)
{
	m_currentPlayer->addHumanBet(value);
}

void Game::deal()
{
	m_dealer.deal();
}

