#include "mouse.h"

mouse::mouse() {
	mouseTexture.loadFromFile("Data/mouse.png");
	mouseImage.setTexture(mouseTexture);
	mouseImage.setTextureRect(sf::IntRect(0, 0, 30, 30));
}

mouse::~mouse() {
}

void mouse::set_hover(bool hover) {
	if (hover)
		mouseImage.setTextureRect(sf::IntRect(0, 30, 30, 30));
	else
		mouseImage.setTextureRect(sf::IntRect(0, 0, 30, 30));
}

void mouse::draw(sf::RenderWindow &Window) {
	mouseImage.setPosition(sf::Vector2f(sf::Mouse::getPosition(Window)));
	Window.draw(mouseImage);
}
