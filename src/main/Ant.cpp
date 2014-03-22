#include "Ant.h"

const int Ant::MAX_AGE = 100;

Ant::Ant() : age(0)
{
}

bool Ant::isAlive()
{
	return this->age < Ant::MAX_AGE;
}

int Ant::getAge()
{
	return age;
}

void Ant::update()
{
	age++;
}
