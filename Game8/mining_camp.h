#include <SFML/Graphics.hpp>
#include <iostream>

#include "mouse.h"
#include "hud.h"
#include "text.h"
#include "resources.h"
#include "audio.h"

#include "tutorial.h"

#pragma once

class mining_camp {

private:

bool active, hover;
int stone_upgrade, gold_upgrade, stone_production, gold_production;

sf::Texture mining_campTexture, stone_buttons, gold_buttons;
sf::Sprite mining_campImage, stoneImage, goldImage;
text upgrade_cost, upgrade_info;
resources * resources1;
audio audio4;

tutorial * the_tutorial;

public:

mining_camp(resources * resources2, tutorial * player_tutorial);
~mining_camp();

void test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse);
void draw(sf::RenderWindow &Window, hud &player_hud);

int get_stone_production();
int get_gold_production();
};