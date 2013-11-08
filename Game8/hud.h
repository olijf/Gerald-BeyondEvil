/**
 *\file hud.h
 *
 *\brief deze library bevat de klasse hud
 *
 *
 *\class hud
 *
 *
 * \brief deze klasse laat het heads up display zien op het scherm
 *
 * \author Benjamin Meulenberg
 *
 * \version 1.0 
 *
 * \date 2013/11/7 16:30:20 
 *
 */#include <SFML/Graphics.hpp>
#include <iostream>
#include "status.h"

#pragma once

class hud {

private:

sf::Texture hud_topTexture, hud_bottomTexture, hud_enemyTexture;
sf::Sprite hud_topImage, hud_bottomImage, hud_enemyImage;

	sf::RectangleShape health_enemy;
	sf::RectangleShape health_player;
		
	status &stat;

public:
/**Hier word een hud object aangemaakt
*\param blah is het huidige health niveau van het kasteel
*/
hud(status &blah);
///Hier word het hud object verwijderd
~hud();

/**Tekent de hud an de bovekant van het scherm met de recources en het health niveau van het kasteel
*\param Window is het window waar de hud op getoont moet worden
*/
void draw_top(sf::RenderWindow &Window);
/**Tekent de hud an de onderkant van het scherm met de knoppen voor het bouwen van units en upgraden van je recources gebouwen
*\param Window is het window waar de hud op getoont moet worden
*/
void draw_bottom(sf::RenderWindow &Window);

};