#include "text.h"

text::text() {
	font.loadFromFile("Data/arial.ttf");
	text1.setFont(font);
	text1.setCharacterSize(14);
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
