#include "ScreenManager.h"

maingamescreen *currentScreen, *newScreen;

ScreenManager &ScreenManager::GetInstance() {
	static ScreenManager instance;
	return instance;
}

ScreenManager::ScreenManager() {
	wStartAnimation=true;
}


ScreenManager::~ScreenManager() {
	wStartAnimation=true;
}

float ScreenManager::GetAlpha() {
	return fade.GetAlpha();
}

void ScreenManager::Transition(sf::RenderWindow &Window) {
	
	if (transition) {
		
		fade.Update(Window);
		
		if (fade.GetAlpha() >= 1.0f) {
			
			currentScreen->UnloadContent();
			delete currentScreen;
			currentScreen = newScreen;
			currentScreen->LoadContent();
			newScreen = NULL;
						
		}
		else if (fade.GetAlpha() <= 0.0f) {
			if(wStartAnimation==true){
				wStartAnimation=false;
				fade.SetActive(true);
			}
			else{
				wStartAnimation=true;
				transition = false;
				fade.SetActive(false);
			}
			

		}

	}

}

void ScreenManager::AddScreen(maingamescreen *screen) {
	
	transition = true;
	newScreen = screen;
	fade.SetActive(true);
	fade.SetAlpha(0.0f);

}

void ScreenManager::Initialize() {
	
	currentScreen = new SplashScreen();
	transition = false;

}

void ScreenManager::LoadContent() {

	currentScreen->LoadContent();
	
	
	sf::Texture image;
	sf::Vector2f pos;
	fade.LoadContent("", image, pos);
	fade.SetAlpha(0.0f);

}

void ScreenManager::UnloadContent() {
	
}

void ScreenManager::Update(sf::RenderWindow &Window, sf::Event event) {
	if (!transition) {
		currentScreen->Update(Window, event);
	}
	Transition(Window);
}

void ScreenManager::Draw(sf::RenderWindow &Window) {
	currentScreen->Draw(Window);
}