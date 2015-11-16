#pragma once
class PlayerBank
{
public:
	PlayerBank();
	~PlayerBank();

	void incrementBet(int value);
	int getBet() const;
	int getBank() const;
	int busted();
	void setWinnings(float value);
	float getWinnings() const { return m_winnings; }
	void gameOver();
private:
	int m_bank;
	int m_bet;
	float m_winnings;
};

