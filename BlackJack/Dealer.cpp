#include "Dealer.h"

#include "Deck.h"
#include "Player.h"
#include "Card.h"

Dealer::Dealer(Deck* deck, Player* p1, Player* p2, Player* p3)
	:m_deck(deck), m_player1(p1), m_player2(p2), m_player3(p3)
{
}

Dealer::~Dealer()
{
}

void Dealer::newGame()
{
	m_myCards.clear();
	m_player1->clearCards();
	m_player2->clearCards();
	m_player3->clearCards();
	//m_table->setCard(nullptr, PokerTable::DealerHole);
	//m_table->setCard(nullptr, PokerTable::DealerSpread);
	//m_table->setCard(nullptr, PokerTable::P1_1);
	//m_table->setCard(nullptr, PokerTable::P1_2);
	//m_table->setCard(nullptr, PokerTable::P2_1);
	//m_table->setCard(nullptr, PokerTable::P2_2);
	//m_table->setCard(nullptr, PokerTable::P3_1);
	//m_table->setCard(nullptr, PokerTable::P3_2);
}

void Dealer::deal()
{
	m_myCards.push_back(m_deck->draw());
	m_player1->pushCard(m_deck->draw());
	m_player2->pushCard(m_deck->draw());
	m_player3->pushCard(m_deck->draw());

	m_myCards.push_back(m_deck->draw());
	m_player1->pushCard(m_deck->draw());
	m_player2->pushCard(m_deck->draw());
	m_player3->pushCard(m_deck->draw());


	//m_table->setCard(m_deck->draw(), PokerTable::DealerHole);
	//m_table->setCard(m_deck->draw(), PokerTable::P1_1);
	//m_table->setCard(m_deck->draw(), PokerTable::P2_1);
	//m_table->setCard(m_deck->draw(), PokerTable::P3_1);
	//m_table->setCard(m_deck->draw(), PokerTable::DealerSpread);
	//m_table->setCard(m_deck->draw(), PokerTable::P1_2);
	//m_table->setCard(m_deck->draw(), PokerTable::P2_2);
	//m_table->setCard(m_deck->draw(), PokerTable::P3_2);
}
