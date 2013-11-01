#include "draw_field.h"

draw_field::draw_field() {
	fieldTexture.loadFromFile("Data/level.png");
	fieldImage.setTexture(fieldTexture);
	fieldImage.setPosition(sf::Vector2f(0, 0));
}

draw_field::~draw_field() {
}

void draw_field::draw(sf::RenderWindow &Window) {
	Window.draw(fieldImage);
}