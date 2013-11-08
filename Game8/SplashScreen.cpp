#include "SplashScreen.h"
#include <iostream>


SplashScreen::SplashScreen() {
}

SplashScreen::~SplashScreen() {
}

void SplashScreen::LoadContent() {


	texture.loadFromFile("Data/texture.png");
	
	sprite.setTexture(texture);

}

void SplashScreen::UnloadContent() {
	
	maingamescreen::UnloadContent();

}

void SplashScreen::Update(sf::RenderWindow &Window, sf::Event event) {
	
	input.Update(event);
		
	if (input.KeyPressed()){
		
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
		
	}
}

void SplashScreen::Draw(sf::RenderWindow &Window) {
	Window.draw(sprite);
	
	//Window.draw(naam1);

}