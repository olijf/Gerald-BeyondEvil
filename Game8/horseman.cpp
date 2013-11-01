#include "horseman.h"
#include <iostream>

horseman::horseman() {
	frameCounter = 0, switchFrame = 100, frameSpeed = 500;
	
	health_bar_back.setSize(sf::Vector2f(32, 5));
	health_bar_back.setFillColor(sf::Color::Red);
	health_bar.setSize(sf::Vector2f(26, 5));
	health_bar.setFillColor(sf::Color::Green);

	pTexture.loadFromFile("Data/horseman.png");
	playerImage.setTexture(pTexture);
	//playerImage.setPosition(sf::Vector2f(1100, 468));

	source.x = 1;

	std::cout << "new horseman" << std::endl;
}

horseman::~horseman() {
	std::cout << "delete horseman" << std::endl;
}