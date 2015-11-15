#include "GameEngine.h"
#include <iostream>

using namespace std;
using namespace BlackJack;

GameEngine::GameEngine(Game& game)
	:m_game(game)
{
	m_gameState = State::NewGame;
}


GameEngine::~GameEngine()
{
}

void GameEngine::mouseClick(int x, int y)
{
	if (m_gameState == State::PlaceBets)
	{
		int value = m_hitDetector.hitChip(x, y);
		if (value != -1)
		{
			m_game.setPlayerBet(value);
			m_game.paint(m_gameState);
		}
	}
	else if (m_gameState == State::Play)
	{
		Play p = m_hitDetector.hitPlay(x, y);
		if (p != Play::Unknown)
		{
			m_game.setPlayerPlay(p);
			m_game.paint(m_gameState);
		}
	}
}

void GameEngine::handlePollEvent()
{
	if (m_gameState == State::NewGame)
	{
		m_gameState = State::PlaceBets;
		m_game.paint(m_gameState);
	}
	else if (m_gameState == State::PlaceBets)
	{
		if (m_game.placeBetsDone())
		{
			m_gameState = State::Deal;
			m_game.paint(m_gameState);
		}
	}
	else if (m_gameState == State::Deal)
	{
		m_game.deal();
		m_gameState = State::Play;
		m_game.paint(m_gameState);
	}
	else if (m_gameState == State::Play)
	{
		if (m_game.playDone())
		{
			m_gameState = State::DealerHit;
			m_game.paint(m_gameState);
		}
		else if (m_game.playHit())
		{
			m_game.paint(m_gameState);
		}
		else if (m_game.playDouble())
		{
			m_game.paint(m_gameState);
		}
	}

}
