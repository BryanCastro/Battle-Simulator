#include "Human.h"

Human::Human()
{
	attack = 50;
	attackChance = 70;
	health = 100;
}

void Human::getStats() {
	std::cout << "Health:" << health << std::endl;
	std::cout << "Attack:" << attack << std::endl;
	std::cout << "Attack Chance:" << attackChance << std::endl;
}

int Human::getAttackChance() {
	return attackChance;
}

int Human::getAttack() {
	return attack;
}

int Human::getHealth() {
	return health;
}

void Human::reduceHealth(int a) {
	health -= a;
}


Human::~Human()
{
}
