#pragma once

#include "BlackJack.h"

class HitDetector
{
public:
	HitDetector();
	~HitDetector();

	int hitChip(int x, int y) const;
	BlackJack::Play hitPlay(int x, int y) const;
	bool hitContinue(int x, int y) const;
};

