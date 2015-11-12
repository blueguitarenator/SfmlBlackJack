#pragma once
#include <vector>
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();

	void addCard(const Card* card);
	void shuffle();
	const Card* draw();
	void deckToString() const;

private:
	std::vector<const Card*> m_deck;
	int m_top;
};

