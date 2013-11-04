#pragma once

#include <SFML/Graphics.hpp>

class draw_field {

private:

sf::Texture fieldTexture;
sf::Sprite fieldImage;

public:

draw_field();
~draw_field();

void draw(sf::RenderWindow &Window);

};