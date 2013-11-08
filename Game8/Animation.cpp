#include "Animation.h"

Animation::Animation() {
}


Animation::~Animation() {
}


void Animation::LoadContent(std::string text, sf::Texture image, sf::Vector2f position) {
	
	this->preText = text;
	this->image = image;
	this->position = position;

	alpha = 1.0f;
	textColor = sf::Color(114, 77, 255);

	if(image.getSize().y > 0) {
		
		sprite.setTexture(image);
	}

	
	this->text.setString(text);
	active = false;

}

void Animation::UnloadContent() {

	

}

void Animation::Update(sf::RenderWindow &Window) {

	

}

void Animation::Draw(sf::RenderWindow &Window) {

	
	std::string str = text.getString();

	if (str != "") {
		Window.draw(text);
	}
	
	
	if (sprite.getTexture() != NULL) {
		Window.draw(sprite);
	}

}

float Animation::GetAlpha() {

	return alpha;

}

void Animation::SetActive(bool value) {
	active = value;
}

void Animation::SetAlpha(float value) {

	alpha = value;

}