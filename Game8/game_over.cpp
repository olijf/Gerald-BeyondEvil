#include "game_over.h"

game_over::game_over(int screenWidth, int screenHeight) {
	game_overTexture.loadFromFile("Data/game_over.png");
	game_overImage.setTexture(game_overTexture);
	game_overImage.setPosition((screenWidth/2)-(game_overImage.getTextureRect().width/2), (screenHeight/2)-(game_overImage.getTextureRect().height/2));
	game_over_text.set_position(game_overImage.getPosition().x+40, game_overImage.getPosition().y+40);
}

game_over::~game_over() {

}

void game_over::win(bool b, sf::RenderWindow &Window) {
	if (b) {
		game_over_text.set_text("You are victorious!\n\nDruk spatie om verder te gaan..");
	}
	else {
		game_over_text.set_text("You have lost!\n\nDruk spatie om verder te gaan..");
	}
	Window.draw(game_overImage);
	Window.draw(game_over_text.text1);
}