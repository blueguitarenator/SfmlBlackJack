#pragma once
#include <vector>
class Card;

class MyCards
{
public:
	MyCards();
	~MyCards();

	void clear() 
	{ 
		m_spread.clear(); 
		m_holeCard = nullptr;
	}

	void setHole(const Card* card)
	{
		m_holeCard = card;
	}

	const Card* getHoleCard() const { return m_holeCard; }

	void addSpread(const Card* card)
	{
		m_spread.push_back(card);
	}

	const std::vector<const Card*> getSpread() const { return m_spread; }


private:
	const Card* m_holeCard;
	std::vector<const Card*> m_spread;

};

