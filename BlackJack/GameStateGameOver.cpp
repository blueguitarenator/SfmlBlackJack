#include "GameStateGameOver.h"
#include "Game.h"

GameStateGameOver::GameStateGameOver(Game* game, PokerTable* table)
	:GameState(game, table)
{
}


GameStateGameOver::~GameStateGameOver()
{
}

GameState* GameStateGameOver::doRun()
{
	m_game->roundOver();
	return m_nextState->init();
}