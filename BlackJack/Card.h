#pragma once
#include <string>

class Card
{
public:
	enum class Suit
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
	void setCardGraphic(const std::string& cardGraphicFile);
	std::string getCardGraphic() const;
	int getRank() const { return m_rank; }
private:
	int m_rank;
	Suit m_suit;
	std::string m_cardGraphicFile;
};

