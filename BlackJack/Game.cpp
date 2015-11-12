#include "Game.h"
#include <iostream>
#include "Dealer.h"
#include "PokerTable.h"

using namespace std;

void setCardGraphics(Card* cards);

Game::Game(PokerTable* table)
	:m_pokerTable(table),m_dealer(&m_deck, &m_player1, &m_player2, &m_player3)
{
	initCards();
	initDeck();
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

void Game::initCards()
{
	doInit(Card::Ace, 0);
	doInit(Card::Two, 4);
	doInit(Card::Three, 8);
	doInit(Card::Four, 12);
	doInit(Card::Five, 16);
	doInit(Card::Six, 20);
	doInit(Card::Seven, 24);
	doInit(Card::Eight, 28);
	doInit(Card::Nine, 32);
	doInit(Card::Ten, 36);
	doInit(Card::Jack, 40);
	doInit(Card::Queen, 44);
	doInit(Card::King, 48);
	setCardGraphics(m_cards);
}

void Game::doInit(Card::Rank rank, int offset)
{
	m_cards[offset++].init(rank, Card::HEART);
	m_cards[offset++].init(rank, Card::DIAMOND);
	m_cards[offset++].init(rank, Card::SPADE);
	m_cards[offset++].init(rank, Card::CLUB);
}

void Game::initDeck()
{
	for (int i = 0; i < 52; i++)
	{
		m_deck.addCard(&m_cards[i]);
	}
	m_deck.shuffle();
}

void setCardGraphics(Card* cards)
{
	int i = 0;
	cards[i++].setCardGraphic("ace_of_hearts.png");
	cards[i++].setCardGraphic("ace_of_diamonds.png");
	cards[i++].setCardGraphic("ace_of_spades2.png");
	cards[i++].setCardGraphic("ace_of_clubs.png");

	cards[i++].setCardGraphic("2_of_hearts.png");
	cards[i++].setCardGraphic("2_of_diamonds.png");
	cards[i++].setCardGraphic("2_of_spades.png");
	cards[i++].setCardGraphic("2_of_clubs.png");

	cards[i++].setCardGraphic("3_of_hearts.png");
	cards[i++].setCardGraphic("3_of_diamonds.png");
	cards[i++].setCardGraphic("3_of_spades.png");
	cards[i++].setCardGraphic("3_of_clubs.png");

	cards[i++].setCardGraphic("4_of_hearts.png");
	cards[i++].setCardGraphic("4_of_diamonds.png");
	cards[i++].setCardGraphic("4_of_spades.png");
	cards[i++].setCardGraphic("4_of_clubs.png");

	cards[i++].setCardGraphic("5_of_hearts.png");
	cards[i++].setCardGraphic("5_of_diamonds.png");
	cards[i++].setCardGraphic("5_of_spades.png");
	cards[i++].setCardGraphic("5_of_clubs.png");

	cards[i++].setCardGraphic("6_of_hearts.png");
	cards[i++].setCardGraphic("6_of_diamonds.png");
	cards[i++].setCardGraphic("6_of_spades.png");
	cards[i++].setCardGraphic("6_of_clubs.png");

	cards[i++].setCardGraphic("7_of_hearts.png");
	cards[i++].setCardGraphic("7_of_diamonds.png");
	cards[i++].setCardGraphic("7_of_spades.png");
	cards[i++].setCardGraphic("7_of_clubs.png");

	cards[i++].setCardGraphic("8_of_hearts.png");
	cards[i++].setCardGraphic("8_of_diamonds.png");
	cards[i++].setCardGraphic("8_of_spades.png");
	cards[i++].setCardGraphic("8_of_clubs.png");

	cards[i++].setCardGraphic("9_of_hearts.png");
	cards[i++].setCardGraphic("9_of_diamonds.png");
	cards[i++].setCardGraphic("9_of_spades.png");
	cards[i++].setCardGraphic("9_of_clubs.png");

	cards[i++].setCardGraphic("10_of_hearts.png");
	cards[i++].setCardGraphic("10_of_diamonds.png");
	cards[i++].setCardGraphic("10_of_spades.png");
	cards[i++].setCardGraphic("10_of_clubs.png");

	cards[i++].setCardGraphic("jack_of_hearts2.png");
	cards[i++].setCardGraphic("jack_of_diamonds2.png");
	cards[i++].setCardGraphic("jack_of_spades2.png");
	cards[i++].setCardGraphic("jack_of_clubs2.png");

	cards[i++].setCardGraphic("queen_of_hearts2.png");
	cards[i++].setCardGraphic("queen_of_diamonds2.png");
	cards[i++].setCardGraphic("queen_of_spades2.png");
	cards[i++].setCardGraphic("queen_of_clubs2.png");

	cards[i++].setCardGraphic("king_of_hearts2.png");
	cards[i++].setCardGraphic("king_of_diamonds2.png");
	cards[i++].setCardGraphic("king_of_spades2.png");
	cards[i++].setCardGraphic("king_of_clubs2.png");

}