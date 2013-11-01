#include "unit.h"


void unit::draw(sf::RenderWindow &Window, int direction, bool movement, bool attack) {

	switch (direction) {
		case 0:
			source.y = Right;
			if (movement) {
				playerImage.move(.125, 0);
			}
			if (attack) {
				source.y = attackRight;
			}
			break;
		case 1:
			source.y = Left;
			if (movement) {
				playerImage.move(-.125, 0);
			}
			if (attack) {
				source.y = attackLeft;
			}
			break;
		default:
			break;
	}

	frameCounter += frameSpeed * clock.restart().asSeconds();
	if (frameCounter >= switchFrame) {
		frameCounter = 0;
		source.x++;
		if (source.x * 64 >= pTexture.getSize().x) {
			source.x = 0;
		}
	}

	if (!movement && !attack) {
		playerImage.setTextureRect(sf::IntRect(2 * 64, source.y * 64, 64, 64));
	}
	else {
		playerImage.setTextureRect(sf::IntRect(source.x * 64, source.y * 64, 64, 64));
	}

	Window.draw(playerImage);

	health_bar_back.setPosition(playerImage.getPosition().x + 16, playerImage.getPosition().y);
	Window.draw(health_bar_back);
	health_bar.setPosition(playerImage.getPosition().x + 16, playerImage.getPosition().y);
	Window.draw(health_bar);

}
