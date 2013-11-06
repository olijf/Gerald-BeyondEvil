#include <SFML/Graphics.hpp>

#pragma once

class text {

public:

	sf::Font font;
	sf::Text text1;

	text();
	~text();

	void draw(sf::RenderWindow &Window);
	void set_text(const char *string);
	void set_position(int x, int y);
	void set_color(sf::Color color);

};

