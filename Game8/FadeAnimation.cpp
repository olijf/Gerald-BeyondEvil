#include "FadeAnimation.h"
#include <iostream>

FadeAnimation::FadeAnimation() {
}

FadeAnimation::~FadeAnimation() {
}

void FadeAnimation::LoadContent(std::string text, sf::Texture image, sf::Vector2f position) {

	Animation::LoadContent(text, image, position);
	increase = false;
	fadeSpeed = 1.0f;

}

void FadeAnimation::UnloadConent() {

}

void FadeAnimation::Update(sf::RenderWindow &Window) {

	if (active) {
		
		
		if (!increase) {
			
			alpha -= 0.02 * fadeSpeed;
			
		}
		else {
			
			alpha += 0.02 * fadeSpeed;
			
		}

		if (alpha >= 1.0f) {
		
			alpha = 1.0f;
			increase = false;

		}
		else if (alpha <= 0.0f) {

			alpha = 0.0f;
			increase = true;

		}

	}
	else {
		alpha = 1.0f;
	}

}

void FadeAnimation::Draw(sf::RenderWindow &Window) {

	Animation::Draw(Window);

}

void FadeAnimation::SetAlpha(float value) {

	alpha = value;

	if (alpha = 0.0f) {
		increase = true;
	}
	else {
		increase = false;
	}

}