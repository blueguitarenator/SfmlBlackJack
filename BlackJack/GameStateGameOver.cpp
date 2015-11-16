#include "GameStateGameOver.h"
#include "Game.h"

GameStateGameOver::GameStateGameOver(Game* game, PokerTable* table)
	:GameState(game, table)
{
}


GameStateGameOver::~GameStateGameOver()
{
}

GameState* GameStateGameOver::run()
{
	m_game->roundOver();
	m_game->paint(this);
	return m_nextState->init();
}