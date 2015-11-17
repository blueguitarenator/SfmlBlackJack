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

GameState* GameState::doRun()
{
	GameState* state = run();
	m_game->paint(this);
	return state;
}

GameState* GameState::doClick(int x, int y)
{
	GameState* state = click(x, y);
	m_game->paint(this);
	return state;
}

void GameState::setNextState(GameState* state)
{
	m_nextState = state;
}

GameState* GameState::init()
{
	m_done = false;
	doInit();
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