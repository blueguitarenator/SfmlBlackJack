#include "Deck.h"

#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

Deck::Deck()
	:m_top(51)
{
}


Deck::~Deck()
{
}

void Deck::addCard(const Card* card)
{
	m_deck.push_back(card);
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

