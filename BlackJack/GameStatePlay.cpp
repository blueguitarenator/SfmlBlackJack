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

void GameStatePlay::doInit()
{
	m_playState = m_game->initPlayState();
}

GameState* GameStatePlay::click(int x, int y)
{
	m_playState = m_playState->click(x, y);
	return this;
}

GameState* GameStatePlay::run()
{
	m_playState = m_playState->execute();
	if (m_playState == nullptr)
	{
		return m_nextState->init();
	}
	return this;
}

void GameStatePlay::draw()
{
	if (m_playState != nullptr)
	{
		m_playState->draw();
	}
}

void GameStatePlay::getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer)
{
	const vector<const Card*>* dealerCards = dealer->getCards();
	cards.push_back(dealer->getDownCard());
	cards.push_back(dealerCards->at(1));
}