#include "farm.h"

farm::farm() {
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
		if (Event.mouseButton.button == sf::Mouse::Left)
			active = true;
	}
	else if (Event.mouseButton.button == sf::Mouse::Left && (mouseY < (Window.getSize().y-90) || mouseX > 500)) {
		active = false;
	}
	else if (hover) {
		player_mouse.set_hover(false);
		hover = false;
		upgrade_cost.set_text("Farm");
		upgrade_info.set_text("");
	}

	//button
	if ((mouseX > foodImage.getPosition().x && mouseX < (foodImage.getPosition().x+40)) && (mouseY > foodImage.getPosition().y && mouseY < (foodImage.getPosition().y+40))) {
		if (active) {
			if (Event.mouseButton.button == sf::Mouse::Left) {
				if (Event.type == sf::Event::MouseButtonPressed) {
					foodImage.setTextureRect(sf::IntRect(food_upgrade*40, 40, 40, 40));
				}
				if (Event.type == sf::Event::MouseButtonReleased) {
					if (food_upgrade < 3)
						++food_upgrade;
					if (food_upgrade == 3)
						farmTexture.loadFromFile("Data/farm_max.png");
				}
			}
			if (food_upgrade < 3) {
				player_mouse.set_hover(true);
				hover = true;
				upgrade_cost.set_text("Food:\t20\nWood:\t20\nStone:\t10\nGold:\t5");
				upgrade_info.set_text("Lorem ipsum..");
			}
			else {
				upgrade_cost.set_text("Farm");
				upgrade_info.set_text("");
			}
		}
	}
	//reset_button
	if (active && Event.mouseButton.button == sf::Mouse::Left && Event.type == sf::Event::MouseButtonReleased) {
		foodImage.setTextureRect(sf::IntRect(food_upgrade*40, 0, 40, 40));
	}

}

void farm::draw(sf::RenderWindow &Window, hud &player_hud) {
	Window.draw(farmImage);
	if (active) {
		player_hud.draw_bottom(Window);
		Window.draw(foodImage);
		Window.draw(upgrade_cost.text1);
		Window.draw(upgrade_info.text1);
	}
}