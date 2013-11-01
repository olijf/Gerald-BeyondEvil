#include "text.h"

text::text(int x, int y, char text[], int size) {
	font.loadFromFile("Data/arial.ttf");
	text1.setFont(font);
	text1.setString(text);
	text1.setPosition(x, y);
	text1.setCharacterSize(size);
	text1.setColor(sf::Color::White);
}

text::~text() {
}

void text::draw(sf::RenderWindow &Window) {
	Window.draw(text1);
}

void text::set_text(const char *string) {
	text1.setString(string);
}

void text::set_position(int x, int y) {
	text1.setPosition(x, y);
}
