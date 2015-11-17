#include "HitDetector.h"
#include "BlackJack.h"

using namespace BlackJack;

HitDetector::HitDetector()
{
}


HitDetector::~HitDetector()
{
}

int HitDetector::hitChip(int x, int y) const
{
	if (x > ONE_CHIP_X && x < ONE_CHIP_X + CHIP_RADIUS &&
		y > ONE_CHIP_Y && y < ONE_CHIP_Y + CHIP_RADIUS)
	{
		return 1;
	}
	else if (x > FIVE_CHIP_X && x < FIVE_CHIP_X + CHIP_RADIUS &&
		y > FIVE_CHIP_Y && y < FIVE_CHIP_Y + CHIP_RADIUS)
	{
		return 5;
	}
	else if (x > TEN_CHIP_X && x < TEN_CHIP_X + CHIP_RADIUS &&
		y > TEN_CHIP_Y && y < TEN_CHIP_Y + CHIP_RADIUS)
	{
		return 10;
	}
	else if (x > TWENTYFIVE_CHIP_X && x < TWENTYFIVE_CHIP_X + CHIP_RADIUS &&
		y > TWENTYFIVE_CHIP_Y && y < TWENTYFIVE_CHIP_Y + CHIP_RADIUS)
	{
		return 25;
	}
	else if (x > DONE_CHIP_X && x < DONE_CHIP_X + CHIP_RADIUS &&
		y > DONE_CHIP_Y && y < DONE_CHIP_Y + CHIP_RADIUS)
	{
		return DONE_BET;
	}
	return -1;
}

PlayState::Play HitDetector::hitPlay(int x, int y) const
{
	if (x > HIT_BUTTON_X && x < HIT_BUTTON_X + BUTTON_WIDTH &&
		y > BUTTON_Y && y < BUTTON_Y + BUTTON_HEIGHT)
	{
		return PlayState::Play::Hit;
	}
	else if (x > STAY_BUTTON_X && x < STAY_BUTTON_X + BUTTON_WIDTH &&
		y > BUTTON_Y && y < BUTTON_Y + BUTTON_HEIGHT)
	{
		return PlayState::Play::Stay;
	}
	else if (x > DOUBLE_BUTTON_X && x < DOUBLE_BUTTON_X + BUTTON_WIDTH &&
		y > BUTTON_Y && y < BUTTON_Y + BUTTON_HEIGHT)
	{
		return PlayState::Play::Double;
	}

	return PlayState::Play::Unknown;
}

bool HitDetector::hitContinue(int x, int y) const
{
	if (x > HIT_BUTTON_X && x < HIT_BUTTON_X + BUTTON_WIDTH &&
		y > BUTTON_Y && y < BUTTON_Y + BUTTON_HEIGHT)
	{
		return true;
	}
	return false;
}