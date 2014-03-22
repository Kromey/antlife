#include <cstdlib>
#include <ctime>
#include "Ant.h"


const int Ant::MAX_AGE = 100;
const float Ant::AGE_VARIANCE = 0.2;

Ant::Ant() : age(0)
{
	int minAgeLimit, maxAgeLimit;
	minAgeLimit = (1.0 - Ant::AGE_VARIANCE) * Ant::MAX_AGE;
	maxAgeLimit = (1.0 + Ant::AGE_VARIANCE) * Ant::MAX_AGE;

	srand(time(NULL));
	this->ageLimit = rand() % (maxAgeLimit - minAgeLimit) + minAgeLimit;
}

bool Ant::isAlive()
{
	return this->age < this->ageLimit;
}

int Ant::getAge()
{
	return age;
}

bool Ant::update()
{
	if(this->age < this->ageLimit)
	{
		++this->age;
		return true;
	} else {
		return false;
	}
}
