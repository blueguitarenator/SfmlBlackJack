#include "GameEngine.h"
#include "GameState.h"
#include <iostream>

using namespace std;
using namespace BlackJack;

GameEngine::GameEngine(Game& game)
	:m_game(game), 
	m_newGame(&game, game.getTable()),
	m_placeBets(&game, game.getTable()),
	m_deal(&game, game.getTable()),
	m_checkBlackJack(&game, game.getTable()),
	m_play(&game, game.getTable()),
	m_dealerHit(&game, game.getTable()),
	m_payout(&game, game.getTable()),
	m_gameOver(&game, game.getTable())
{
	buildGameState();
	m_state = &m_newGame;
}


GameEngine::~GameEngine()
{
}

void GameEngine::mouseClick(int x, int y)
{
	m_state = m_state->doClick(x, y);

}

void GameEngine::handlePollEvent()
{
	m_state = m_state->doRun();
}

void GameEngine::buildGameState()
{
	m_newGame.setNextState(&m_placeBets);
	m_placeBets.setNextState(&m_deal);
	m_deal.setNextState(&m_checkBlackJack);
	m_checkBlackJack.setNextState(&m_play);
	m_checkBlackJack.setPayout(&m_payout);
	m_checkBlackJack.setPlay(&m_play);
	m_play.setNextState(&m_dealerHit);
	m_dealerHit.setNextState(&m_payout);
	m_payout.setNextState(&m_gameOver);
	m_gameOver.setNextState(&m_newGame);
}