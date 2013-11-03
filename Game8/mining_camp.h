#include <SFML/Graphics.hpp>
#include <iostream>

#include "mouse.h"
#include "hud.h"
#include "text.h"

#pragma once

class mining_camp {

private:

bool active, hover;
int stone_upgrade, gold_upgrade;

sf::Texture mining_campTexture, stone_buttons, gold_buttons;
sf::Sprite mining_campImage, stoneImage, goldImage;
text upgrade_cost, upgrade_info;

public:

mining_camp();
~mining_camp();

void test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse);
void draw(sf::RenderWindow &Window, hud &player_hud);

};