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
	const std::vector<const Card*>* getCards() const;

private:
	Card m_cards[52];
	std::vector<const Card*> m_deck;
	int m_top;

	void initDeck();
	void initCards();
	void doInit(Card::Rank rank, int offset);
};

