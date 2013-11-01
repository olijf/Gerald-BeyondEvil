#pragma once

#include <SFML/Graphics.hpp>

class draw_field {

public:

draw_field();
~draw_field();

void draw(sf::RenderWindow &Window);

sf::Texture fieldTexture;
sf::Sprite fieldImage;

};

