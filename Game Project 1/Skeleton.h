#pragma once
class Skeleton
{
public:
	Skeleton();
	int getHealth();
	int getAttack();
	int getAttackChance();
	void reduceHealth(int a);
	~Skeleton();
private:
	int health;
	int attack;
	int attackChance;
};

