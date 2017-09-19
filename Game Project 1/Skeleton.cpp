#include "Skeleton.h"

Skeleton::Skeleton()
{
	health = 70;
	attackChance = 60;
	attack = 30;
}

int Skeleton::getHealth() {
	return health;
}

int Skeleton::getAttackChance() {
	return attackChance;
}

int Skeleton::getAttack() {
	return attack;
}

void Skeleton::reduceHealth(int a) {

	health -= a;
}

Skeleton::~Skeleton()
{
}
