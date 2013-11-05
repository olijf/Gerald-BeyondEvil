#include "hud.h"

hud::hud(status &blah):stat(blah) {
	hud_topTexture.loadFromFile("Data/hud_top.png");
	hud_topImage.setTexture(hud_topTexture);
	hud_topImage.setPosition(sf::Vector2f(0, 0));

	hud_bottomTexture.loadFromFile("Data/hud_bottom.png");
	hud_bottomImage.setTexture(hud_bottomTexture);
	hud_bottomImage.setPosition(sf::Vector2f(0, 620));
	
	hud_enemyTexture.loadFromFile("Data/hud_enemy.png");
	hud_enemyImage.setTexture(hud_enemyTexture);
	hud_enemyImage.setPosition(sf::Vector2f(1110, 0));

	
	health_enemy.setPosition(sf::Vector2f(1130,7));
	health_enemy.setSize(sf::Vector2f(130, 17));
	health_enemy.setFillColor(sf::Color::Green);

	health_player.setPosition(sf::Vector2f(352,7));
	health_player.setSize(sf::Vector2f(130, 17));
	health_player.setFillColor(sf::Color::Green);
}

hud::~hud() {
}

void hud::draw_top(sf::RenderWindow &Window) {
	Window.draw(hud_topImage);
	Window.draw(hud_enemyImage);
	
	health_enemy.setSize(sf::Vector2f(stat.get_health_enemy()*0.013, 17));
	Window.draw(health_enemy);
	
	health_player.setSize(sf::Vector2f(stat.get_health_player()*0.013, 17));
	Window.draw(health_player);
}

void hud::draw_bottom(sf::RenderWindow &Window) {
	Window.draw(hud_bottomImage);
}
