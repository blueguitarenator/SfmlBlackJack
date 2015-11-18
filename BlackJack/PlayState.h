#pragma once
#include "PlayerBank.h"
#include "HitDetector.h"
#include "CardCalculator.h"

class Player;
class PokerTable;
class Game;

class PlayState
{
public:
	//enum class Play
	//{
	//	Hit,
	//	Stay,
	//	Split,
	//	Double,
	//	Bust,
	//	BlackJack,
	//	Unknown
	//};

	PlayState(Game* game, PokerTable* table);
	~PlayState();
	void init(Player* p);
	virtual PlayState* execute() = 0;
	void draw();
	virtual PlayState* click(int x, int y);
	const Player* getPlayer() const { return m_player; }

	//void init();
	//void setState(Play state);
	//void setChoice(PlayerBank& bank, Play choice);
	//Play getChoice() const;

protected:
	//Play m_state;
	//PlayState* m_nextPlayState;
	Player* m_player;
	HitDetector m_hitDetector;
	PokerTable* m_table;
	Game* m_game;
	CardCalculator m_cardCalculator;

	// operations
	virtual void doDraw() = 0;

};

