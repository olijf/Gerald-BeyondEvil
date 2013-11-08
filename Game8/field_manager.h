#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "swordsman.h"
#include "archer.h"
#include "horseman.h"
#include "status.h"
#include "audio.h"

#pragma once
/**
 *\file field_manager.h
 *
 *\brief deze library bevat de klasse field_manager
*
 * \class field_manager
 *
 * \brief De field_manager beheert de eenheden
 *
 * De field_manager gebruikt een vector array om de eenheden te beheren. 
 * En deze klasse roept de individuele draw events van de unit aan.
 *
 * \author Olaf van der Kruk
 * \author Ben Meulenberg
 * \author Peter Markotic
 *
 * \version 1.0
 *
 * \date 2013/11/07
 */
typedef std::vector<unit*> unitlist;

class field_manager {

private:

	unitlist p;
	unit* s;
	status &stat;
	audio audio2;

public:
	/// Maakt een field_manager object aan
	field_manager();
	
	/** Maakt een field_manager object aan, en zet het adres van status
	* \param &stats de reference naar het status object
	*/
	field_manager(status &stats):stat(stats){}
	~field_manager();

	/** \brief Maakt een unit aan
	* \param type type van de unit
	* \param enemy bepaald de start positie
	* \return void
	*
	* De new_unit methode voegt een unit van type aan de unit list toe
	*/
	void new_unit(int type, bool enemy);

	/** \brief tekent een unit op de Window
	* \param &Window De referentie naar de window
	* \param dir bepaald de richting dat de eenheden uit de unitlist oplopen
	* \param &m de vijandige field_manager
	* \return void 
	*
	* De draw methode tekend de eenheden op de window.
	* Hij loopt door de array heen, vergelijkt deze met de voorkant van de vijandige positie, of de positie van de voorganger
	* en bepaald of de eenheid moet stoppen, aanvallen of verder lopen doormiddel van de calculate_distance methode.
	* Ook wordt er gekeken naar de afstand tot het kasteel van de voorste unit. 
	*/
	void draw(sf::RenderWindow &Window, int dir, field_manager &m);

	/** \brief Geeft de waarde tussen twee unit objecten terug
	* \param &obj1 unit waarde 1
	* \param &obj2 unit waarde 2
	* \return geeft een float waarde terug als afstand tussen beide eenheden
	*/
	float calculate_distance(unit * &obj1, unit * &obj2);

	/** \brief geeft de lengte van de unit list terug
	* \return unit list length()
	*/
	int get_size();

	/** \brief verwijdert een eenheid als dit mogelijk is. */
	void delete_unit();

	/** \brief haalt de eenheden lijst leeg */
	void clear_units();

};

