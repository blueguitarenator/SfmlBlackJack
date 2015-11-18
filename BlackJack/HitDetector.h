#pragma once

class HitDetector
{
public:

	HitDetector();
	~HitDetector();

	int hitChip(int x, int y) const;
	bool hitContinue(int x, int y) const;
	bool hitHit(int x, int y) const;
	bool hitStay(int x, int y) const;
	bool hitDouble(int x, int y) const;
	bool hitSplit(int x, int y) const;

};

