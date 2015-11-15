#pragma once
#include <limits>

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
	static const int CHIP_RADIUS = 100;

	enum class Play
	{
		Hit,
		Stay,
		Split,
		Double,
		Unknown
	};

	enum class State
	{
		NewGame,
		PlaceBets,
		Deal,
		Play,
		DealerHit,
		Payout,
		GameOver,
	};
}