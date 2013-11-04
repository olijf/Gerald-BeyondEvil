#include <SFML/Graphics.hpp>
#include <iostream>

#include "mouse.h"
#include "hud.h"
#include "text.h"

#pragma once

class lumber_camp {

private:

bool active, hover;
int wood_upgrade, production;

sf::Texture lumber_campTexture, wood_buttons;
sf::Sprite lumber_campImage, woodImage;
text upgrade_cost, upgrade_info;

public:

lumber_camp();
~lumber_camp();

void test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse);
void draw(sf::RenderWindow &Window, hud &player_hud);
int get_production();
};