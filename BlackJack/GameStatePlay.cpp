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
		m_game->paint(this);
	}
	return this;
}

GameState* GameStatePlay::run()
{
	GameState* state = this;
	m_game->playForPlayerDone();
	if (m_game->playForRoundDone())
	{
		state = m_nextState->init();
	}
	else
	{
		if (m_game->playHit())
		{
			m_game->paint(this);
		}
		else if (m_game->playDouble())
		{
			m_game->paint(this);
		}
	}
	m_game->paint(this);
	return state;
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