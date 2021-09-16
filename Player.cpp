#include "Player.h"

Player::Player()
{
	onedeckship = 4;
	twodeckship = 3;
	threedeckship = 2;
	fourdeckship = 1;
	loose = false;
	turn = false;
	SHIPFIELD[0][0] = 22;
	PLAYFIELD[0][0] = 22;

	int x = 1;
	int y = 1;

	for (x = 1; x < 11; x++)
	{
		SHIPFIELD[0][x] = 22;
	}

	for (y = 1; y < 11; y++)
	{
		SHIPFIELD[y][0] = 22;
	}

	x = 1;
	y = 1;

	for (x = 1; x < 11; x++)
	{
		PLAYFIELD[0][x] = 22;
	}

	for (y = 1; y < 11; y++)
	{
		PLAYFIELD[y][0] = 22;
	}

	x = 1;
	y = 1;

	while (y < 11)
	{
		if (x > 10)
		{
			y += 1;
			x = 0;
		}
		SHIPFIELD[y][x] = 0;
		PLAYFIELD[y][x] = 0;
		x += 1;
	}
}

Player::~Player()
{
}

void Player::giveTurn()
{
	if (turn == false)
	{
		turn = true;
	}
}

void Player::passTurn()
{
	turn = false;
}

bool Player::turnIsGiven()
{
	return turn;
}

bool Player::isLooser()
{
	return loose;
}

bool Player::underFire(short X, short Y)
{
	bool founded = false;
	bool destroyed = false;
	if (SHIPFIELD[Y][X] == onedeck || SHIPFIELD[Y][X] == twodeck || SHIPFIELD[Y][X] == threedeck || SHIPFIELD[Y][X] == fourdeck)
	{
		if (SHIPFIELD[Y][X] == onedeck)
		{
			founded = true;
			onedeckship--;
		}
		else if (SHIPFIELD[Y][X] == twodeck)
		{
			founded = true;
			if (Y - 1 > 0)
			{
				if (SHIPFIELD[Y - 1][X] == wreckeddeck)
				{
					destroyed = true;
				}
			}
			if (Y + 1 < 11)
			{
				if (SHIPFIELD[Y + 1][X] == wreckeddeck)
				{
					destroyed = true;
				}
			}
			if (X + 1 < 11)
			{
				if (SHIPFIELD[Y][X + 1] == wreckeddeck)
				{
					destroyed = true;
				}
			}
			if (X - 1 > 0)
			{
				if (SHIPFIELD[Y][X - 1] == wreckeddeck)
				{
					destroyed = true;
				}
			}
			if (destroyed)
			{
				twodeckship--;	
			}
			
		}
		else if (SHIPFIELD[Y][X] == threedeck)
		{
			founded = true;
			if (Y - 1 > 0)
			{
				if (SHIPFIELD[Y - 1][X] == wreckeddeck)
				{
					if (Y + 1 < 11)
					{
						if (SHIPFIELD[Y + 1][X] == wreckeddeck)
						{
							destroyed = true;
						}
					}
					if (Y - 2 > 0)
					{
						if (SHIPFIELD[Y - 2][X] == wreckeddeck)
						{
							destroyed = true;
						}
					}
				}
			}
			if (Y + 1 < 11)
			{
				if (SHIPFIELD[Y + 1][X] == wreckeddeck)
				{
					if (Y - 1 > 0)
					{
						if (SHIPFIELD[Y - 1][X] == wreckeddeck)
						{
							destroyed = true;
						}
					}
					if (Y + 2 < 11)
					{
						if (SHIPFIELD[Y + 2][X] == wreckeddeck)
						{
							destroyed = true;
						}
					}
				}
			}
			if (X + 1 < 11)
			{
				if (SHIPFIELD[Y][X + 1] == wreckeddeck)
				{
					if (X - 1 > 0)
					{
						if (SHIPFIELD[Y][X - 1] == wreckeddeck)
						{
							destroyed = true;
						}
					}
					if (X + 2 < 11)
					{
						if (SHIPFIELD[Y][X + 2] == wreckeddeck)
						{
							destroyed = true;
						}
					}
				}
			}			
			if (X - 1 > 0)
			{
				if (SHIPFIELD[Y][X - 1] == wreckeddeck)
				{
					if (X + 1 < 11)
					{
						if (SHIPFIELD[Y][X + 1] == wreckeddeck)
						{
							destroyed = true;
						}
					}
					if (X - 2 > 0)
					{
						if (SHIPFIELD[Y][X - 2] == wreckeddeck)
						{
							destroyed = true;
						}
					}
				}
			}
			if (destroyed)
			{
				threedeckship --;
			}
					
		}
		else if (SHIPFIELD[Y][X] == fourdeck)
		{
			founded = true;
			if (Y - 1 > 0)
			{
				if (SHIPFIELD[Y - 1][X] == wreckeddeck)
				{
					if (Y + 1 < 11 && Y - 2 > 0)
					{
						if (SHIPFIELD[Y + 1][X] == wreckeddeck && SHIPFIELD[Y - 2][X] == wreckeddeck)
						{
							destroyed = true;
						}
					}
					if (Y - 2 > 0 && Y - 3 > 0)
					{
						if (SHIPFIELD[Y - 2][X] == wreckeddeck && SHIPFIELD[Y - 3][X] == wreckeddeck)
						{
							destroyed = true;
						}
					}
				}
			}
			if (Y + 1 < 11)
			{
				if (SHIPFIELD[Y + 1][X] == wreckeddeck)
				{
					if (Y - 1 > 0 && Y + 2 > 11)
					{
						if (SHIPFIELD[Y - 1][X] == wreckeddeck && SHIPFIELD[Y + 2][X] == wreckeddeck)
						{
							destroyed = true;
						}
					}
					if (Y + 3 < 11 && Y + 2 > 11)
					{
						if (SHIPFIELD[Y + 3][X] == wreckeddeck && SHIPFIELD[Y + 2][X] == wreckeddeck)
						{
							destroyed = true;
						}
					}
				}
			}
			if (X + 1 < 11)
			{
				if (SHIPFIELD[Y][X + 1] == wreckeddeck)
				{
					if (X - 1 > 0 && X + 2 < 11)
					{
						if (SHIPFIELD[Y][X - 1] == wreckeddeck && SHIPFIELD[Y][X + 2] == wreckeddeck)
						{
							destroyed = true;
						}
					}
					if (X + 3 < 11 && X + 2 < 11)
					{
						if (SHIPFIELD[Y][X + 3] == wreckeddeck && SHIPFIELD[Y][X + 2] == wreckeddeck)
						{
							destroyed = true;
						}
					}
				}
			}
			if (X - 1 > 0)
			{
				if (SHIPFIELD[Y][X - 1] == wreckeddeck)
				{
					if (X + 1 < 11 && X - 2 > 0)
					{
						if (SHIPFIELD[Y][X + 1] == wreckeddeck && SHIPFIELD[Y][X - 2] == wreckeddeck)
						{
							destroyed = true;
						}
					}
					if (X - 3 > 0 && X - 2 > 0)
					{
						if (SHIPFIELD[Y][X - 3] == wreckeddeck && SHIPFIELD[Y][X - 2] == wreckeddeck)
						{
							destroyed = true;
						}
					}
				}
			}

			if (destroyed)
			{
				fourdeckship --;
			}
		}
		
	}
	if (founded)
	{
		SHIPFIELD[Y][X] == wreckeddeck;
	}
	if (onedeckship == 0 && twodeckship == 0 && threedeckship == 0 && fourdeckship == 0)
	{
		loose = true;
	}
	return founded;
}

short Player::howManyFourdeck()
{
	return fourdeckship;
}

short Player::howManyThreedeck()
{
	return threedeckship;
}

short Player::howManyTwodeck()
{
	return twodeckship;
}

short Player::howManyOnedeck()
{
	return onedeckship;
}
