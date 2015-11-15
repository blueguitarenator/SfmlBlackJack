#include "Card.h"
#include <string>

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

void Card::setCardGraphic(const std::string& cardGraphicFile)
{
	m_cardGraphicFile = cardGraphicFile;
}

std::string Card::getCardGraphic() const
{
	return m_cardGraphicFile;
}