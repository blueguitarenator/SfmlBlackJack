#include "Game.h"
#include "GameState.h"
#include "PlayState.h"
#include "Logger.h"
#include <iostream>
#include <string>

using namespace std;

void doPayout(Player& p, Dealer& dealer);

Game::Game(sf::RenderWindow& window)
	:m_pokerTable(window, m_player1, m_player2, m_player3, m_dealer),
	m_player1("One", &m_player2, nullptr),
	m_splitPlayer1("OneSplit", &m_player2, nullptr),
	m_player2("Two", &m_player3, &m_robot2),
	m_splitPlayer2("TwoSplit", &m_player3, &m_robot2),
	m_player3("Three", nullptr, &m_robot3),
	m_splitPlayer3("ThreeSplit", nullptr, &m_robot3),
	m_dealer(&m_shoe, &m_player1, &m_player2, &m_player3),
	m_playStateFactory1(this, &m_pokerTable),
	m_playStateFactory2(this, &m_pokerTable),
	m_playStateFactory3(this, &m_pokerTable),
	m_playStateFactory1s(this, &m_pokerTable),
	m_playStateFactory2s(this, &m_pokerTable),
	m_playStateFactory3s(this, &m_pokerTable)
{
	loadShoe();
	m_player1.setSplit(&m_splitPlayer1);
	m_player2.setSplit(&m_splitPlayer2);
	m_player3.setSplit(&m_splitPlayer3);
}

Game::~Game()
{
}

Player* Game::getActivePlayer()
{
	if (m_player1.isActive())
	{
		return &m_player1;
	}
	else if (m_player2.isActive())
	{
		return &m_player2;
	}
	else if (m_player3.isActive())
	{
		return &m_player3;
	}
	return nullptr;
}

void Game::loadShoe()
{
	LOG_INFO("Loading new shoe");
	m_shoe.clear();
	m_shoe.addDeck(&m_deck[0]);
	m_shoe.addDeck(&m_deck[1]);
	m_shoe.addDeck(&m_deck[2]);
	m_shoe.addDeck(&m_deck[3]);
	m_shoe.addDeck(&m_deck[4]);
	m_shoe.addDeck(&m_deck[5]);
}

PlayState* Game::initBetState()
{
	m_playStateFactory1.createBetState(&m_player1);
	m_playStateFactory2.createBetState(&m_player2);
	m_playStateFactory3.createBetState(&m_player3);
	m_player1.setIsActive(true);
	return m_player1.getBetState();
}

PlayState* Game::initPlayState()
{
	m_playStateFactory1.resetPlayState(&m_player1);
	m_playStateFactory1s.resetPlayState(&m_splitPlayer1);
	m_playStateFactory2.resetPlayState(&m_player2);
	m_playStateFactory2s.resetPlayState(&m_splitPlayer2);
	m_playStateFactory3.resetPlayState(&m_player3);
	m_playStateFactory3s.resetPlayState(&m_splitPlayer3);
	m_player1.setIsActive(true);

	return m_player1.getPlayState();
}

PokerTable* Game::getTable() 
{
	return &m_pokerTable;
}

bool Game::dealerHitDone()
{
	return m_dealer.hitPastSoft17();
}

void Game::paint(GameState* state)
{
	m_pokerTable.drawTable(state);
	m_pokerTable.drawCards(state);
	m_pokerTable.display();
}

void Game::deal()
{
	m_dealer.deal();
}

void Game::payout()
{
	doPayout(m_player1, m_dealer);
	doPayout(m_player2, m_dealer);
	doPayout(m_player3, m_dealer);
}

void doPayout(Player& p, Dealer& dealer)
{
	if (p.getBet() > 0 && p.isInGame())
	{
		dealer.payout(&p);
	}
}

bool Game::atLeastOnePlayer() const
{
	return m_player1.isInGame() || m_player2.isInGame() || m_player3.isInGame();
}

void Game::roundOver()
{
	m_dealer.gameOver();
	m_player1.gameOver();
	m_player2.gameOver();
	m_player3.gameOver();
	int shoeSize = m_shoe.getCardsRemaining();
	if (shoeSize < 20)
	{
		loadShoe();
	}
}