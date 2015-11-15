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
	//if (state == State::NewGame)
	//{
	//	m_pokerTable.drawTable();
	//}
	m_pokerTable.drawTable();
	m_pokerTable.drawCards(state);
	m_pokerTable.display();
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

//void Game::handlePollEvent()
//{
	//if (m_state == GameState::Bet)
	//{
	//	handleBets();
	//}
	//else if (m_state == GameState::Deal)
	//{
	//	m_dealer.deal();
	//	changeState(GameState::Hits);
	//}
	//else if (m_state == GameState::Hits)
	//{
	//	handleHits();
	//	changeState(GameState::Hitting);
	//	refresh();
	//}
//}

//void Game::handleKeyPressed(sf::Event::KeyEvent keyEvent)
//{
	/*if (keyEvent.code == sf::Keyboard::H)
	{
		hitPress();
	}
	else if (keyEvent.code == sf::Keyboard::S)
	{
		stayPress();
	}*/
//}

//void Game::refresh()
//{
//	m_pokerTable->refresh(&m_dealer, &m_player1, &m_player2, &m_player3);// , m_state);
//}

//void Game::changeState(BlackJack::GameState state)
//{
//	m_state = state;
//	cout << "New state: ";
//	//printState(m_state);
//	refresh();
//}

//void Game::stayPress()
//{
//	if (m_player1.getHitChoice() == HitChoice::MakingChoice)
//	{
//		m_player1.setStayChoice();
//	}
//	else if (m_player2.getHitChoice() == HitChoice::MakingChoice)
//	{
//		m_player2.setStayChoice();
//	}
//	else if (m_player3.getHitChoice() == HitChoice::MakingChoice)
//	{
//		m_player3.setStayChoice();
//	}
//}

//void Game::hitPress()
//{
//	if (m_player1.getHitChoice() == HitChoice::MakingChoice)
//	{
//		m_dealer.hit(&m_player1);
//		m_player1.setNoChoice();
//	}
//	else if (m_player2.getHitChoice() == HitChoice::MakingChoice)
//	{
//		m_dealer.hit(&m_player1);
//		m_player2.setNoChoice();
//	}
//	else if (m_player3.getHitChoice() == HitChoice::MakingChoice)
//	{
//		m_dealer.hit(&m_player1);
//		m_player3.setNoChoice();
//	}
//	else
//	{
//		changeState(GameState::DealerHit);
//	}
//}


//void Game::handleHits()
//{
//	const Card* showCard = m_dealer.getShowCard();
//	if (m_player1.getHitChoice() != HitChoice::Stay)
//	{
//		doHandleHit(m_player1, showCard);
//	}
//	else if (m_player2.getHitChoice() != HitChoice::Stay)
//	{
//		doHandleHit(m_player2, showCard);
//	}
//	else if (m_player3.getHitChoice() != HitChoice::Stay)
//	{
//		doHandleHit(m_player3, showCard);
//	}
//	else
//	{
//		changeState(GameState::DealerHit);
//	}
//}

//void Game::doHandleHit(Player& player, const Card* showCard)
//{
//	if (player.getHitChoice() == HitChoice::NoChoice)
//	{
//		player.makeHitChoice(showCard);
//	}
//	else if (player.getHitChoice() == HitChoice::Hit)
//	{
//		m_dealer.hit(&m_player1);
//		player.setNoChoice();
//	}
//	else
//	{
//		player.setStayChoice();
//	}
//}

//void Game::handleBets()
//{
//	if (m_player1.getBet() == 0)
//	{
//		m_player1.makeBet();
//	}
//	else if (m_player2.getBet() == 0)
//	{
//		m_player2.makeBet();
//	}
//	else if (m_player3.getBet() == 0)
//	{
//		m_player3.makeBet();
//	}
//	else
//	{
//		changeState(GameState::Deal);
//	}
//}



