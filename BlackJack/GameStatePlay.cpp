#include "GameStatePlay.h"
#include "Game.h"
#include "PlayState.h"

using namespace std;

GameStatePlay::GameStatePlay(Game* game, PokerTable* table)
	:GameState(game, table)
{
}


GameStatePlay::~GameStatePlay()
{
}

GameState* GameStatePlay::click(int x, int y)
{
	PlayState::Play p = m_hitDetector.hitPlay(x, y);
	if (p != PlayState::Play::Unknown)
	{
		m_game->setPlayerPlay(p);
	}
	return this;
}

GameState* GameStatePlay::run()
{
	m_game->playForPlayerDone();
	if (m_game->playForRoundDone())
	{
		return m_nextState->init();
	}
	else
	{
		if (m_game->playHit())
		{
			return this;
		}
		else if (m_game->playDouble())
		{
			return this;
		}
	}
	return this;
}

void GameStatePlay::draw()
{
	m_table->drawPlay();
}

void GameStatePlay::getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer)
{
	const vector<const Card*>* dealerCards = dealer->getCards();
	cards.push_back(dealer->getDownCard());
	cards.push_back(dealerCards->at(1));
}