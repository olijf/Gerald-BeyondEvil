#include <SFML/Graphics.hpp>

#pragma once

class text {

public:
	text(int x, int y, char text[], int size);
	~text();

	void draw(sf::RenderWindow &Window);
	void set_text(const char *string);
	void set_position(int x, int y);

	sf::Font font;
	sf::Text text1;

};

