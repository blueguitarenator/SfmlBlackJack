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

PlayState* Game::initPlayState()
{
	m_playStateFactory1.createPlayState(&m_player1);
	m_playStateFactory2.createPlayState(&m_player2);
	m_playStateFactory3.createPlayState(&m_player3);
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
	m_pokerTable.drawCards(state);
	m_pokerTable.display();
}

void Game::paint(GameState* gameState, PlayState* playState)
{
	m_pokerTable.drawTable(gameState, playState);
}

//void Game::setPlayerPlay(PlayState::Play play)
//{
//	m_currentPlayer->setPlayChoice(play);
//}

//bool Game::playHit()
//{
//	if (m_currentPlayer->getPlayChoice() == PlayState::Play::Hit)
//	{
//		m_dealer.hit(m_currentPlayer);
//		if (m_currentPlayer->getPlayChoice() != PlayState::Play::Bust)
//		{
//			m_currentPlayer->setPlayChoice(PlayState::Play::Unknown);
//		}
//		else
//		{
//			m_currentPlayer = m_currentPlayer->getNextPlayer();
//		}
//		return true;
//	}
//	return false;
//}

//bool Game::playDouble()
//{
//	if (m_currentPlayer->getPlayChoice() == PlayState::Play::Double)
//	{
//		m_dealer.hit(m_currentPlayer);
//		if (m_currentPlayer->getPlayChoice() != PlayState::Play::Bust)
//		{
//			m_currentPlayer->setPlayChoice(PlayState::Play::Stay);
//		}
//		m_currentPlayer = m_currentPlayer->getNextPlayer();
//		return true;
//	}
//	return false;
//}

//bool Game::playForPlayerDone()
//{
//	if (m_currentPlayer == nullptr)
//	{
//		return true;
//	}
//	if (m_currentPlayer->getPlayChoice() == PlayState::Play::Stay ||
//		m_currentPlayer->getPlayChoice() == PlayState::Play::Bust ||
//		m_currentPlayer->getPlayChoice() == PlayState::Play::BlackJack)
//	{
//		m_currentPlayer = m_currentPlayer->getNextPlayer();
//		return true;
//	}
//	return false;
//}

//bool Game::playForRoundDone()
//{
//	if (m_currentPlayer == nullptr)
//	{
//		return true;
//	}
//	return false;
//}

bool Game::placeBetsPlayerDone()
{
	if (m_currentPlayer->makeBetDone())
	{
		m_currentPlayer = m_currentPlayer->getNextPlayer();
		return true;
	}
	return false;
}

bool Game::placeBetsRoundDone()
{
	if (m_currentPlayer == nullptr)
	{
		return true;
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

void Game::payout()
{
	doPayout(m_player1, m_dealer);
	doPayout(m_player2, m_dealer);
	doPayout(m_player3, m_dealer);
}

void doPayout(Player& p, Dealer& dealer)
{
	//if (p.getPlayChoice() != PlayState::Play::BlackJack && p.getPlayChoice() != PlayState::Play::Bust)
	//{
	//	dealer.payout(&p);
	//}
}

//bool Game::checkDealerBlackJack()
//{
//	return m_dealer.checkDealerBlackJack();
//}
//
//void Game::checkPlayerBlackJack()
//{
//	m_dealer.checkBlackJack(&m_player1);
//	m_dealer.checkBlackJack(&m_player2);
//	m_dealer.checkBlackJack(&m_player3);
//}

void Game::roundOver()
{
	m_dealer.gameOver();
	m_player1.gameOver();
	m_player2.gameOver();
	m_player3.gameOver();
	//m_currentPlayer = nullptr;
}