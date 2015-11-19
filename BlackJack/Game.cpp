#include "Game.h"
#include "GameState.h"
#include "PlayState.h"

#include <iostream>
#include <string>

using namespace std;

void doPayout(Player& p, Dealer& dealer);

Game::Game(sf::RenderWindow& window)
	:m_pokerTable(window, m_player1, m_player2, m_player3, m_dealer),
	m_player1("One", &m_player2),
	m_player2("Two", &m_player3),
	m_player3("Three", nullptr),
	m_dealer(&m_shoe, &m_player1, &m_player2, &m_player3),
	m_playStateFactory1(this, &m_pokerTable),
	m_playStateFactory2(this, &m_pokerTable),
	m_playStateFactory3(this, &m_pokerTable)
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
	m_playStateFactory1.createPlayState(&m_player1);
	m_playStateFactory2.createPlayState(&m_player2);
	m_playStateFactory3.createPlayState(&m_player3);
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

void Game::initFirstPlayer()
{
	m_currentPlayer = &m_player1;
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
	if (p.getBet() > 0)
	{
		dealer.payout(&p);
	}
}

void Game::roundOver()
{
	m_dealer.gameOver();
	m_player1.gameOver();
	m_player2.gameOver();
	m_player3.gameOver();
}