#include "Game.h"
#include "PokerTable.h"

using namespace std;



Game::Game(PokerTable* table)
	:m_pokerTable(table),m_dealer(&m_shoe, &m_player1, &m_player2, &m_player3)
{
	m_shoe.addDeck(&m_deck[0]);
	m_shoe.addDeck(&m_deck[1]);
	m_shoe.addDeck(&m_deck[2]);
	m_shoe.addDeck(&m_deck[3]);
	m_shoe.addDeck(&m_deck[4]);
	m_shoe.addDeck(&m_deck[5]);
}

Game::~Game()
{
}

void Game::handleKeyPressed(sf::Event::KeyEvent keyEvent)
{
	if (keyEvent.code == sf::Keyboard::C)
	{
		m_dealer.deal();
	}
	else if (keyEvent.code == sf::Keyboard::N)
	{
		m_dealer.newGame();
	}
	m_pokerTable->refresh(&m_dealer, &m_player1, &m_player2, &m_player3);
}





