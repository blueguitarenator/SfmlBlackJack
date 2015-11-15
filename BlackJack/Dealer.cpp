#include "Dealer.h"
#include "Shoe.h"
#include "Player.h"

using namespace BlackJack;
using namespace std;

Dealer::Dealer(Shoe* shoe, Player* p1, Player* p2, Player* p3)
	:m_shoe(shoe), m_player1(p1), m_player2(p2), m_player3(p3)
{
	m_downCard.setCardGraphic("back.png");
}

Dealer::~Dealer()
{
}

bool Dealer::hitPastSoft17()
{
	int value = m_cardCalculator.getCardValue(&m_myCards);
	if (m_cardCalculator.isLessThanEqualToSoft17(&m_myCards))
	{
		m_myCards.push_back(m_shoe->draw());
		return false;
	}
	return true;
}

void Dealer::hit(Player* player)
{
	player->pushCard(m_shoe->draw());
	if (isBust(player->getMyCards()))
	{
		player->setPlayChoice(Play::Bust);
	}
}

const Card* Dealer::getShowCard() const
{
	return m_myCards.at(1);// m_showCard;
}

void Dealer::getMyCards(vector<const Card*>& cards, BlackJack::State state) const
{
	if (m_myCards.size() > 1)
	{
		if (state == State::Deal || state == State::Play)
		{
			cards.push_back(&m_downCard);
			cards.push_back(m_myCards.at(1));
		}
		else
		{
			for (auto c : m_myCards)
			{
				cards.push_back(c);
			}
		}
	}
}

void Dealer::newGame()
{
	m_myCards.clear();
	m_player1->clearCards();
	m_player2->clearCards();
	m_player3->clearCards();
}

void Dealer::deal()
{
	// try catch here
	m_myCards.push_back(m_shoe->draw());
	m_player1->pushCard(m_shoe->draw());
	m_player2->pushCard(m_shoe->draw());
	m_player3->pushCard(m_shoe->draw());

	m_myCards.push_back(m_shoe->draw());
	m_player1->pushCard(m_shoe->draw());
	m_player2->pushCard(m_shoe->draw());
	m_player3->pushCard(m_shoe->draw());
}

bool Dealer::isBust(const std::vector<const Card*>* cards)
{
	int value = m_cardCalculator.getCardValue(cards);
	return value > 21;
}