#include "HPlayer.h"

HPlayer::HPlayer() : Player()
{
	numOfTurn = 0;
}

HPlayer::~HPlayer()
{
}

int HPlayer::GetShipFieldElement( int x, int y)
{
	return SHIPFIELD[y][x];
}

bool HPlayer::SetShipFieldElement(int x, int y, int set)
{
	if (SHIPFIELD[y][x] != onedeck || SHIPFIELD[y][x] != twodeck || SHIPFIELD[y][x] != threedeck || SHIPFIELD[y][x] != fourdeck || SHIPFIELD[y][x] != wreckeddeck || SHIPFIELD[y][x] != miss)
	{
		SHIPFIELD[y][x] = set;
		return true;
	}
	return false;
}

int HPlayer::GetPlayFieldElement(int x, int y)
{
	return PLAYFIELD[y][x];
}

bool HPlayer::SetPlayFieldElement(int x, int y, int set)
{
	if (PLAYFIELD[y][x] != onedeck || PLAYFIELD[y][x] != twodeck || PLAYFIELD[y][x] != threedeck || PLAYFIELD[y][x] != fourdeck || PLAYFIELD[y][x] != wreckeddeck || PLAYFIELD[y][x] != miss)
	{
		PLAYFIELD[y][x] = set;
		return true;
	}
	return false;
}
