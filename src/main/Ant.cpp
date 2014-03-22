#include "Ant.h"

Ant::Ant() : age(0)
{
}

bool Ant::isAlive()
{
	return true;
}

int Ant::getAge()
{
	return age;
}

void Ant::update()
{
	age++;
}
