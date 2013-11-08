#include "audio.h"

#pragma once
/**
 *\file status.h
 *
 *\brief deze library bevat de klasse status
*
 * \class status
 *
 * \brief De status houdt het gezondsheidsniveau bij van de kastelen
 *
 * \author Olaf van der Kruk
 * \author Peter Markotic
 *
 * \version 1.0
 *
 * \date 2013/11/07
 */
class status{
private:
	signed int health_enemy, health_player;
	audio audio3;
	sf::Time time;
	sf::Clock clock;
public:
	/// Maakt een status object aan
	status();
	~status();
	
	/** \brief Haalt een amount levenspunten van het vijandig kasteel af 
	* \param amount de hoeveelheid health om er af te halen
	* \return void
	*/
	void health_down_enemy(int amount);
	
	/** \brief Haalt een amount levenspunten van het player kasteel af. 
	* \param amount de hoeveelheid health om er af te halen
	* \return void
	*
	* Deze methode speelt ook een geluid af om de vijf seconden
	*/
	void health_down_player(int amount);
	
	
	/** \brief Geeft de hoeveelheid health van je eigen kasteel
	* \return int Health
	*/
	int get_health_player();
	/** \brief Geeft de hoeveelheid health van je vijandig kasteel
	* \return int Health
	*/
	int get_health_enemy();
	
	/** \brief herstelt de health naar zijn standaard nivea
	/* \return void
	*/
	void reset_health();
};