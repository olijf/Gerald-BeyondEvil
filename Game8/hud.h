#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class hud {

private:

sf::RectangleShape hud_top;
sf::RectangleShape hud_bottom;

public:

hud();
~hud();

void draw_top(sf::RenderWindow &Window);
void draw_bottom(sf::RenderWindow &Window);

};