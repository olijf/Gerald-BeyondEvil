/**
 *\file game_over.h
 *
 *\brief deze library bevat de klasse game_over
 *
 * \class game_over
 *
 *
 * \brief deze klasse laat zien of je gewonnen of verloren hebt aan het einde van het spel
 *
 * \author Benjamin Meulenberg
 *
 * \version 1.0 
 *
 * \date 2013/11/7 16:30:20 
 *
 */#include <SFML/Graphics.hpp>

#include "text.h"

#pragma once

class game_over {

private:

sf::Texture game_overTexture;
sf::Sprite game_overImage;

text game_over_text;

public:
	/**hier word een game_over object aangemaakt
	*\param screenWidth is de breedte van het scherm
	*\param screenHeight is de hoogte van het scherm
	*/
	game_over(int screenWidth, int screenHeight);
	///hier word het game_over object verwijderd
	~game_over();
	
	/**deze functie laat op het scherm zien of je gewonnen of verloren hebt
	*\param b is de boolean die verteld of je gewonnen hebt (gewonnen=true en verloren=false)
	*\param Window is het window waar het gameover scherm op getoont word
	*\return void
	*/
	void win(bool b, sf::RenderWindow &Window);

};

