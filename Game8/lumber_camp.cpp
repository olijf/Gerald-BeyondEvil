#include "lumber_camp.h"

lumber_camp::lumber_camp() {
	//lumber_camp
	lumber_campTexture.loadFromFile("Data/lumber_camp.png");
	lumber_campImage.setTexture(lumber_campTexture);
	lumber_campImage.setPosition(sf::Vector2f(65, 72));

	//buttons
	wood_buttons.loadFromFile("Data/wood_buttons.png");
	woodImage.setTexture(wood_buttons);
	woodImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
	woodImage.setPosition(sf::Vector2f(30, 650));

	active = false;
	wood_upgrade = 0;
	upgrade_cost.set_position(200, 640);
	upgrade_info.set_position(300, 640);
}

lumber_camp::~lumber_camp() {
}

void lumber_camp::test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse) {

	int mouseX = sf::Mouse::getPosition(Window).x;
	int mouseY = sf::Mouse::getPosition(Window).y;

	//lumber_camp
	int lumber_campX = lumber_campImage.getPosition().x;
	int lumber_campY = lumber_campImage.getPosition().y;

	int lumber_campWidth = lumber_campImage.getTextureRect().width;
	int lumber_campHeight = lumber_campImage.getTextureRect().height;

	if ((mouseX > lumber_campX && mouseX < (lumber_campX+lumber_campWidth)) && (mouseY > lumber_campY && mouseY < (lumber_campY+lumber_campHeight))) {
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
	}

	//button
	if ((mouseX > woodImage.getPosition().x && mouseX < (woodImage.getPosition().x+40)) && (mouseY > woodImage.getPosition().y && mouseY < (woodImage.getPosition().y+40))) {
		if (active) {
			if (Event.mouseButton.button == sf::Mouse::Left) {
				if (Event.type == sf::Event::MouseButtonPressed) {
					woodImage.setTextureRect(sf::IntRect(wood_upgrade*40, 40, 40, 40));
				}
				if (Event.type == sf::Event::MouseButtonReleased) {
					if (wood_upgrade < 2)
						++wood_upgrade;
					if (wood_upgrade == 2)
						lumber_campTexture.loadFromFile("Data/lumber_camp_max.png");
				}
			}
			if (wood_upgrade < 2) {
				player_mouse.set_hover(true);
				hover = true;
				upgrade_cost.set_text("Food:\t20\nWood:\t20\nStone:\t10\nGold:\t5");
				upgrade_info.set_text("Lorem Ipsum..");
			}
			else {
				upgrade_cost.set_text("Lumber Camp");
				upgrade_info.set_text("");
			}
		}
	}
	//reset_button
	if (active && Event.mouseButton.button == sf::Mouse::Left && Event.type == sf::Event::MouseButtonReleased) {
		woodImage.setTextureRect(sf::IntRect(wood_upgrade*40, 0, 40, 40));
	}

}

void lumber_camp::draw(sf::RenderWindow &Window, hud &player_hud) {
	Window.draw(lumber_campImage);
	if (active) {
		player_hud.draw_bottom(Window);
		Window.draw(woodImage);
		Window.draw(upgrade_cost.text1);
		Window.draw(upgrade_info.text1);
	}
}