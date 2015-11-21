#pragma once

class Player;
class PlayState;

class Robot
{
public:
	Robot();
	~Robot();

	void makeBet(Player* player);
	PlayState* play(PlayState* play);
};

