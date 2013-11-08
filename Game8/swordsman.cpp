#include "swordsman.h"
#define factorqual (32.0/1500)

swordsman::swordsman() {
	pTexture.loadFromFile("Data/swordman.png");
	std::cout << "new swordsman" << std::endl;
	health = 1508;
	factor = factorqual;
	damage = 50;	
	castle_damage = 75;
	range = 15;
}

swordsman::~swordsman() {
	std::cout << "delete swordsman" << std::endl;
}

