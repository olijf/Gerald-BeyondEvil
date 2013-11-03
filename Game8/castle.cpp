#include "castle.h"

castle::castle() {
	//castle
	castleTexture.loadFromFile("Data/castle.png");
	castleImage.setTexture(castleTexture);
	castleImage.setPosition(sf::Vector2f(47, 298));

	//buttons
	player_buttons.loadFromFile("Data/player_buttons.png");

	swordsmanImage.setTexture(player_buttons);
	swordsmanImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
	swordsmanImage.setPosition(sf::Vector2f(30, 650));

	archerImage.setTexture(player_buttons);
	archerImage.setTextureRect(sf::IntRect(40, 0, 40, 40));
	archerImage.setPosition(sf::Vector2f(80, 650));

	horsemanImage.setTexture(player_buttons);
	horsemanImage.setTextureRect(sf::IntRect(80, 0, 40, 40));
	horsemanImage.setPosition(sf::Vector2f(130, 650));

	active = false;
	upgrade_cost.set_position(200, 640);
	upgrade_info.set_position(300, 640);
}

castle::~castle() {
}

void castle::test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse, field_manager &player_manager) {

	int mouseX = sf::Mouse::getPosition(Window).x;
	int mouseY = sf::Mouse::getPosition(Window).y;

	//castle
	int castleX = castleImage.getPosition().x;
	int castleY = castleImage.getPosition().y;

	int castleWidth = castleImage.getTextureRect().width;
	int castleHeight = castleImage.getTextureRect().height;

	if ((mouseX > castleX && mouseX < (castleX+castleWidth)) && (mouseY > castleY && mouseY < (castleY+castleHeight))) {
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
		upgrade_cost.set_text("Castle");
		upgrade_info.set_text("");
	}

	//buttons
	//swordsman button
	if ((mouseX > swordsmanImage.getPosition().x && mouseX < (swordsmanImage.getPosition().x+40)) && (mouseY > swordsmanImage.getPosition().y && mouseY < (swordsmanImage.getPosition().y+40))) {
		if (active) {
			if (Event.mouseButton.button == sf::Mouse::Left) {
				if (Event.type == sf::Event::MouseButtonPressed) {
					swordsmanImage.setTextureRect(sf::IntRect(0, 40, 40, 40));
				}
				if (Event.type == sf::Event::MouseButtonReleased) {
					player_manager.new_unit(1, false);
				}
			}
			player_mouse.set_hover(true);
			hover = true;
			upgrade_cost.set_text("Food:\t30\nWood:\t10\nStone:\t0\nGold:\t10");
			upgrade_info.set_text("Lorem Ipsum1..");
		}
	}
	//archer button
	else if ((mouseX > archerImage.getPosition().x && mouseX < (archerImage.getPosition().x+40)) && (mouseY > archerImage.getPosition().y && mouseY < (archerImage.getPosition().y+40))) {
		if (active) {
			if (Event.mouseButton.button == sf::Mouse::Left) {
				if (Event.type == sf::Event::MouseButtonPressed) {
					archerImage.setTextureRect(sf::IntRect(40, 40, 40, 40));
				}
				if (Event.type == sf::Event::MouseButtonReleased) {
					player_manager.new_unit(2, false);
				}
			}
			player_mouse.set_hover(true);
			hover = true;
			upgrade_cost.set_text("Food:\t30\nWood:\t30\nStone:\t0\nGold:\t10");
			upgrade_info.set_text("Lorem Ipsum2..");
		}
	}
	//horseman button
	else if ((mouseX > horsemanImage.getPosition().x && mouseX < (horsemanImage.getPosition().x+40)) && (mouseY > horsemanImage.getPosition().y && mouseY < (horsemanImage.getPosition().y+40))) {
		if (active) {
			if (Event.mouseButton.button == sf::Mouse::Left) {
				if (Event.type == sf::Event::MouseButtonPressed) {
					horsemanImage.setTextureRect(sf::IntRect(80, 40, 40, 40));
				}
				if (Event.type == sf::Event::MouseButtonReleased) {
					player_manager.new_unit(3, false);
				}
			}
			player_mouse.set_hover(true);
			hover = true;
			upgrade_cost.set_text("Food:\t50\nWood:\t10\nStone:\t5\nGold:\t20");
			upgrade_info.set_text("Lorem Ipsum3..");
		}
	}
	//reset buttons
	if (Event.type == sf::Event::MouseButtonReleased) {
		swordsmanImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
		archerImage.setTextureRect(sf::IntRect(40, 0, 40, 40));
		horsemanImage.setTextureRect(sf::IntRect(80, 0, 40, 40));
	}

}

void castle::draw(sf::RenderWindow &Window, hud &player_hud) {
	Window.draw(castleImage);
	if (active) {
		player_hud.draw_bottom(Window);
		Window.draw(swordsmanImage);
		Window.draw(archerImage);
		Window.draw(horsemanImage);
		Window.draw(upgrade_cost.text1);
		Window.draw(upgrade_info.text1);
	}
}
