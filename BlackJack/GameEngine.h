#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "HitDetector.h"
#include "GameStateNewGame.h"
#include "GameStatePlaceBets.h"
#include "GameStateDeal.h"
#include "GameStatePlay.h"
#include "GameStateDealerHit.h"
#include "GameStatePayout.h"
#include "GameStateGameOver.h"

class GameEngine
{
public:
	GameEngine(Game& game);
	~GameEngine();

	void handlePollEvent();
	void mouseClick(int x, int y);
private:
	// attributes
	Game& m_game;
	GameState* m_state;
	HitDetector m_hitDetector;
	
	GameStateNewGame m_newGame;
	GameStatePlaceBets m_placeBets;
	GameStateDeal m_deal;
	GameStatePlay m_play;
	GameStateDealerHit m_dealerHit;
	GameStatePayout m_payout;
	GameStateGameOver m_gameOver;

	//operations
	void buildGameState();
};

