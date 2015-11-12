#include "Card.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Card::Card()
{
}

void Card::init(Rank value, Suit suit)
{
	m_rank = value;
	m_suit = suit;
}

Card::~Card()
{
}

string Card::cardToString() const
{
	stringstream sstr;
	sstr << m_rank << " " << m_suit;
	return sstr.str();
}

void Card::setCardGraphic(const std::string& cardGraphicFile)
{
	m_cardGraphicFile = cardGraphicFile;
}

std::string Card::getCardGraphic() const
{
	return m_cardGraphicFile;
}