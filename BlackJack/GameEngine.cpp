#include "GameEngine.h"
#include <iostream>

using namespace std;
using namespace BlackJack;

GameEngine::GameEngine(Game& game)
	:m_game(game)
{
	m_lastState = State::NewGame;
}


GameEngine::~GameEngine()
{
}

void GameEngine::mouseClick(int x, int y)
{
	if (m_lastState == State::PlaceBets)
	{
		int value = m_hitDetector.hitChip(x, y);
		if (value != -1)
		{
			m_game.setPlayerBet(value);
			m_game.paint(m_lastState);
		}

	}

}

void GameEngine::handlePollEvent()
{
	if (m_lastState == State::NewGame)
	{
		m_game.paint(m_lastState);
		m_lastState = State::PlaceBets;
	}
	else if (m_lastState == State::PlaceBets)
	{
		if (m_game.placeBetsDone())
		{
			m_lastState = State::Deal;
			m_game.paint(m_lastState);
		}
	}
	else if (m_lastState == State::Deal)
	{
		m_game.deal();
		m_lastState = State::Play;
		m_game.paint(m_lastState);
	}

}
