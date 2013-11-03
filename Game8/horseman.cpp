#include "horseman.h"

horseman::horseman() {
	pTexture.loadFromFile("Data/horseman.png");
	std::cout << "new horseman" << std::endl;
	health = 4000;
	factor = 0.008;
	damage = 100;	
	range = 100;
}

horseman::~horseman() {
	std::cout << "delete horseman" << std::endl;
}