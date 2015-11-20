#pragma once
#include <vector>

class Card;
class Deck;

class Shoe
{
public:
	Shoe();
	~Shoe();

	void addDeck(const Deck* deck);
	int getCardsRemaining() const;
	void clear();

	const Card* draw();

private:
	std::vector<const Card*> m_shoe;
	int m_top;
};

