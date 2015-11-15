#include "Dealer.h"
#include "Shoe.h"
#include "Player.h"

using namespace BlackJack;

Dealer::Dealer(Shoe* shoe, Player* p1, Player* p2, Player* p3)
	:m_shoe(shoe), m_player1(p1), m_player2(p2), m_player3(p3)
{
	m_downCard.setCardGraphic("back.png");
}

Dealer::~Dealer()
{
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
	return m_showCard;
}

void Dealer::getMyCards(std::vector<const Card*>& cards, BlackJack::State state) const
{
	if (state == State::Payout || state == State::DealerHit)
	{
		cards.push_back(m_holeCard);
		cards.push_back(m_showCard);
	}
	else if (state == State::Deal || state == State::Play)
	{
		cards.push_back(&m_downCard);
		cards.push_back(m_showCard);
	}
	else if (state == State::DealerHit)
	{

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
	m_holeCard = m_shoe->draw();
	m_player1->pushCard(m_shoe->draw());
	m_player2->pushCard(m_shoe->draw());
	m_player3->pushCard(m_shoe->draw());

	m_showCard = m_shoe->draw();
	m_player1->pushCard(m_shoe->draw());
	m_player2->pushCard(m_shoe->draw());
	m_player3->pushCard(m_shoe->draw());
}

bool Dealer::isBust(const std::vector<const Card*>* cards)
{
	int value = m_cardCalculator.getCardValue(cards);
	return value > 21;
}