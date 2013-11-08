#include "archer.h"
#define factorqual (32.0/1000)
archer::archer() {
	pTexture.loadFromFile("Data/archer.png");
	std::cout << "new archer" << std::endl;
	health = 1000;
	factor = factorqual;
	damage = 50;
	castle_damage = 50;
	range = 100;
}

archer::~archer() {
	std::cout << "delete archer" << std::endl;
}

