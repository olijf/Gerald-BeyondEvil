#include "TitleScreen.h"
#include <iostream>


TitleScreen::TitleScreen() {
}

TitleScreen::~TitleScreen() {
}

void TitleScreen::LoadContent() {


	texture.loadFromFile("Data/menu.png");
	sp.loadFromFile("Data/menusp.png");
	lb.loadFromFile("Data/menulb.png");
	c.loadFromFile("Data/menuc.png");
	e.loadFromFile("Data/menue.png");
	sprite.setTexture(texture);
	keys.push_back(sf::Keyboard::Z);
	keys.push_back(sf::Keyboard::Return);

}

void TitleScreen::UnloadContent() {

	maingamescreen::UnloadContent();

}

void TitleScreen::Update(sf::RenderWindow &Window, sf::Event event) {
	sf::Vector2i muis = sf::Mouse::getPosition(Window); 	
	input.Update(event);
	int muisx=muis.x;
	int muisy=muis.y;
	//singleplayer button
	if ((muisx>=24 && muisx<=217)&& (muisy>=145 && muisy <=188)){
		sprite.setTexture(sp);
	
		if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased) {
			ScreenManager::GetInstance().setInMenu(false);
			Window.setMouseCursorVisible(false);
			//workaround - changes the event otherwise sf::Mouse::Left is called repeatedly
			//sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition(Window).x, sf::Mouse::getPosition(Window).y), Window);
		}
	}
	
	

	//credits button
	else if ((muisx>=24 && muisx<=217)&& (muisy>=298 && muisy <=332)){

		sprite.setTexture(c);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
			ScreenManager::GetInstance().AddScreen(new SplashScreen);
		}
	}
	//exit button
	else if ((muisx>=24 && muisx<=217)&& (muisy>=403 && muisy <=446)){
		sprite.setTexture(e);
	
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
			Window.close();
		}
	}
	else{
		sprite.setTexture(texture);
	}
}

void TitleScreen::Draw(sf::RenderWindow &Window) {
	
	Window.draw(sprite);
}