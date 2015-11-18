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
	//HitDetector::Play p = m_hitDetector.hitPlay(x, y);
	//if (p == HitDetector::Play::Hit)
	//{

		//m_game->setPlayerPlay(p);
	//}
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
	//m_game->playForPlayerDone();
	//if (m_game->playForRoundDone())
	//{
	//	return m_nextState->init();
	//}
	//else
	//{
	//	if (m_game->playHit())
	//	{
	//		return this;
	//	}
	//	else if (m_game->playDouble())
	//	{
	//		return this;
	//	}
	//}
	return this;
}

void GameStatePlay::draw()
{
	m_playState->draw();
}

void GameStatePlay::getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer)
{
	const vector<const Card*>* dealerCards = dealer->getCards();
	cards.push_back(dealer->getDownCard());
	cards.push_back(dealerCards->at(1));
}