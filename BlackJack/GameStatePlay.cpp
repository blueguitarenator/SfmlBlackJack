#include "GameStatePlay.h"
#include "BlackJack.h"
#include "Game.h"

using namespace BlackJack;
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
	Play p = m_hitDetector.hitPlay(x, y);
	if (p != Play::Unknown)
	{
		m_game->setPlayerPlay(p);
		m_game->paint(this);
	}
	return this;
}

GameState* GameStatePlay::run()
{
	//	if (m_game.playForPlayerDone())
	//	{
	//		m_game.paint(m_gameState);
	//	}
	//	if (m_game.playForRoundDone())
	//	{
	//		m_gameState = State::DealerHit;
	//		m_game.paint(m_gameState);
	//	}
	//	else if (m_game.playHit())
	//	{
	//		m_game.paint(m_gameState);
	//	}
	//	else if (m_game.playDouble())
	//	{
	//		m_game.paint(m_gameState);
	//	}

	GameState* state = this;
	if (m_game->playForPlayerDone())
	{
		m_game->paint(this);
	}
	if (m_game->playForRoundDone())
	{
		m_game->paint(this);
		state = m_nextState->init();
	}
	else if (m_game->playHit())
	{
		m_game->paint(this);
	}
	else if (m_game->playDouble())
	{
		m_game->paint(this);
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