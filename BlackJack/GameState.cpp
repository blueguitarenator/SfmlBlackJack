#include "GameState.h"
#include "Game.h"
#include "Dealer.h"
#include "Card.h"

using namespace std;

GameState::GameState(Game* game, PokerTable* table)
	:m_game(game), m_table(table)
{
	m_done = false;
}


GameState::~GameState()
{
}

void GameState::setNextState(GameState* state)
{
	m_nextState = state;
}

GameState* GameState::init()
{
	m_done = false;
	return this;
}

void GameState::getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer)
{
	const vector<const Card*>* dealerCards = dealer->getCards();
	for (const auto c : *dealerCards)
	{
		cards.push_back(c);
	}
}

GameState* GameState::click(int x, int y)
{
	return this;
}

void GameState::draw()
{
}