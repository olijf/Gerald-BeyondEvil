#include <SFML/Graphics.hpp>
#include <iostream>

#include "mouse.h"
#include "hud.h"
#include "text.h"
#include "field_manager.h"
#include "resources.h"
#include "audio.h"

#include "tutorial.h"

#pragma once

class castle {

private:

bool active, hover, spawn;

sf::Texture castleTexture, player_buttons;
sf::Sprite castleImage, swordsmanImage, archerImage, horsemanImage;
text upgrade_cost, upgrade_info;

resources * resources1;
audio audio1;

tutorial * the_tutorial;

public:

castle(resources * resources2, tutorial * player_tutorial);
~castle();

void test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse, field_manager &player_manager);
void draw(sf::RenderWindow &Window, hud &player_hud);

};