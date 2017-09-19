#pragma once
#include <iostream>

class Human
{
public:
	Human();
	void getStats();
	int getAttackChance();
	int getAttack();
	int getHealth();
	void reduceHealth(int a);
	~Human();
private:
	int attackChance;
	int attack;
	int health;
};

