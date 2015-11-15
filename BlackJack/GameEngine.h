#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "HitDetector.h"
#include "BlackJack.h"

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
	BlackJack::State m_gameState;
	HitDetector m_hitDetector;

	//operations

};

