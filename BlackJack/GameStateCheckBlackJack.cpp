#include "GameStateCheckBlackJack.h"
#include "Game.h"
#include "GameStatePayout.h"
#include <vector>

using namespace std;

GameStateCheckBlackJack::GameStateCheckBlackJack(Game* game, PokerTable* table)
	:GameState(game, table)
{
}


GameStateCheckBlackJack::~GameStateCheckBlackJack()
{
}

void GameStateCheckBlackJack::setPayout(GameStatePayout* payout)
{
	m_payout = payout;
}

GameState* GameStateCheckBlackJack::run()
{
	Dealer* dealer = m_game->getDealer();
	if (m_cardCalculator.getCardValue(dealer->getCards()) == 21)
	{
		m_nextState = m_payout->init();
	}
	else
	{
		vector<Player*> players;
		dealer->getPlayers(players);
		for (auto p : players)
		{
			int playerValue = m_cardCalculator.getCardValue(p->getMyCards());
			if (playerValue == 21)
			{
				dealer->payout(p, true);
			}
		}
		m_game->initFirstPlayer();
	}
	return m_nextState->init();
}