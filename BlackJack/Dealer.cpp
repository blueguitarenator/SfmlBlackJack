#include "Dealer.h"
#include "Shoe.h"
#include "Player.h"
#include "GameState.h"
#include "PlayState.h"

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

void Dealer::getPlayers(vector<Player*>& players) const
{
	players.push_back(m_player1);
	players.push_back(m_player2);
	players.push_back(m_player3);
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