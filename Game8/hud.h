#include <SFML/Graphics.hpp>

#pragma once

class hud {

public:

hud();
~hud();

void draw(sf::RenderWindow &Window);

sf::RectangleShape hud_top;
sf::RectangleShape hud_bottom;

sf::Texture player_buttons;
sf::Sprite swordsmanImage;
sf::Sprite archerImage;
sf::Sprite horsemanImage;

};

