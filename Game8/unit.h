#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once
/**
 *\file unit.h
 *
 *\brief deze library bevat de klasse unit
*
 * \class unit
 *
 * \brief de klasse unit is de hoofd klasse van de verschillende eenheden
 *
 * \author Olaf van der Kruk
 * \author Ben Meulenberg
 * \author Peter Markotic
 *
 * \version 1.0
 *
 * \date 2013/11/07
 */

class unit {

protected:

	int health, damage, range, speed, castle_damage;
	float factor;
	
	enum Direction { Left, Right, attackLeft, attackRight };

	float frameCounter, switchFrame, frameSpeed;
	
	sf::Vector2i source;

	sf::Texture pTexture;
	sf::Sprite playerImage;
	sf::RectangleShape health_bar_back;
	sf::RectangleShape health_bar;
	sf::Clock clock;

public:

	/** \brief maakt een unit object aan */
	unit();
		
	/** \brief deze methode is virtual omdat de eenheden verschillende dingen doen bij het doodgaan */
	virtual ~unit(){};

	/** \brief verandert de hoeveelheid health van de eenheid
	* \param val de hoeveelheid health om er af te halen
	* \return void
	*/
	void health_down(int val) {
		health=health-val;
	}
	
	/** \brief geeft de hoeveelheid health terug van de eenheid
	* \return int health
	*/
	int get_health(){
		return health*factor;
	}
	
	/** \brief geeft de hoeveelheid damage terug van de eenheid
	* \return int damage
	*/
	int get_damage(){
		return damage;
	}
	
	/** \brief geeft de hoeveelheid damage die de eenheid aan een kasteel kan doen 
	* \return int castle_damage
	*/
	int get_castle_damage(){
		return castle_damage;
	}
	
	/** \brief geeft de afstand waarover een eenheid schade kan doen
	* \return int afstand
	*/
	int get_range(){
		return range;
	}

	/** \brief geeft de x positie terug van de eenheid
	* \return int roept de get position methode aan van de afbeelding
	*/
	int get_x() {
		return playerImage.getPosition().x;
	}
	
	/** \brief bepaald de x positie terug van de eenheid
	* \return void
	*/	
	void set_x(int pos){
		playerImage.setPosition(sf::Vector2f(pos, 468));
	}

	/** \brief geeft de x positie terug van de eenheid
	* \param &Window de window waarnaar deze draw functie moet schrijven
	* \param direction bepaald de richting van de eenheid
	* \param movement bepaald of de eenheid moet bewegen
	* \param attack bepaald of de eenheid moet aanvallen
	* \return void
	*/
	
	void draw(sf::RenderWindow &Window, int direction, bool movement, bool attack);

};

