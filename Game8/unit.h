#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class unit {

protected:

	int health, damage, range;
	float factor;

public:

	unit();
	virtual ~unit(){};

	virtual void attack() {}
	//afhandelen in de field manager?... 
	virtual void die() {}

	void health_down(int val) {
		health=health-val;
	}
	int get_health(){
		return health*factor;
	}
	int get_damage(){
		return damage;
	}
	int get_range(){
		return range;
	}

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

