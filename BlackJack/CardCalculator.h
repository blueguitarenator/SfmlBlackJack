#pragma once
#include <vector>

class Card;

class CardCalculator
{
public:
	CardCalculator();
	~CardCalculator();

	int getCardValue(const std::vector<const Card*>* cards) const;
	bool isLessThanEqualToSoft17(const std::vector<const Card*>* cards) const;
};

