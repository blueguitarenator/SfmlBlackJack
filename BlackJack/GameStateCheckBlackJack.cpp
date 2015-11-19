#include "GameStateCheckBlackJack.h"
#include "Game.h"
#include "GameStatePayout.h"
#include "GameStatePlay.h"
#include <vector>

using namespace std;

GameStateCheckBlackJack::GameStateCheckBlackJack(Game* game, PokerTable* table)
	:GameState(game, table)
{
}


GameStateCheckBlackJack::~GameStateCheckBlackJack()
{
}

void GameStateCheckBlackJack::doInit()
{
	m_nextState = m_play;
}

void GameStateCheckBlackJack::setPayout(GameStatePayout* payout)
{
	m_payout = payout;
}

void GameStateCheckBlackJack::setPlay(GameStatePlay* play)
{
	m_play = play;
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