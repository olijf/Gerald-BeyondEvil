#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <stdio.h>

#include "draw_field.h"
#include "hud.h"
#include "field_manager.h"
#include <SFML/OpenGL.hpp>

int main() {

	sf::RenderWindow Window(sf::VideoMode(1280, 720), "Game10");
	Window.setKeyRepeatEnabled(false);

	// it works out of the box
	glEnable(GL_TEXTURE_2D);
	draw_field field;
	hud player_hud;
	field_manager player_manager;
	field_manager enemy_manager;

	while (Window.isOpen()) {

		sf::Event Event;
		while (Window.pollEvent(Event)) {

			//if (Event.type == sf::Event::Closed || Event.key.code == sf::Keyboard::Escape) {
			
			if (Event.type == sf::Event::KeyReleased && Event.key.code == sf::Keyboard::A) {
				enemy_manager.new_unit(1,true);
			}
			if (Event.type == sf::Event::KeyReleased && Event.key.code == sf::Keyboard::S) {
				enemy_manager.new_unit(2,true);
			}
			if (Event.type == sf::Event::KeyReleased && Event.key.code == sf::Keyboard::D) {
				enemy_manager.new_unit(3,true);
			}
			if (Event.type == sf::Event::KeyReleased && Event.key.code == sf::Keyboard::F) {
				enemy_manager.delete_unit();
			}
			if (Event.type == sf::Event::KeyReleased && Event.key.code == sf::Keyboard::G) {
				player_manager.delete_unit();
			}

			if (Event.type == sf::Event::Closed) {
				Window.close();
			}

			if (Event.mouseButton.button == sf::Mouse::Left) {

				int tempX = sf::Mouse::getPosition(Window).x;
				int tempY = sf::Mouse::getPosition(Window).y;

				int buttonSize = player_hud.swordsmanImage.getTextureRect().width;

				//swordsman button
				if ((tempX > player_hud.swordsmanImage.getPosition().x && tempX < (player_hud.swordsmanImage.getPosition().x+buttonSize)) && (tempY > player_hud.swordsmanImage.getPosition().y && tempY < (player_hud.swordsmanImage.getPosition().y+buttonSize))) {
					if (Event.type == sf::Event::MouseButtonPressed) {
						player_hud.swordsmanImage.setTextureRect(sf::IntRect(0, 40, 40, 40));
					}
					if (Event.type == sf::Event::MouseButtonReleased) {
						player_manager.new_unit(1,false);
					}
				}
				//archer button
				if ((tempX > player_hud.archerImage.getPosition().x && tempX < (player_hud.archerImage.getPosition().x+buttonSize)) && (tempY > player_hud.archerImage.getPosition().y && tempY < (player_hud.archerImage.getPosition().y+buttonSize))) {
					if (Event.type == sf::Event::MouseButtonPressed) {
						player_hud.archerImage.setTextureRect(sf::IntRect(40, 40, 40, 40));
					}
					if (Event.type == sf::Event::MouseButtonReleased) {
						player_manager.new_unit(2,false);
					}
				}
				//horseman button
				if ((tempX > player_hud.horsemanImage.getPosition().x && tempX < (player_hud.horsemanImage.getPosition().x+buttonSize)) && (tempY > player_hud.horsemanImage.getPosition().y && tempY < (player_hud.horsemanImage.getPosition().y+buttonSize))) {
					if (Event.type == sf::Event::MouseButtonPressed) {
						player_hud.horsemanImage.setTextureRect(sf::IntRect(80, 40, 40, 40));
					}
					if (Event.type == sf::Event::MouseButtonReleased) {
						player_manager.new_unit(3,false);
					}
				}

				//reset buttons
				if (Event.type == sf::Event::MouseButtonReleased) {
					player_hud.swordsmanImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
					player_hud.archerImage.setTextureRect(sf::IntRect(40, 0, 40, 40));
					player_hud.horsemanImage.setTextureRect(sf::IntRect(80, 0, 40, 40));
				}

			}

		}

		field.draw(Window);
		player_hud.draw(Window);
		player_manager.draw(Window, 0, enemy_manager);
		enemy_manager.draw(Window, 1, player_manager);

		Window.display();
		Window.clear();
	
	}

	return 0;

}