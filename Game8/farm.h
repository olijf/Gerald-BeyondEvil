#include <SFML/Graphics.hpp>
#include <iostream>

#include "mouse.h"
#include "hud.h"
#include "text.h"

#pragma once

class farm {

private:

bool active, hover;
int food_upgrade;

sf::Texture farmTexture, food_buttons;
sf::Sprite farmImage, foodImage;
text upgrade_cost, upgrade_info;

public:

farm();
~farm();

void test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse);
void draw(sf::RenderWindow &Window, hud &player_hud);

};