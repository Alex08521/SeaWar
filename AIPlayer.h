#pragma once
#include "Player.h"
#include "LightRand.h"
#include "twoPoints.h"
#include <iostream>

class AIPlayer :
    public Player
{
protected:
    twoPoints point[100];
    twoPoints myPoint[100];
    LightRand random;
    twoPoints coordinatesforfire;
    twoPoints coordinatesforshipstand;
    twoPoints iShootSomewhereIn;
    int sizeOfPointsArray;
    int sizeOfMyPointsArray;
    int chekcer;
    int strikes;
    bool iShootSomewhere;
    bool match(twoPoints forMatching);
    void forgotThisCoordinates(int forgot);
    void forgotThisMyShipCoordinates(int forgot);
    int getNumOfElement(twoPoints forFinding);
    int getNumOfMyElement(int pnt1, int pnt2);
    bool correct(int x, int y, const char ignore[]);
public:
    AIPlayer();
    ~AIPlayer();
    bool doChoise();
    twoPoints shooting();
    bool isIMissed(bool missed);
    bool setFourdeckShip();
    bool setThreedeckShip();
    bool setTwodeckShip();
    bool setOnedeckShip();
};

