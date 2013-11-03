#include "swordsman.h"
#define factorqual (32.0/3000)

swordsman::swordsman() {
	pTexture.loadFromFile("Data/swordman.png");
	std::cout << "new swordsman" << std::endl;
	health = 3018;
	factor = factorqual;
	damage = 50;	
	range = 15;
}

swordsman::~swordsman() {
	std::cout << "delete swordsman" << std::endl;
}

