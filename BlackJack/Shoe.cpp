#include "Shoe.h"
#include "Deck.h"


Shoe::Shoe()
{
	m_top = -1;
}


Shoe::~Shoe()
{
}

void Shoe::addDeck(const Deck* deck)
{
	for (auto c : *deck->getCards())
	{
		m_top++;
		m_shoe.push_back(c);
	}
}

const Card* Shoe::draw()
{
	if (m_top > 0)
	{
		return m_shoe.at(m_top--);
	}
	else
	{
		throw "Out of cards";
	}
}