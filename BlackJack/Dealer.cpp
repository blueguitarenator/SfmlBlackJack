#include "Dealer.h"
#include "Shoe.h"
#include "Player.h"
#include "GameState.h"

using namespace BlackJack;
using namespace std;

Dealer::Dealer(Shoe* shoe, Player* p1, Player* p2, Player* p3)
	:m_shoe(shoe), m_player1(p1), m_player2(p2), m_player3(p3), m_bank(0)
{
	m_downCard.setCardGraphic("back.png");
}

Dealer::~Dealer()
{
}

void Dealer::gameOver()
{
	m_myCards.clear();
}

bool Dealer::checkDealerBlackJack()
{
	int dealerValue = m_cardCalculator.getCardValue(&m_myCards);
	return dealerValue == 21;
}

void Dealer::checkBlackJack(Player* player)
{
	int playerValue = m_cardCalculator.getCardValue(player->getMyCards());
	if (playerValue == 21)
	{
		payout(player, true);
		player->setPlayChoice(Play::BlackJack);
	}
}

void Dealer::payout(Player* player, bool blackJack)
{
	int bet = player->getBet();
	if (blackJack)
	{
		float bj = bet * 1.5f;
		m_bank -= bj;
		player->setWinnings(bj);
	}
	else if (bet > 0)
	{
		int playerValue = m_cardCalculator.getCardValue(player->getMyCards());
		int dealerValue = m_cardCalculator.getCardValue(&m_myCards);
	
		if (dealerValue > 21 || playerValue > dealerValue)
		{
			m_bank -= bet;
			player->setWinnings(bet);
		}
		else if (dealerValue == playerValue)
		{
			player->setWinnings(0.0f);
		}
		else
		{
			m_bank += bet;
			player->setWinnings(-(bet));
		}
	}
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
		m_bank += player->busted();
	}
}

const Card* Dealer::getShowCard() const
{
	return m_myCards.at(1);
}

const vector<const Card*>* Dealer::getCards() const
{
	return &m_myCards;
}

const Card* Dealer::getDownCard() const
{
	return &m_downCard;
}

void Dealer::getMyCards(vector<const Card*>& cards, GameState* state) const
{
	//m_myCards.clear();
	//Card* ace = new Card();
	//Card* king = new Card();
	//ace->init(Card::Rank::Ace, Card::Suit::CLUB);
	//king->init(Card::Rank::King, Card::Suit::CLUB);
	//ace->setCardGraphic("ace_of_clubs.png");
	//king->setCardGraphic("king_of_clubs2.png");
	//m_myCards.push_back(ace);
	//m_myCards.push_back(king);
	if (m_myCards.size() > 1)
	{
		state->getDealerCards(cards, this);
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