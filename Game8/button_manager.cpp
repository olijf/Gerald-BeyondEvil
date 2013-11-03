#include "button_manager.h"

button_manager::button_manager() {
	food_upgrade = 0;
	wood_upgrade = 0;
	stone_upgrade = 0;
	gold_upgrade = 0;
}

button_manager::~button_manager() {
}

void button_manager::test(sf::Event &Event, sf::RenderWindow &Window, hud &player_hud, field_manager &player_manager) {

	if (Event.mouseButton.button == sf::Mouse::Left) {

		int tempX = sf::Mouse::getPosition(Window).x;
		int tempY = sf::Mouse::getPosition(Window).y;

		//swordsman button
		if ((tempX > player_hud.swordsmanImage.getPosition().x && tempX < (player_hud.swordsmanImage.getPosition().x+40)) && (tempY > player_hud.swordsmanImage.getPosition().y && tempY < (player_hud.swordsmanImage.getPosition().y+40))) {
			if (Event.type == sf::Event::MouseButtonPressed) {
				player_hud.swordsmanImage.setTextureRect(sf::IntRect(0, 40, 40, 40));
			}
			if (Event.type == sf::Event::MouseButtonReleased) {
				player_manager.new_unit(1, false);
			}
		}
		//archer button
		if ((tempX > player_hud.archerImage.getPosition().x && tempX < (player_hud.archerImage.getPosition().x+40)) && (tempY > player_hud.archerImage.getPosition().y && tempY < (player_hud.archerImage.getPosition().y+40))) {
			if (Event.type == sf::Event::MouseButtonPressed) {
				player_hud.archerImage.setTextureRect(sf::IntRect(40, 40, 40, 40));
			}
			if (Event.type == sf::Event::MouseButtonReleased) {
				player_manager.new_unit(2, false);
			}
		}
		//horseman button
		if ((tempX > player_hud.horsemanImage.getPosition().x && tempX < (player_hud.horsemanImage.getPosition().x+40)) && (tempY > player_hud.horsemanImage.getPosition().y && tempY < (player_hud.horsemanImage.getPosition().y+40))) {
			if (Event.type == sf::Event::MouseButtonPressed) {
				player_hud.horsemanImage.setTextureRect(sf::IntRect(80, 40, 40, 40));
			}
			if (Event.type == sf::Event::MouseButtonReleased) {
				player_manager.new_unit(3, false);
			}
		}
		//food button
		if ((tempX > player_hud.foodImage.getPosition().x && tempX < (player_hud.foodImage.getPosition().x+40)) && (tempY > player_hud.foodImage.getPosition().y && tempY < (player_hud.foodImage.getPosition().y+40))) {
			if (Event.type == sf::Event::MouseButtonPressed) {
				player_hud.foodImage.setTextureRect(sf::IntRect(food_upgrade*40, 40, 40, 40));
			}
			if (Event.type == sf::Event::MouseButtonReleased) {
				if (food_upgrade < 3)
					++food_upgrade;
			}
		}
		//wood button
		if ((tempX > player_hud.woodImage.getPosition().x && tempX < (player_hud.woodImage.getPosition().x+40)) && (tempY > player_hud.woodImage.getPosition().y && tempY < (player_hud.woodImage.getPosition().y+40))) {
			if (Event.type == sf::Event::MouseButtonPressed) {
				player_hud.woodImage.setTextureRect(sf::IntRect(wood_upgrade*40, 40, 40, 40));
			}
			if (Event.type == sf::Event::MouseButtonReleased) {
				if (wood_upgrade < 2)
					++wood_upgrade;
			}
		}
		//stone button
		if ((tempX > player_hud.stoneImage.getPosition().x && tempX < (player_hud.stoneImage.getPosition().x+40)) && (tempY > player_hud.stoneImage.getPosition().y && tempY < (player_hud.stoneImage.getPosition().y+40))) {
			if (Event.type == sf::Event::MouseButtonPressed) {
				player_hud.stoneImage.setTextureRect(sf::IntRect(stone_upgrade*40, 40, 40, 40));
			}
			if (Event.type == sf::Event::MouseButtonReleased) {
				if (stone_upgrade < 2)
					++stone_upgrade;
			}
		}
		//gold button
		if ((tempX > player_hud.goldImage.getPosition().x && tempX < (player_hud.goldImage.getPosition().x+40)) && (tempY > player_hud.goldImage.getPosition().y && tempY < (player_hud.goldImage.getPosition().y+40))) {
			if (Event.type == sf::Event::MouseButtonPressed) {
				player_hud.goldImage.setTextureRect(sf::IntRect(gold_upgrade*40, 40, 40, 40));
			}
			if (Event.type == sf::Event::MouseButtonReleased) {
				if (gold_upgrade < 2)
					++gold_upgrade;
			}
		}

		//reset buttons
		if (Event.type == sf::Event::MouseButtonReleased) {
			player_hud.swordsmanImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
			player_hud.archerImage.setTextureRect(sf::IntRect(40, 0, 40, 40));
			player_hud.horsemanImage.setTextureRect(sf::IntRect(80, 0, 40, 40));

			player_hud.foodImage.setTextureRect(sf::IntRect(food_upgrade*40, 0, 40, 40));
			player_hud.woodImage.setTextureRect(sf::IntRect(wood_upgrade*40, 0, 40, 40));
			player_hud.stoneImage.setTextureRect(sf::IntRect(stone_upgrade*40, 0, 40, 40));
			player_hud.goldImage.setTextureRect(sf::IntRect(gold_upgrade*40, 0, 40, 40));
		}

	}
}
