#include "castle.h"

castle::castle(resources * resources2, tutorial * player_tutorial) {

	resources1 = resources2; 
	the_tutorial = player_tutorial;

	//castle
	castleTexture.loadFromFile("Data/castle.png");
	castleImage.setTexture(castleTexture);
	castleImage.setPosition(sf::Vector2f(47, 298));

	//buttons
	player_buttons.loadFromFile("Data/player_buttons.png");

	swordsmanImage.setTexture(player_buttons);
	swordsmanImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
	swordsmanImage.setPosition(sf::Vector2f(25, 642));

	archerImage.setTexture(player_buttons);
	archerImage.setTextureRect(sf::IntRect(40, 0, 40, 40));
	archerImage.setPosition(sf::Vector2f(75, 642));

	horsemanImage.setTexture(player_buttons);
	horsemanImage.setTextureRect(sf::IntRect(80, 0, 40, 40));
	horsemanImage.setPosition(sf::Vector2f(125, 642));

	active = false;
	upgrade_cost.set_position(200, 637);
	upgrade_info.set_position(300, 637);
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
		if (Event.mouseButton.button == sf::Mouse::Left && Event.type == sf::Event::MouseButtonReleased && !active) {
			active = true;
			//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
			sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
		}
	}
	else if (Event.mouseButton.button == sf::Mouse::Left && Event.type == sf::Event::MouseButtonReleased && (mouseY < (Window.getSize().y-100) || mouseX > 500)) {
		active = false;
		//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
		sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
	}
	else if (hover) {
		player_mouse.set_hover(false);
		hover = false;
		upgrade_cost.set_text("Castle");
		upgrade_info.set_text("");
	}

	if (active) {
		//swordsman button
		if ((mouseX > swordsmanImage.getPosition().x && mouseX < (swordsmanImage.getPosition().x+40)) && (mouseY > swordsmanImage.getPosition().y && mouseY < (swordsmanImage.getPosition().y+40))) {

			hover = true;
			upgrade_cost.set_text("Food: \t30\nWood:\t20\nStone:\t5\nGold: \t30");

			if (resources1->get_food() >= 30 && resources1->get_wood() >= 20 && resources1->get_stone() >= 5 && resources1->get_gold() >= 30) {
				player_mouse.set_hover(true);
				upgrade_info.set_text("Swordsman\nStrong against buildings");
				if (Event.mouseButton.button == sf::Mouse::Left) {
					if (Event.type == sf::Event::MouseButtonPressed) {
						swordsmanImage.setTextureRect(sf::IntRect(0, 40, 40, 40));
					}
					if (Event.type == sf::Event::MouseButtonReleased) {
						resources1->decrease_food(30);
						resources1->decrease_wood(20);
						resources1->decrease_stone(5);
						resources1->decrease_gold(30);
						player_manager.new_unit(1, false);
						audio1.spawn_swordsman();					
					}
				}
			}
			else {
				player_mouse.set_disable();
				upgrade_info.set_text("Not enough resources!");
			}
			//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
			sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
		}
		//archer button
		else if ((mouseX > archerImage.getPosition().x && mouseX < (archerImage.getPosition().x+40)) && (mouseY > archerImage.getPosition().y && mouseY < (archerImage.getPosition().y+40))) {

			hover = true;
			upgrade_cost.set_text("Food: \t25\nWood:\t30\nStone:\t5\nGold: \t20");

			if (resources1->get_food() >= 25 && resources1->get_wood() >= 30 && resources1->get_stone()>= 5 && resources1->get_gold() >= 20) {
				player_mouse.set_hover(true);
				upgrade_info.set_text("Archer\nStrong because of long range");
				if (Event.mouseButton.button == sf::Mouse::Left) {
					if (Event.type == sf::Event::MouseButtonPressed) {
						archerImage.setTextureRect(sf::IntRect(40, 40, 40, 40));
					}
					if (Event.type == sf::Event::MouseButtonReleased) {
						resources1->decrease_food(25);
						resources1->decrease_wood(30);
						resources1->decrease_stone(5);
						resources1->decrease_gold(20);
						player_manager.new_unit(2, false);
						audio1.spawn_archer();
					}
				}
			}
			else {
				player_mouse.set_disable();
				upgrade_info.set_text("Not enough resources!");
			}
			//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
			sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
		}
		//horseman button
		else if ((mouseX > horsemanImage.getPosition().x && mouseX < (horsemanImage.getPosition().x+40)) && (mouseY > horsemanImage.getPosition().y && mouseY < (horsemanImage.getPosition().y+40))) {

			hover = true;
			upgrade_cost.set_text("Food: \t60\nWood:\t40\nStone:\t10\nGold: \t40");

			if (resources1->get_food() >= 60 && resources1->get_wood() >= 40 && resources1->get_stone() >= 10 && resources1->get_gold() >= 40) {
				player_mouse.set_hover(true);
				upgrade_info.set_text("Horseman\nStrong as a tank");
				if (Event.mouseButton.button == sf::Mouse::Left && spawn) {
					if (Event.type == sf::Event::MouseButtonPressed) {
						horsemanImage.setTextureRect(sf::IntRect(80, 40, 40, 40));
					}
					if (Event.type == sf::Event::MouseButtonReleased) {
						resources1->decrease_food(60);
						resources1->decrease_wood(40);
						resources1->decrease_stone(10);
						resources1->decrease_gold(40);
						player_manager.new_unit(3, false);
						audio1.spawn_horseman();
					}
				}
			}
			else {
				player_mouse.set_disable();
				upgrade_info.set_text("Not enough resources!");
			}
			//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
			sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
		}
		//reset buttons
		if (Event.type == sf::Event::MouseButtonReleased) {
			swordsmanImage.setTextureRect(sf::IntRect(0, 0, 40, 40));
			archerImage.setTextureRect(sf::IntRect(40, 0, 40, 40));
			horsemanImage.setTextureRect(sf::IntRect(80, 0, 40, 40));
		}
	}
}

void castle::draw(sf::RenderWindow &Window, hud &player_hud) {

	Window.draw(castleImage);

	if (!the_tutorial->active()) {
		if (active) {
		player_hud.draw_bottom(Window);
		Window.draw(swordsmanImage);
		Window.draw(archerImage);
		Window.draw(horsemanImage);
		Window.draw(upgrade_cost.text1);
		Window.draw(upgrade_info.text1);
		}
	}
	else {
		switch (the_tutorial->castle_state()) {
			case 1:
				if (active) {
					player_hud.draw_bottom(Window);
					Window.draw(swordsmanImage);
					Window.draw(archerImage);
					Window.draw(horsemanImage);
					Window.draw(upgrade_cost.text1);
					Window.draw(upgrade_info.text1);
				}
				break;
			case 2:
				active = true;
				player_hud.draw_bottom(Window);
				Window.draw(swordsmanImage);
				Window.draw(archerImage);
				Window.draw(horsemanImage);
				Window.draw(upgrade_cost.text1);
				Window.draw(upgrade_info.text1);
				break;
			default:
				break;
		}
	}
}

void castle::set_active(bool b) {
	active = b;
}