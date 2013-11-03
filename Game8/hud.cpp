#include "hud.h"

hud::hud() {
	hud_top.setSize(sf::Vector2f(500, 30));
	hud_top.setFillColor(sf::Color::Black);
	hud_top.setPosition(sf::Vector2f(0, 0));
	hud_bottom.setSize(sf::Vector2f(500, 90));
	hud_bottom.setFillColor(sf::Color::Black);
	hud_bottom.setPosition(sf::Vector2f(0, 630));
}

hud::~hud() {
}

void hud::draw_top(sf::RenderWindow &Window) {
	Window.draw(hud_top);
}

void hud::draw_bottom(sf::RenderWindow &Window) {
	Window.draw(hud_bottom);
}