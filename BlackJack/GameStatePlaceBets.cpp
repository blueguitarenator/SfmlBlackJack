#include "GameStatePlaceBets.h"
#include "Game.h"
#include "PlayState.h"

GameStatePlaceBets::GameStatePlaceBets(Game* game, PokerTable* table)
	:GameState(game, table)
{
}


GameStatePlaceBets::~GameStatePlaceBets()
{
}

void GameStatePlaceBets::doInit()
{
	m_playState = m_game->initBetState();
}

GameState* GameStatePlaceBets::doRobot()
{
	m_playState = m_playState->robotAction();
	return this;
}

GameState* GameStatePlaceBets::doClick(int x, int y)
{	
	m_playState = m_playState->click(x, y);
	return this;
}

GameState* GameStatePlaceBets::doRun()
{
	if (m_playState == nullptr)
	{
		return m_nextState->init();
	}
	else if (m_game->getActivePlayer()->isRobot())
	{

	}
	return this;
}

void GameStatePlaceBets::draw()
{
	m_table->drawChips();
	if (m_playState != nullptr)
	{
		m_playState->draw();
	}
}
