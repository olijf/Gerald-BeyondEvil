#include "tutorial.h"

tutorial::tutorial(mouse *player_mouse) {

	tutorial_mouse = player_mouse;

	questionTexture.loadFromFile("Data/question_mark.png");
	questionImage.setTexture(questionTexture);
	questionImage.setPosition(sf::Vector2f(620, 5));

	tutorialTexture.loadFromFile("Data/hud_bottom.png");
	tutorialImage.setTexture(tutorialTexture);
	tutorialImage.setPosition(sf::Vector2f(1280-500, 620));

	focus.setFillColor(sf::Color::Transparent);
	focus.setOutlineColor(sf::Color::Red);
	focus.setOutlineThickness(3);

	tutorial_text.set_position(1280-480, 635);
	tutorial_text.set_text("Tutorial - Begin\nWelkom bij de tutorial van Gerald Beyond Evil. Klik weer op het\nvraagteken om de tutorial af te sluiten en spatie om verder te gaan..");

	tutorial_step = 0;

	tutorial_active = false;
	farm_active = 0;
	lumber_camp_active = 0;
	mining_camp_active = 0;
	castle_active = 0;

	hover = false;
}


tutorial::~tutorial() {}

void tutorial::next_step(int step) {
	switch(step) {
		case 1:
			focus.setPosition(3, 3);
			focus.setSize(sf::Vector2f(494, 24));
			tutorial_text.set_text("Resources\nLinksboven zijn al je resources zichtbaar. Rechts naast je resources staat\nde health van je kasteel, als deze leeg is heb je de strijd verloren.\nKlik spatie om verder te gaan..");
			break;
		case 2:
			farm_active = 1;
			focus.setPosition(305, 217);
			focus.setSize(sf::Vector2f(120, 132));
			tutorial_text.set_text("Resources - Food\nKlik op de farm om deze te openen.\nDruk spatie om verder te gaan..");
			break;
		case 3:
			farm_active = 2;
			focus.setPosition(3, 624);
			focus.setSize(sf::Vector2f(494, 94));
			tutorial_text.set_text("Resources - Food\nHet venster linksonder toont de mogelijke upgrades die je kunt\nkopen voor de farm. In dit geval zal de upgrade je voedselinkomsten\nverhogen. Druk spatie om verder te gaan..");
			break;
		case 4:
			farm_active = 0;
			lumber_camp_active = 1;
			focus.setPosition(65, 72);
			focus.setSize(sf::Vector2f(131, 145));
			tutorial_text.set_text("Resources - Wood\nKlik op de lumber camp om deze te openen.\nDruk spatie om verder te gaan..");
			break;
		case 5:
			lumber_camp_active = 2;
			focus.setPosition(3, 624);
			focus.setSize(sf::Vector2f(494, 94));
			tutorial_text.set_text("Resources - Wood\nHet venster linksonder toont de mogelijke upgrades die je kunt\nkopen voor de lumber camp. In dit geval zal de upgrade je houtinkomsten\nverhogen. Druk spatie om verder te gaan..");
			break;
		case 6:
			lumber_camp_active = 0;
			mining_camp_active = 1;
			focus.setPosition(285, 38);
			focus.setSize(sf::Vector2f(223, 100));
			tutorial_text.set_text("Resources - Stone/Gold\nKlik op de mining camp om deze te openen.\nDruk spatie om verder te gaan..");
			break;
		case 7:
			mining_camp_active = 2;
			focus.setPosition(3, 624);
			focus.setSize(sf::Vector2f(494, 94));
			tutorial_text.set_text("Resources - Stone/Gold\nHet venster linksonder toont de mogelijke upgrades die je kunt\nkopen voor de mining camp.\nDruk spatie om verder te gaan..");
			break;
		case 8:
			mining_camp_active = 0;
			castle_active = 1;
			focus.setPosition(47, 298);
			focus.setSize(sf::Vector2f(218, 229));
			tutorial_text.set_text("Aanval\nKlik op het kasteel om deze te openen.\nDruk spatie om verder te gaan..");
			break;
		case 9:
			castle_active = 2;
			focus.setPosition(3, 624);
			focus.setSize(sf::Vector2f(494, 94));
			tutorial_text.set_text("Aanval\nHet venster linksonder toont de mogelijke units die je kunt\nkopen om een aanval in te zetten.\nDruk spatie om verder te gaan..");
			break;
		case 10:
			castle_active = 0;
			focus.setOutlineThickness(0);
			tutorial_text.set_text("Tutorial - Einde\nDit was het einde van de tutorial. Veel plezier met spelen!\nDruk spatie om de tutorial af te sluiten..");
			break;
		default:
			tutorial_active = false;
			questionImage.setPosition(-100, -100);
			break;
	}
}

bool tutorial::active() {
	return tutorial_active;
}
int tutorial::farm_state() {
	return farm_active;
}
int tutorial::lumber_camp_state() {
	return lumber_camp_active;
}
int tutorial::mining_camp_state() {
	return mining_camp_active;
}
int tutorial::castle_state() {
	return castle_active;
}

void tutorial::draw(sf::RenderWindow &Window, sf::Event &Event) {
	Window.draw(questionImage);

	int mouseX = sf::Mouse::getPosition(Window).x;
	int mouseY = sf::Mouse::getPosition(Window).y;

	if ((mouseX > questionImage.getPosition().x && mouseX < (questionImage.getPosition().x+40)) && (mouseY > questionImage.getPosition().y && mouseY < (questionImage.getPosition().y+40))) {
		if (Event.mouseButton.button == sf::Mouse::Left && Event.type == sf::Event::MouseButtonReleased) {
			if (tutorial_active) {
				tutorial_active = false;
				farm_active = true;
				lumber_camp_active = true;
				mining_camp_active = true;
				castle_active = true;
			}
			else {
				tutorial_active = true;
				farm_active = false;
				lumber_camp_active = false;
				mining_camp_active = false;
				castle_active = false;
				if (tutorial_step > 0)
					next_step(tutorial_step);
			}
		}
		tutorial_mouse->set_hover(true);
		hover = true;
	}
	else if (hover) {
		tutorial_mouse->set_hover(false);
		hover = false;
	}

	if (tutorial_active) {
		if ((Event.type == sf::Event::KeyReleased && Event.key.code == sf::Keyboard::Space)) {
			next_step(++tutorial_step);
			//workaround - changes the event otherwise sf::Event::KeyReleased is called repeatedly
			sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition(Window).x, sf::Mouse::getPosition(Window).y), Window);
		}
		Window.draw(tutorialImage);
		Window.draw(focus);
		Window.draw(tutorial_text.text1);
	}
}
