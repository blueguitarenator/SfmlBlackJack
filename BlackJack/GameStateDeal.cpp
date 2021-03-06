#include "GameStateDeal.h"
#include "Game.h"

using namespace std;

GameStateDeal::GameStateDeal(Game* game, PokerTable* table)
	:GameState(game, table)
{
}

GameStateDeal::~GameStateDeal()
{
}

GameState* GameStateDeal::doRun()
{
	m_game->deal();
	return m_nextState->init();
}

void GameStateDeal::getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer)
{
	const vector<const Card*>* dealerCards = dealer->getCards();
	cards.push_back(dealer->getDownCard());
	cards.push_back(dealerCards->at(1));
}