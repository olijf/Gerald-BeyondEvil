/**
 *\file text.h
 *
 *\brief deze library bevat de klasse text
 *
 * \class text
 *
 * \brief Maakt het mogelijk text op het scherm te plaatsen.
 *
 * Deze klasse is verantwoordelijk voor het teken van tekst op het scherm.
 * De kleur, positie en tekst kunnen aangepast worden.
 *
 * \author Benjamin Meulenberg
 *
 * \version 1.1
 *
 * \date 05/11/2013
 *
 */

#include <SFML/Graphics.hpp>

#pragma once

class text {
	
private:
	
	sf::Font font;

public:
	
	sf::Text text1;
	
	/// Maakt een text klasse aan geeft alvast de font en size op.
	text();
	
	~text();
	
	/** \brief Zet de benodigde tekst die getoond moet worden.
      * \param *string De tekst die getoond moet worden.
      * \return void
      * 
      * Deze methode zet de opgegeven tekst die moet worden getoond op het scherm.
      */
	void set_text(const char *string);
	
	/** \brief Zet de positie van de tekst
      * \param x De x waarde relatief van het scherm gezien.
      * \param y De y waarde relatief van het scherm gezien.
      * \return void
      * 
      * Deze methode zet de tekst op de plaats van de gegeven coordinaten.
      */
	void set_position(int x, int y);
	
	/** \brief Zet de kleur van de tekst
      * \param color De gegeven kleur die de tekst moet krijgen.
      * \return void
      * 
      * Deze methode veranderd de kleur van de tekst.
      */
	void set_color(sf::Color color);
	
	/** \brief Tekent de tekst op het scherm
      * \param &Window Krijgt de benodigde window mee waarop de tekst getekend moet worden.
      * \return void
      * 
      * Deze methode zorgt ervoor dat de eerder opgegeven tekst op de gegeven positie getoond wordt.
      */
	void draw(sf::RenderWindow &Window);

};

