#include "Deck.h"

#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

void setCardGraphics(Card* cards);

Deck::Deck()
	:m_top(51)
{
	initCards();
	initDeck();
}

Deck::~Deck()
{
}

void Deck::initDeck()
{
	for (int i = 0; i < 52; i++)
	{
		addCard(&m_cards[i]);
	}
	shuffle();
}

void Deck::addCard(const Card* card)
{
	m_deck.push_back(card);
}

const std::vector<const Card*>* Deck::getCards() const
{
	return &m_deck;
}

void Deck::shuffle()
{
	auto engine = std::default_random_engine{};
	std::shuffle(std::begin(m_deck), std::end(m_deck), engine);
}

const Card* Deck::draw()
{
	return m_deck.at(m_top--);
}

void Deck::deckToString() const
{
	for (int i = 0; i < 52; i++)
	{
		cout << m_deck.at(i)->cardToString() << endl;
	}
}

void Deck::doInit(Card::Rank rank, int offset)
{
	m_cards[offset++].init(rank, Card::HEART);
	m_cards[offset++].init(rank, Card::DIAMOND);
	m_cards[offset++].init(rank, Card::SPADE);
	m_cards[offset++].init(rank, Card::CLUB);
}

void Deck::initCards()
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