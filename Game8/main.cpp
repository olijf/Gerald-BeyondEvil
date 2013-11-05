#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <sstream>
#include <stdio.h>

#include "draw_field.h"
#include "hud.h"
#include "field_manager.h"

#include "mouse.h"

#include "farm.h"
#include "lumber_camp.h"
#include "mining_camp.h"
#include "castle.h"
#include "market.h"
#include "status.h"

#include "ai.h"

int main() {

	sf::RenderWindow Window(sf::VideoMode(1280, 720), "Game10");

	glEnable(GL_TEXTURE_2D);

	Window.setFramerateLimit(60);
	Window.setVerticalSyncEnabled(true);

	Window.setMouseCursorVisible(false);
	Window.setKeyRepeatEnabled(false);

	draw_field field;
	status castlehealth;
	
	hud player_hud(castlehealth);
	field_manager player_manager(castlehealth);
	field_manager enemy_manager(castlehealth);

	mouse player_mouse;

	resources player_resources;
	farm player_farm(&player_resources);
	lumber_camp player_lumber_camp(&player_resources);
	mining_camp player_mining_camp(&player_resources);
	market player_market(&player_farm, &player_lumber_camp, &player_mining_camp, &player_resources);
	castle player_castle(&player_resources);

	ai enemy_ai;

	sf::Event Event;

	while (Window.isOpen()) {

		while (Window.pollEvent(Event)) {
			if (Event.type == sf::Event::KeyReleased) {
				if (Event.key.code == sf::Keyboard::S)
					enemy_manager.new_unit(1, true);

				if (Event.key.code == sf::Keyboard::A)
					enemy_manager.new_unit(2, true);

				if (Event.key.code == sf::Keyboard::H)
					enemy_manager.new_unit(3, true);

				if (Event.key.code == sf::Keyboard::E)
					enemy_manager.delete_unit();

				if (Event.key.code == sf::Keyboard::D)
					player_manager.delete_unit();
			}
			if (Event.type == sf::Event::Closed)
				Window.close();
		}

		player_farm.test(Event, Window, player_mouse);
		player_lumber_camp.test(Event, Window, player_mouse);
		player_mining_camp.test(Event, Window, player_mouse);
		player_castle.test(Event, Window, player_mouse, player_manager);

		field.draw(Window);

		player_farm.draw(Window, player_hud);
		player_lumber_camp.draw(Window, player_hud);
		player_mining_camp.draw(Window, player_hud);
		player_castle.draw(Window, player_hud);

		player_manager.draw(Window, 0, enemy_manager);
		enemy_manager.draw(Window, 1, player_manager);

		enemy_ai.test(player_manager, enemy_manager);
		player_market.update();
		player_hud.draw_top(Window);

		player_mouse.draw(Window);

		Window.display();
		Window.clear();
	
	}

	return 0;

}