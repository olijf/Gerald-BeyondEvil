#include "lumber_camp.h"

lumber_camp::lumber_camp(resources * resources2, tutorial * player_tutorial) {

	resources1 = resources2;
	the_tutorial = player_tutorial;

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
	production = 5;
	factor = 1.0;
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
		upgrade_cost.set_text("Lumber Camp");
		upgrade_info.set_text("");
	}

	if (active) {
		//wood button
		if ((mouseX > woodImage.getPosition().x && mouseX < (woodImage.getPosition().x+40)) && (mouseY > woodImage.getPosition().y && mouseY < (woodImage.getPosition().y+40))) {
			
			hover = true;
			upgrade_cost.set_text("Food: \t40\nWood:\t50\nStone:\t100\nGold: \t60");

			if(resources1->get_food() >= 40 && resources1->get_wood() >= 50 && resources1->get_stone() >= 100 && resources1->get_gold() >= 60) {
				player_mouse.set_hover(true);
				if (Event.mouseButton.button == sf::Mouse::Left) {
					if (Event.type == sf::Event::MouseButtonPressed) {
						woodImage.setTextureRect(sf::IntRect(wood_upgrade*40, 40, 40, 40));
					}
					if (Event.type == sf::Event::MouseButtonReleased) {
						if (wood_upgrade < 2) {
							audio4.lumber_up();
							resources1->decrease_food(40);
							resources1->decrease_wood(50);
							resources1->decrease_stone(100);
							resources1->decrease_gold(60);
							++wood_upgrade;
							factor += 0.20;
						}
						if (wood_upgrade == 2)
							lumber_campTexture.loadFromFile("Data/lumber_camp_max.png");
					}
				}
			}
			else {
				player_mouse.set_disable();
				upgrade_info.set_text("Not enough resources!");
			}
			if (wood_upgrade > 1) {
				player_mouse.set_disable();
				upgrade_cost.set_text("Lumber Camp");
			}
			else
				upgrade_info.set_text("Increase base wood \nproduction with 20%");
			//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
			sf::Mouse::setPosition(sf::Vector2i(mouseX, mouseY), Window);
		}
		//reset button
		if (active && Event.mouseButton.button == sf::Mouse::Left && Event.type == sf::Event::MouseButtonReleased) {
			woodImage.setTextureRect(sf::IntRect(wood_upgrade*40, 0, 40, 40));
		}
	}
}

void lumber_camp::draw(sf::RenderWindow &Window, hud &player_hud) {

	Window.draw(lumber_campImage);

	if (!the_tutorial->active()) {
		if (active) {
		player_hud.draw_bottom(Window);
		Window.draw(woodImage);
		Window.draw(upgrade_cost.text1);
		Window.draw(upgrade_info.text1);
		}
	}
	else {
		switch (the_tutorial->lumber_camp_state()) {
			case 1:
				if (active) {
					player_hud.draw_bottom(Window);
					Window.draw(woodImage);
					Window.draw(upgrade_cost.text1);
					Window.draw(upgrade_info.text1);
				}
				break;
			case 2:
				active = true;
				player_hud.draw_bottom(Window);
				Window.draw(woodImage);
				Window.draw(upgrade_cost.text1);
				Window.draw(upgrade_info.text1);
				break;
			default:
				break;
		}
	}
}

int lumber_camp::get_production(){
	return production*factor;
}

float lumber_camp::get_factor() {
	return factor;
}

void lumber_camp::reset_lumber() {
	production = 5;
	wood_upgrade = 0;
	factor = 1.0;
}

void lumber_camp::set_active(bool b) {
	active = b;
}