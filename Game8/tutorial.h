#include <SFML/Graphics.hpp>
#include <iostream>

#include "mouse.h"
#include "text.h"

#pragma once

class tutorial {

private:

	sf::Texture questionTexture, tutorialTexture;
	sf::Sprite questionImage, tutorialImage;
	sf::RectangleShape focus, text_back;

	text tutorial_text;

	bool tutorial_active, hover;
	int tutorial_step, farm_active, lumber_camp_active, mining_camp_active, castle_active;

	mouse *tutorial_mouse;

public:

	tutorial(mouse *player_mouse);
	~tutorial();

	void next_step(int step);

	bool active();
	int farm_state();
	int lumber_camp_state();
	int mining_camp_state();
	int castle_state();

	void draw(sf::RenderWindow &Window, sf::Event &Event);

};