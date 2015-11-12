#pragma once
#include <string>

class Card
{
public:
	enum Suit
	{
		HEART,
		DIAMOND,
		SPADE,
		CLUB
	};

	enum Rank
	{
		Ace = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King
	};

	Card();
	~Card();

	void init(Rank value, Suit suit);
	std::string cardToString() const;
	void setCardGraphic(const std::string& cardGraphicFile);
	std::string getCardGraphic() const;

private:
	int m_rank;
	Suit m_suit;
	std::string m_cardGraphicFile;
};

