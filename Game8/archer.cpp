#include "archer.h"

archer::archer() {
	pTexture.loadFromFile("Data/archer.png");
	std::cout << "new archer" << std::endl;
	health = 2000;
	factor = 0.016;
	damage = 75;
	range = 100;
}

archer::~archer() {
	std::cout << "delete archer" << std::endl;
}

