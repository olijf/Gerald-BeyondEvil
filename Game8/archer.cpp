#include <iostream>

#include "archer.h"

archer::archer() {
	frameCounter = 0, switchFrame = 100, frameSpeed = 500;

	health_bar_back.setSize(sf::Vector2f(32, 5));
	health_bar_back.setFillColor(sf::Color::Red);
	health_bar.setSize(sf::Vector2f(26, 5));
	health_bar.setFillColor(sf::Color::Green);

	pTexture.loadFromFile("Data/archer.png");
	playerImage.setTexture(pTexture);
	//playerImage.setPosition(sf::Vector2f(1100, 468));

	source.x = 1;

	std::cout << "new archer" << std::endl;
}

archer::~archer() {
	std::cout << "delete archer" << std::endl;
}

