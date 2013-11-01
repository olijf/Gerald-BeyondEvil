#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class unit {

private:

int health, damage, range;

public:

	unit(){};
	virtual ~unit(){};

virtual void attack() {}

virtual void die() {}

virtual void health_down() {}

sf::Texture pTexture;
sf::Sprite playerImage;
sf::RectangleShape health_bar_back;
sf::RectangleShape health_bar;
sf::Clock clock;

int get_x() {
	//std::cout<< (int)playerImage.getPosition().x <<'\n';
	return playerImage.getPosition().x;
}
void set_x(int pos){
	playerImage.setPosition(sf::Vector2f(pos, 468));
}

enum Direction { Left, Right, attackLeft, attackRight };

float frameCounter, switchFrame, frameSpeed;

void draw(sf::RenderWindow &Window, int direction, bool movement, bool attack);
sf::Vector2i source;

};

