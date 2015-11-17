#pragma once
#include "PlayerBank.h"

class PlayState
{
public:
	enum class Play
	{
		Hit,
		Stay,
		Split,
		Double,
		Bust,
		BlackJack,
		Unknown
	};

	PlayState();
	~PlayState();

	void init();
	void setState(Play state);
	void setChoice(PlayerBank& bank, Play choice);
	Play getChoice() const;

private:
	Play m_state;
};

