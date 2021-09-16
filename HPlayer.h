#pragma once
#include "Player.h"
#include "twoPoints.h"
#include "SFML/Graphics.hpp"
class HPlayer :
    public Player
{
protected:
    twoPoints points[100];
    int numOfTurn;
public:
    HPlayer();
    ~HPlayer();
    int GetShipFieldElement(int x, int y);
    bool SetShipFieldElement(int x, int y, int set);
    int GetPlayFieldElement(int x, int y);
    bool SetPlayFieldElement(int x, int y, int set);

};

