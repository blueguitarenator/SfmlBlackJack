#include "CardCalculator.h"
#include "Card.h"


CardCalculator::CardCalculator()
{
}


CardCalculator::~CardCalculator()
{
}

bool CardCalculator::isLessThanEqualToSoft17(const std::vector<const Card*>* cards) const
{
	int value = getCardValue(cards);
	if (value < 17)
	{
		return true;
	}
	else if (value == 17)
	{
		for (auto c : *cards)
		{
			if (c->getRank() == 1)
			{
				return true;
			}
		}
	}
	return false;
}

int CardCalculator::getCardValue(const std::vector<const Card*>* cards) const
{
	int value = 0;
	int aceCount = 0;
	for (auto c : *cards)
	{
		if (c->getRank() == 11 || c->getRank() == 12 || c->getRank() == 13)
		{
			value += 10;
		}
		else if (c->getRank() == 1)
		{
			value += 11;
			aceCount++;
		}
		else
		{
			value += c->getRank();
		}
	}
	if (value > 21 && aceCount > 0)
	{
		while (value > 21 && aceCount > 0)
		{
			value -= 10;
			aceCount--;
		}
	}
	return value;
}
