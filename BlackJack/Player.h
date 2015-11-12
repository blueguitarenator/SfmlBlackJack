#pragma once
#include <vector>

class Card;

class Player
{
public:
	Player();
	~Player();

	void pushCard(const Card* card)
	{
		m_myCards.push_back(card);
	}

	void clearCards()
	{
		m_myCards.clear();
	}

	const std::vector<const Card*>* getMyCards() const
	{
		return &m_myCards;
	}
private:
	std::vector<const Card*> m_myCards;
	bool m_isHuman;

};

