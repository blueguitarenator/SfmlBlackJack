#pragma once
#include "GameState.h"

class PlayState;

class GameStatePlay : public GameState
{
public:
	//enum class Play
	//{
	//	Hit,
	//	Stay,
	//	Double,
	//	Split,
	//	Unknown,
	//};
	GameStatePlay(Game* game, PokerTable* table);
	~GameStatePlay();

	GameState* run();
	GameState* click(int x, int y);
	void draw();
	void getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer);
	void doInit();
private:
	GameStatePlay(const GameStatePlay&);                 // Prevent copy-construction
	GameStatePlay& operator=(const GameStatePlay&);      // Prevent assignment

	PlayState* m_playState;

};

