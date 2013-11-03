#include <SFML/Graphics.hpp>
#include <iostream>

#include "hud.h"
#include "field_manager.h"

#pragma once

class button_manager {

public:

	int food_upgrade, wood_upgrade, stone_upgrade, gold_upgrade;

	button_manager();
	~button_manager();

	void test(sf::Event &Event, sf::RenderWindow &Window, hud &player_hud, field_manager &player_manager);

};

