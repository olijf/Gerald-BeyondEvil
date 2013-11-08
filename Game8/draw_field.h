/**
 *\file draw_field.h
 *
 *\brief deze library bevat de klasse draw_field
 *
 * \class draw_field
 *
 *
 * \brief deze klasse laat de achtergrond van het level zien
 *
 * \author Benjamin Meulenberg
 *
 * \version 1.0 
 *
 * \date 2013/11/7 16:30:20 
 *
 */#pragma once

#include <SFML/Graphics.hpp>

class draw_field {

private:

sf::Texture fieldTexture;
sf::Sprite fieldImage;

public:
///maakt een draw_field object aan
draw_field();
///verwijderd een draw_field object
~draw_field();
/**tekent de achtergrond op het scherm
*\param Window is het window waarnaar de achtergrond geschreven moet worden
*\return void
*/
void draw(sf::RenderWindow &Window);

};