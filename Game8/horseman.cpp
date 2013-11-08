#include "horseman.h"
#define factorqual (32.0/2000)
horseman::horseman() {
	pTexture.loadFromFile("Data/horseman.png");
	std::cout << "new horseman" << std::endl;
	health = 2000;
	factor = 0.016;
	damage = 75;
	castle_damage = 50;

	range = 15;
}

horseman::~horseman() {
	std::cout << "delete horseman" << std::endl;
}