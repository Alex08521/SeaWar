//Created by Alexandr Pluzhinskyi 2020//
///////////////////////////////////////

#include "LightRand.h"

LightRand::LightRand()
{
	int* random = new int;
	rand = *random;
	delete random;
	checker = 0;
	prevVol1 = 0;
	prevVol2 = 0;
	prevVol3 = 0;
	limMin = 0;
	limMax = 100;
	volume = (limMax) - limMin;
	modulator = time.tm_sec;
	correlator = time.tm_sec;
	if (rand < 0) { rand = rand * (-1); }
}

LightRand::LightRand(int min, int max, int seed)
{
	int* random = new int;
	rand = *random;
	delete random;
	checker = 0;
	prevVol1 = 0;
	prevVol2 = 0;
	prevVol3 = 0;
	limMin = min;
	limMax = max;
	volume = limMax - limMin;
	modulator = time.tm_sec;
	correlator = time.tm_sec;
	if (rand < 0) { rand = rand * (-1); }
}

LightRand::~LightRand()
{
}
  
int LightRand::getVolume()
{
	return volume;
}

int LightRand::getRandVolume()
{
	rand += modulator * correlator + prevVol1 + prevVol2 + prevVol3;
	if (rand < 0) { rand = rand * (-1); }
	int randVolume = (rand % volume) + limMin;
	if (rand > 2000000000) { rand = prevVol3; }
	if (checker == 0) prevVol1 = randVolume;
	else if (checker == 1) prevVol2 = randVolume;
	else if (checker == 2)
	{
		prevVol3 = randVolume;
		checker = 0;
	}
	modulator++;
	if (modulator > 22564) modulator = time.tm_sec;
	correlator++;
	if (correlator > 5432) correlator = time.tm_min;
	return randVolume;
}

void LightRand::changeLimits(int min, int max)
{
	limMin = min;
	limMax = max;
	volume = limMax - limMin;
}

void LightRand::changeSeed()
{
	int* random = new int;
	rand = *random;
	delete random;
	if (rand < 0) { rand = rand * (-1); }
}
