#include "hud.h"

hud::hud() {

	hud_top.setSize(sf::Vector2f(500, 30));
	hud_top.setFillColor(sf::Color::Black);
	hud_top.setPosition(sf::Vector2f(0, 0));

	hud_bottom.setSize(sf::Vector2f(300, 200));
	hud_bottom.setFillColor(sf::Color::Black);
	hud_bottom.setPosition(sf::Vector2f(0, 630));

	player_buttons.loadFromFile("Data/player_buttons.png");

	swordsmanImage.setTexture(player_buttons);
	swordsmanImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
	swordsmanImage.setPosition(sf::Vector2f(30, 650));

	archerImage.setTexture(player_buttons);
	archerImage.setTextureRect(sf::IntRect(40, 0, 40, 40));
	archerImage.setPosition(sf::Vector2f(90, 650));

	horsemanImage.setTexture(player_buttons);
	horsemanImage.setTextureRect(sf::IntRect(80, 0, 40, 40));
	horsemanImage.setPosition(sf::Vector2f(150, 650));

}

hud::~hud() {
}

void hud::draw(sf::RenderWindow &Window) {

	Window.draw(hud_top);
	Window.draw(hud_bottom);

	Window.draw(swordsmanImage);
	Window.draw(archerImage);
	Window.draw(horsemanImage);
}
