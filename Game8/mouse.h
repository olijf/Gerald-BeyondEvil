#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class mouse {

private:
	sf::Texture mouseTexture;
	sf::Sprite mouseImage;

public:
	mouse();
	~mouse();

	void set_hover(bool hover);
	void set_disable();
	void draw(sf::RenderWindow &Window);

};

