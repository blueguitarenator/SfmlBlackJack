#pragma once

#include "PlayState.h"

class HitDetector
{
public:
	HitDetector();
	~HitDetector();

	int hitChip(int x, int y) const;
	PlayState::Play hitPlay(int x, int y) const;
	bool hitContinue(int x, int y) const;
};

