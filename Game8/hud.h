#include <SFML/Graphics.hpp>
#include <iostream>
#include "status.h"

#pragma once

class hud {

private:

sf::Texture hud_topTexture, hud_bottomTexture, hud_enemyTexture;
sf::Sprite hud_topImage, hud_bottomImage, hud_enemyImage;

	sf::RectangleShape health_enemy;
	sf::RectangleShape health_player;
		
	status &stat;

public:

	hud(status &blah);
~hud();

void draw_top(sf::RenderWindow &Window);
void draw_bottom(sf::RenderWindow &Window);

};