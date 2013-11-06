#include <SFML/Graphics.hpp>
#include <iostream>

#include "mouse.h"
#include "hud.h"
#include "text.h"
#include "resources.h"
#include "audio.h"

#include "tutorial.h"

#pragma once

class farm {

private:

bool active, hover;
int food_upgrade, production;
audio audio4;

sf::Texture farmTexture, food_buttons;
sf::Sprite farmImage, foodImage;
text upgrade_cost, upgrade_info;
resources * resources1;

tutorial * the_tutorial;

public:

farm(resources * resources2, tutorial * player_tutorial);
~farm();

void test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse);
void draw(sf::RenderWindow &Window, hud &player_hud);

int get_production();
};