/**
 *\file mouse.h
 *
 *\brief deze library bevat de klasse mouse
*
 * \class mouse
 *
 * \brief Zet op de positie van de muis een afbeelding.
 *
 * Deze klasse is verantwoordelijk voor het teken van de muis. De muis
 * kent vesrchillende staten namelijk hover en disable. Bij elke staat
 * hoort een andere afbeelding. Zo moet bijvoorbeeld bij een hover
 * de muis groen oplichten.
 *
 * \author Benjamin Meulenberg
 *
 * \version 1.0
 *
 * \date 04/11/2013
 *
 */

#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class mouse {

private:
	sf::Texture mouseTexture;
	sf::Sprite mouseImage;

public:
	
	/// Maakt een muis klasse aan en zet de benodigde afbeelding.
	mouse();
	
	~mouse();
	
	/** \brief Zet de hover staat van de muis aan/uit.
      * \param hover Krijgt een boolean waarde mee om de hover staat aan/uit te zetten.
      * \return void
	  * 
      * Deze methode maakt het mogelijk de muis te veranderen,
	  * in dit geval zal de muis groen oplichten wanneer de boolean
	  * om true gezet word. Bij het geven van een false boolean zal de muis
	  * terugkeren in zijn oorspronkelijke staat.
      */
	void set_hover(bool hover);
	
	/** \brief Zet de disable staat van de muis.
	  * \return void
      * 
      * Deze methode zorgt ervoor dat de muis is een disable staat
	  * terechtkomt. In dit geval zal de muis rood oplichten. De muis
	  * kan weer in zijn oorspronkelijke staat worden gezet door set_hover(false)
	  * aan te roepen.
      */
	void set_disable();
	
	/** \brief Tekent de muis op het scherm
      * \param &Window Krijgt de benodigde window mee waarop de muis getekend moet worden.
      * \return void
	  * 
      * Deze methode zorgt ervoor dat er een afbeelding getoond word
      * op de positie van de muis. De positie van de afbeelding wordt
      * continou geupdatet naar de positie van de muis. De standaard muis
      * is niet zichtbaar waardoor alleen de afbeelding getoond word.
      */
	void draw(sf::RenderWindow &Window);

};

