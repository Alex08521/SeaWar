#pragma once
class Player
{
protected:
	short SHIPFIELD[11][11];
	short PLAYFIELD[11][11];
	short onedeckship;
	short twodeckship;
	short threedeckship;
	short fourdeckship;
	bool loose;
	bool turn;
public:
	Player();
	~Player();
	void giveTurn();
	void passTurn();
	bool turnIsGiven();
	bool isLooser();
	bool underFire(short X, short Y);
	short howManyFourdeck();
	short howManyThreedeck();
	short howManyTwodeck();
	short howManyOnedeck();
	enum shiptype { onedeck = 12, twodeck, threedeck, fourdeck, wreckeddeck, miss };
};

