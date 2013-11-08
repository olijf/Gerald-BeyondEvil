#include "farm.h"

farm::farm(resources * resources2, tutorial * player_tutorial) {

	resources1 = resources2;
	the_tutorial = player_tutorial;

	//farm
	farmTexture.loadFromFile("Data/farm.png");
	farmImage.setTexture(farmTexture);
	farmImage.setPosition(sf::Vector2f(305, 217));

	//buttons
	food_buttons.loadFromFile("Data/food_buttons.png");
	foodImage.setTexture(food_buttons);
	foodImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
	foodImage.setPosition(sf::Vector2f(30, 645));

	active = false;
	food_upgrade = 0;
	production = 5;
	factor = 1;
	upgrade_cost.set_position(200, 640);
	upgrade_info.set_position(300, 640);
}

farm::~farm() {
}

void farm::test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse) {

	int mouseX = sf::Mouse::getPosition(Window).x;
	int mouseY = sf::Mouse::getPosition(Window).y;

	//farm
	int farmX = farmImage.getPosition().x;
	int farmY = farmImage.getPosition().y;

	int farmWidth = farmImage.getTextureRect().width;
	int farmHeight = farmImage.getTextureRect().height;

	if ((mouseX > farmX && mouseX < (farmX+farmWidth)) && (mouseY > farmY && mouseY < (farmY+farmHeight))) {
		player_mouse.set_hover(true);
		hover = true;
		if (Event.mouseButton.button == sf::Mouse::Left && Event.type == sf::Event::MouseButtonReleased && !active) {
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
		upgrade_cost.set_text("Farm");
		upgrade_info.set_text("");
	}

	if (active) {
		//food button
		if ((mouseX > foodImage.getPosition().x && mouseX < (foodImage.getPosition().x+40)) && (mouseY > foodImage.getPosition().y && mouseY < (foodImage.getPosition().y+40))) {

			hover = true;
			upgrade_cost.set_text("Food: \t40\nWood:\t70\nStone:\t110\nGold: \t70");

			if (resources1->get_food() >= 40 && resources1->get_wood() >= 70 && resources1->get_stone() >= 110 && resources1->get_gold() >= 70) {
				player_mouse.set_hover(true);
				if (Event.mouseButton.button == sf::Mouse::Left) {
					if (Event.type == sf::Event::MouseButtonPressed) {
						foodImage.setTextureRect(sf::IntRect(food_upgrade*40, 40, 40, 40));
					}
					if (Event.type == sf::Event::MouseButtonReleased) {
						if (food_upgrade < 3) {
							resources1->decrease_food(40);
							resources1->decrease_wood(70);
							resources1->decrease_stone(110);
							resources1->decrease_gold(70);
							++food_upgrade;
							factor += 0.20;
							audio4.farm_up();
						}
						if (food_upgrade == 3)
							farmTexture.loadFromFile("Data/farm_max.png");
					}
				}
			}
			else {
				player_mouse.set_disable();
				upgrade_info.set_text("Not enough resources!");
			}
			if (food_upgrade > 2) {
				player_mouse.set_disable();
				upgrade_cost.set_text("Farm");
			}
			else
				upgrade_info.set_text("Increase base food \nproduction with 20%");
			//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
			sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
		}
		//reset button
		if (active && Event.mouseButton.button == sf::Mouse::Left && Event.type == sf::Event::MouseButtonReleased) {
			foodImage.setTextureRect(sf::IntRect(food_upgrade*40, 0, 40, 40));
		}
	}
}

void farm::draw(sf::RenderWindow &Window, hud &player_hud) {

	Window.draw(farmImage);

	if (!the_tutorial->active()) {
		if (active) {
		player_hud.draw_bottom(Window);
		Window.draw(foodImage);
		Window.draw(upgrade_cost.text1);
		Window.draw(upgrade_info.text1);
		}
	}
	else {
		switch (the_tutorial->farm_state()) {
			case 1:
				if (active) {
					player_hud.draw_bottom(Window);
					Window.draw(foodImage);
					Window.draw(upgrade_cost.text1);
					Window.draw(upgrade_info.text1);
				}
				break;
			case 2:
				active = true;
				player_hud.draw_bottom(Window);
				Window.draw(foodImage);
				Window.draw(upgrade_cost.text1);
				Window.draw(upgrade_info.text1);
				break;
			default:
				break;
		}
	}
}

int farm::get_production() {
	return production*factor ;
}

int farm::get_factor() {
	return factor;
}
void farm::reset_farm() {
	production = 5;
	food_upgrade = 0;
	factor = 1.0;
}

void farm::set_active(bool b) {
	active = b;
}