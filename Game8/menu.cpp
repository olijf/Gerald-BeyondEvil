#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.h"
#include "ScreenManager.h"

void initializeMenu(sf::RenderWindow &Window){
	sf::RectangleShape Fade;
	Fade.setPosition(0, 0);
	Fade.setSize(sf::Vector2f(ScreenWidth, ScreenHeight));
	Fade.setFillColor(sf::Color(255, 255, 255));
	ScreenManager::GetInstance().Initialize();
}

void drawMenu(sf::RenderWindow &Window) {
	
		
	sf::RectangleShape Fade;
	Fade.setPosition(0, 0);
	Fade.setSize(sf::Vector2f(ScreenWidth, ScreenHeight));
	Fade.setFillColor(sf::Color(255, 255, 255));

	
	ScreenManager::GetInstance().LoadContent();

	Window.setKeyRepeatEnabled(false);
	
	ScreenManager::GetInstance().setInMenu(true);
	while (Window.isOpen()&&ScreenManager::GetInstance().getInMenu()==true) {		
		sf::Event event;

		if (Window.pollEvent(event)) {

			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
				Window.close();
			}

		}

		Window.clear();

		ScreenManager::GetInstance().Update(Window, event);
		
		Fade.setFillColor(sf::Color(0, 0, 0, 255 * ScreenManager::GetInstance().GetAlpha()));

		ScreenManager::GetInstance().Draw(Window);
		Window.draw(Fade);

		Window.display();

	}
	ScreenManager::GetInstance().UnloadContent();
}