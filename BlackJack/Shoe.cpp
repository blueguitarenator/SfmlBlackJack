#include "Shoe.h"
#include "Deck.h"
#include "Logger.h"


Shoe::Shoe()
{
	LOG_INFO("Creating shoe");
}


Shoe::~Shoe()
{
}

int Shoe::getCardsRemaining() const
{
	return m_top;
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
		LOG_DEBUG("Out of cards");
		throw "Out of cards";
	}
}

void Shoe::clear()
{
	m_shoe.clear();
	m_top = -1;
}