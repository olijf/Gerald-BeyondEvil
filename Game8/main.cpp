#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <iostream>


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

#include "tutorial.h"

#include "ai.h"

#include "audio.h"

#include "game_over.h"
#include "menu.h"

#include "ScreenManager.h"
using namespace std;


int main() {

	ShowWindow( GetConsoleWindow(), SW_HIDE );

	sf::RenderWindow Window(sf::VideoMode(1280, 720), "Gerald Beyond Evil");
	glEnable(GL_TEXTURE_2D);
	Window.setFramerateLimit(60);
	Window.setVerticalSyncEnabled(true);
	Window.setKeyRepeatEnabled(false);

	initializeMenu(Window);

	drawMenu(Window);

	draw_field field;
	status castlehealth;
	
	hud player_hud(castlehealth);
	field_manager player_manager(castlehealth);
	field_manager enemy_manager(castlehealth);

	mouse player_mouse;
	audio audio1;

	tutorial player_tutorial(&player_mouse);

	resources player_resources;
	farm player_farm(&player_resources, &player_tutorial);
	lumber_camp player_lumber_camp(&player_resources, &player_tutorial);
	mining_camp player_mining_camp(&player_resources, &player_tutorial);
	castle player_castle(&player_resources, &player_tutorial);

	market player_market(&player_farm, &player_lumber_camp, &player_mining_camp, &player_resources);

	ai enemy_ai;

	game_over player_game(Window.getSize().x, Window.getSize().y);

	sf::Event Event;

	bool test = true;

	while (Window.isOpen()) {

		if (test && !ScreenManager::GetInstance().getInMenu()) {
			enemy_ai.reset_ai();
			player_resources.reset_resources();
			player_market.reset_market();
			player_market.update();
			audio1.play_background_music();
			player_farm.set_active(false);
			player_lumber_camp.set_active(false);
			player_mining_camp.set_active(false);
			player_castle.set_active(false);
			test = false;
		}

		while (Window.pollEvent(Event)) {
			if (!ScreenManager::GetInstance().getInMenu()) {
				if (Event.type == sf::Event::KeyReleased) {
					if (Event.key.code == sf::Keyboard::S)
						enemy_manager.new_unit(1, true);

					if (Event.key.code == sf::Keyboard::A)
						enemy_manager.new_unit(2, true);

					if (Event.key.code == sf::Keyboard::H)
						enemy_manager.new_unit(3, true);

					if (Event.key.code == sf::Keyboard::E)
						enemy_manager.delete_unit();

					if (Event.key.code == sf::Keyboard::D) {
						player_manager.delete_unit();
					}
					if (Event.key.code == sf::Keyboard::P) {
						player_resources.food += 500;
						player_resources.wood += 500;
						player_resources.stone += 500;
						player_resources.gold += 500;
					}
				}
			}
			if (Event.type == sf::Event::Closed || (Event.type == sf::Event::KeyReleased && Event.key.code == sf::Keyboard::Escape))
				Window.close();
		}

		if (!ScreenManager::GetInstance().getInMenu()) {
			player_farm.test(Event, Window, player_mouse);
			player_lumber_camp.test(Event, Window, player_mouse);
			player_mining_camp.test(Event, Window, player_mouse);
			player_castle.test(Event, Window, player_mouse, player_manager);
		}

		field.draw(Window);

		player_farm.draw(Window, player_hud);
		player_lumber_camp.draw(Window, player_hud);
		player_mining_camp.draw(Window, player_hud);
		player_castle.draw(Window, player_hud);

		if (!player_tutorial.active() && !ScreenManager::GetInstance().getInMenu()) {
			player_manager.draw(Window, 0, enemy_manager);
			enemy_manager.draw(Window, 1, player_manager);
			enemy_ai.test(player_manager, enemy_manager);
			player_market.update();
		}

		player_hud.draw_top(Window);
		player_market.draw(Window);

		if (!ScreenManager::GetInstance().getInMenu())
			player_tutorial.draw(Window, Event);

		if (castlehealth.get_health_player() == 0 || castlehealth.get_health_enemy() == 0) {
			if (castlehealth.get_health_player() == 0)
				player_game.win(false, Window);
			else
				player_game.win(true, Window);
			ScreenManager::GetInstance().setInMenu(true);
			if (Event.type == sf::Event::KeyReleased && Event.key.code == sf::Keyboard::Space) {
				castlehealth.reset_health();
				player_manager.clear_units();
				enemy_manager.clear_units();
				test = true;
				Window.setMouseCursorVisible(true);
				audio1.stop_music();
				drawMenu(Window);
			}
		}

		player_mouse.draw(Window);

		Window.display();
		Window.clear();
	
	}

	return 0;

}