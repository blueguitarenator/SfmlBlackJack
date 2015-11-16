#pragma once
#include <limits>

// black jack need to be excluded from payout
// play state is running away after first round
namespace BlackJack
{
	static const int DONE_BET = INT_MAX;
	static const float ONE_CHIP_X = 10.0f;
	static const float ONE_CHIP_Y = 900.0f;
	static const float FIVE_CHIP_X = 110.0f;
	static const float FIVE_CHIP_Y = 900.0f;
	static const float TEN_CHIP_X = 210.0f;
	static const float TEN_CHIP_Y = 900.0f;
	static const float TWENTYFIVE_CHIP_X = 310.0f;
	static const float TWENTYFIVE_CHIP_Y = 900.0f;
	static const float DONE_CHIP_X = 410.0f;
	static const float DONE_CHIP_Y = 900.0f;
	static const float CHIP_RADIUS = 100.0f;

	static const int BUTTON_WIDTH = 150;
	static const int BUTTON_HEIGHT = 50;
	static const float HIT_BUTTON_X = 10.0f;
	static const float BUTTON_Y = 900.0f;
	static const float STAY_BUTTON_X = 160.0f;
	static const float DOUBLE_BUTTON_X = 310.0f;
	static const float SPLIT_BUTTON_X = 470.0f;

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

	enum class State
	{
		NewGame,
		PlaceBets,
		Deal,
		CheckForBlackJack,
		Play,
		DealerHit,
		Payout,
		GameOver,
		NextPlayer
	};
}