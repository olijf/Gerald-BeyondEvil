#include "mining_camp.h"

mining_camp::mining_camp(resources * resources2, tutorial * player_tutorial) {

	resources1 = resources2;
	the_tutorial = player_tutorial;

	//mining_camp
	mining_campTexture.loadFromFile("Data/mining_camp.png");
	mining_campImage.setTexture(mining_campTexture);
	mining_campImage.setPosition(sf::Vector2f(285, 0));

	//buttons
	stone_buttons.loadFromFile("Data/stone_buttons.png");
	stoneImage.setTexture(stone_buttons);
	stoneImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
	stoneImage.setPosition(sf::Vector2f(30, 650));

	gold_buttons.loadFromFile("Data/gold_buttons.png");
	goldImage.setTexture(gold_buttons);
	goldImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
	goldImage.setPosition(sf::Vector2f(80, 650));

	active = false;
	stone_upgrade = 0;
	gold_upgrade = 0;
	stone_production = 5;
	gold_production = 5;
	upgrade_cost.set_position(200, 640);
	upgrade_info.set_position(300, 640);
}

mining_camp::~mining_camp() {
}

void mining_camp::test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse) {

	int mouseX = sf::Mouse::getPosition(Window).x;
	int mouseY = sf::Mouse::getPosition(Window).y;

	//mining_camp
	int mining_campX = mining_campImage.getPosition().x;
	int mining_campY = mining_campImage.getPosition().y;

	int mining_campWidth = mining_campImage.getTextureRect().width;
	int mining_campHeight = mining_campImage.getTextureRect().height;

	if ((mouseX > mining_campX && mouseX < (mining_campX+mining_campWidth)) && (mouseY > mining_campY && mouseY < (mining_campY+mining_campHeight))) {
		player_mouse.set_hover(true);
		hover = true;
		if (Event.mouseButton.button == sf::Mouse::Left&& Event.type == sf::Event::MouseButtonReleased && !active) {
			active = true;
			//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
			sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
		}
	}
	else if (Event.mouseButton.button == sf::Mouse::Left && (mouseY < (Window.getSize().y-90) || mouseX > 500)) {
		active = false;
		//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
		sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
	}
	else if (hover) {
		player_mouse.set_hover(false);
		hover = false;
		upgrade_cost.set_text("Mining Camp");
		upgrade_info.set_text("");
	}

	if (active) {
	//stone button
		if ((mouseX > stoneImage.getPosition().x && mouseX < (stoneImage.getPosition().x+40)) && (mouseY > stoneImage.getPosition().y && mouseY < (stoneImage.getPosition().y+40))) {

			hover = true;
			upgrade_cost.set_text("Food: \t30\nWood:\t10\nStone:\t0\nGold: \t10");

			if(resources1->get_food() >= 50 && resources1->get_wood() >= 50 && resources1->get_stone() >= 50 && resources1->get_gold() >= 50) {
				player_mouse.set_hover(true);
				if (Event.mouseButton.button == sf::Mouse::Left) {
					if (Event.type == sf::Event::MouseButtonPressed) {
						stoneImage.setTextureRect(sf::IntRect(stone_upgrade*40, 40, 40, 40));
					}
					if (Event.type == sf::Event::MouseButtonReleased) {
						if (stone_upgrade < 2) {
							resources1->decrease_food(1);
							resources1->decrease_wood(1);
							resources1->decrease_stone(1);
							resources1->decrease_gold(1);
							++stone_upgrade;
							stone_production += 5;
							audio4.mine_up();
						}
						if (stone_upgrade == 2 && gold_upgrade == 2)
							mining_campTexture.loadFromFile("Data/mining_camp_max.png");
					}
				}
			}
			else {
				player_mouse.set_disable();
				upgrade_info.set_text("Not enough resources!");
			}
			if (stone_upgrade > 1) {
				player_mouse.set_disable();
				upgrade_cost.set_text("Mining Camp");
			}
			else
				upgrade_info.set_text("Lorem Ipsum1..");
			//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
			sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
		}
		//gold button
		else if ((mouseX > goldImage.getPosition().x && mouseX < (goldImage.getPosition().x+40)) && (mouseY > goldImage.getPosition().y && mouseY < (goldImage.getPosition().y+40))) {

			hover = true;
			upgrade_cost.set_text("Food: \t30\nWood:\t10\nStone:\t0\nGold: \t10");

			if(resources1->get_food() >= 50 && resources1->get_wood() >= 50 && resources1->get_stone() >= 50 && resources1->get_gold() >= 50) {
				player_mouse.set_hover(true);
				if (Event.mouseButton.button == sf::Mouse::Left) {
					if (Event.type == sf::Event::MouseButtonPressed) {
						goldImage.setTextureRect(sf::IntRect(gold_upgrade*40, 40, 40, 40));
					}
					if (Event.type == sf::Event::MouseButtonReleased) {
						if (gold_upgrade < 2) {
							resources1->decrease_food(1);
							resources1->decrease_wood(1);
							resources1->decrease_stone(1);
							resources1->decrease_gold(1);
							++gold_upgrade;
							gold_production+=5;
							audio4.mine_up();
						}
						if (stone_upgrade == 2 && gold_upgrade == 2)
							mining_campTexture.loadFromFile("Data/mining_camp_max.png");
					}
				}
			}
			else {
				player_mouse.set_disable();
				upgrade_info.set_text("Not enough resources!");
			}
			if (gold_upgrade > 1) {
				player_mouse.set_disable();
				upgrade_cost.set_text("Mining Camp");
			}
			else
				upgrade_info.set_text("Lorem Ipsum1..");
			//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
			sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
		}
		//reset buttons
		if (Event.type == sf::Event::MouseButtonReleased) {
			stoneImage.setTextureRect(sf::IntRect(stone_upgrade*40, 0, 40, 40));
			goldImage.setTextureRect(sf::IntRect(gold_upgrade*40, 0, 40, 40));
		}
	}
}

void mining_camp::draw(sf::RenderWindow &Window, hud &player_hud) {

	Window.draw(mining_campImage);

	if (!the_tutorial->active()) {
		if (active) {
		player_hud.draw_bottom(Window);
		Window.draw(stoneImage);
		Window.draw(goldImage);
		Window.draw(upgrade_cost.text1);
		Window.draw(upgrade_info.text1);
		}
	}
	else {
		switch (the_tutorial->mining_camp_state()) {
			case 1:
				if (active) {
					player_hud.draw_bottom(Window);
					Window.draw(stoneImage);
					Window.draw(goldImage);
					Window.draw(upgrade_cost.text1);
					Window.draw(upgrade_info.text1);
				}
				break;
			case 2:
				active = true;
				player_hud.draw_bottom(Window);
				Window.draw(stoneImage);
				Window.draw(goldImage);
				Window.draw(upgrade_cost.text1);
				Window.draw(upgrade_info.text1);
				break;
			default:
				break;
		}
	}
}

int mining_camp::get_stone_production(){
	return gold_production;
}
int mining_camp::get_gold_production(){
	return stone_production;
}
