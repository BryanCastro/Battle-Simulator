//Last left off, Write reduce Health Fucntion for Human

#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <vector>
#include "Human.h"
#include "Skeleton.h"

//functions
int humanCount(); //gets number of humans that user wants to include in simulation
int skeletonCount();//gets number of skeletons that user wants to include in simulation
void dynamicCreate(std::vector<Human> &numHum, int numberOfHumans, std::vector<Skeleton> &numSkel, int numberOfSkeletons); //creates number of humans and skeletons in dynamic vector
void battlePhase(bool battle, bool turn, std::vector<Human> &numHum, std::vector<Skeleton> &numSkel); // battle phase between skeletons and humans
void getStats(std::vector<Human> numHum, std::vector<Skeleton> numSkel); //gets stats after Battle

int main() {


	bool battle = true; //boolean used to check if battle is still in progress
	bool turn = true; //boolean that determins who's turn it is
	int numberOfHumans; //stores number of humans
	int numberOfSkeletons;//stores number of skeletons
	std::vector<Human> numHum; //vector storing all humans
	std::vector<Skeleton> numSkel;//vector storing all skeletons

	std::cout << "*****Human vs Skeletons*****\n\n" << std::endl;

	numberOfHumans = humanCount(); //calls humanCount function and stores return value in numberOfHumans
	numberOfSkeletons = skeletonCount(); //calls skeeltonCount function and stores return value in numberOfSkeletons

	dynamicCreate(numHum, numberOfHumans, numSkel, numberOfSkeletons); //fills vector dynamically in for loop

	battlePhase(battle, turn, numHum, numSkel);

	getStats(numHum, numSkel);	

	return 0;
}

int humanCount() {

	int numberOfHumans;

	std::cout << "How many humans?: ";
	std::cin >> numberOfHumans;
	return numberOfHumans;
}

int skeletonCount() {

	int numberOfSkeletons;

	std::cout << "How many skeletons?: ";
	std::cin >> numberOfSkeletons;
	return numberOfSkeletons;
}

void dynamicCreate(std::vector<Human> &numHum, int numberOfHumans, std::vector<Skeleton> &numSkel, int numberOfSkeletons) {
	for (int i = 0; i < numberOfHumans; i++) {
		numHum.resize(numberOfHumans);
	}

	for (int i = 0; i < numberOfSkeletons; i++) {
		numSkel.resize(numberOfSkeletons);
	}
}

void battlePhase(bool battle, bool turn, std::vector<Human> &numHum, std::vector<Skeleton> &numSkel) {
	std::default_random_engine randomEngine(time(NULL)); //seed declared at runtime
	std::uniform_int_distribution<int> rndNumber(0, 100); //calls for a value from 0 to 100 to be stored in att chance

	int humanCountTurn = 0; //takes in count what human npc is going to attack in battle
	int skeletonCountTurn = 0; //takes in count what skeletopn npc is going to attack in battle
	int currNPCBeingAttacked = 0;

	while (battle) {

		int attChance = rndNumber(randomEngine); //used to determine if npc attacked or failed to attack

		if (turn) { //turn true so human turn
			if (attChance <= numHum[humanCountTurn].getAttackChance()) { //checks if random number generated is within range of human attack chance
				numSkel[currNPCBeingAttacked].reduceHealth(numHum[humanCountTurn].getAttack()); //skeleton at position 0 health decreased

				std::cout << "\nHuman Attack Hit!!" << std::endl;
				std::cout << numHum[humanCountTurn].getAttack() << " damage taken from skeleon!!" << std::endl; //prints out damage done to skeleton

				if (numSkel[currNPCBeingAttacked].getHealth() > 0) {
					std::cout << "Skeleton Health Remaining: " << numSkel[currNPCBeingAttacked].getHealth() << std::endl; //prints out health remaining for skeleton at position 0
				}

				if (numSkel[currNPCBeingAttacked].getHealth() <= 0) {
					std::cout << "Skeleton has died!!" << std::endl;
					numSkel.erase(numSkel.begin()); //deletes first element of vector, all following values in vector moved down by 1 index
													//but vector size remains the same, can lead to errors
					numSkel.shrink_to_fit();	//shrinks vector size down to how many skeletons are left, fixes error potential from above
				}
			}
			else {
				std::cout << "\nHuman Attack Missed!!\n" << std::endl;
			}

			turn = false; //chances to false so Skeleton Turn
		}

		else { //Skeleton turn
			if (attChance <= numSkel[skeletonCountTurn].getAttackChance()) { //checks if random number generated is within range of skeleton attack chance
				numHum[currNPCBeingAttacked].reduceHealth(numSkel[skeletonCountTurn].getAttack()); //human at position 0's health decreased

				std::cout << "\nSkeleton Attack Hit!!" << std::endl;
				std::cout << numSkel[skeletonCountTurn].getAttack() << " damage taken from Human!!" << std::endl; //prints out damage done to Human

				if (numHum[currNPCBeingAttacked].getHealth() >0) {
					std::cout << "Human Health Remaining: " << numHum[currNPCBeingAttacked].getHealth() << std::endl; //prints out health remaining for human at position 0
				}

				if (numHum[currNPCBeingAttacked].getHealth() <= 0) { //checks if human health at position 0 equal to or under 0
					std::cout << "Human has died!!" << std::endl;
					numHum.erase(numHum.begin()); //deletes first human from vector at index 0 and moves remaining humans one index down

					numHum.shrink_to_fit(); //shrinks vector size down to how many skeletons are left, fixes error potential from above
				}
			}
			else {
				std::cout << "\nSkeleton Attack Missed!!\n" << std::endl;
			}

			turn = true; //sets human turn next
		}

		if (numSkel.capacity() <= 0 || numHum.capacity() <= 0) { //checks if either human or skeleton army below 0
			battle = false;	//if either is sets battle to false and winner is determined
		}
	}
}

void getStats(std::vector<Human> numHum, std::vector<Skeleton> numSkel) {

	std::cout << "\n---Battle Aftermath---\n" << std::endl;

	std::cout << "Number of Humans Remaining: " << numHum.capacity() << std::endl; //gets number of humans remaining
	std::cout << "number of Skeletons Remaining: " << numSkel.capacity() << std::endl; //gets number of skeletons remaining

	if (numHum.capacity() > numSkel.capacity()) {		//prints out who won battle
		std::cout << "\nHumans Win!!!"<<std::endl;
	}
	else {
		std::cout << "\nSkeletons Win!!!!" << std::endl;
	}
	
}
