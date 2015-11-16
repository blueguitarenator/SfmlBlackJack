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

GameState* GameStateDeal::run()
{
	m_game->deal();
	m_game->checkBlackJack();
	m_game->paint(this);
	m_game->initFirstPlayer();
	return m_nextState->init();
}

void GameStateDeal::getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer)
{
	const vector<const Card*>* dealerCards = dealer->getCards();
	cards.push_back(dealer->getDownCard());
	cards.push_back(dealerCards->at(1));
}