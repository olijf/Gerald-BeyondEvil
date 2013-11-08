/**
 *\file market.h
 *
 *\brief deze library bevat de klasse market
*
 * \class market
 * \brief Deze klasse telt bij elke update, de productie keer de factor, op bij de resources
 *
 * Deze klasse haalt van een resource object zijn grondstoffen en verhoogt die met de
 * productie maal de factor. Ook reset hij zijn clock en de grondstoffen van de resources.
 *
 *
 * \author Peter Markotic
 *
 * \version 1.0 
 *
 * \date 2013/11/07
 */

#include <sstream>

#include "farm.h"
#include "lumber_camp.h"
#include "mining_camp.h"
#include "resources.h"

#include "text.h"

#pragma once

class market {

private:

	sf::Clock clock;
	sf::Time time;

	text food_text, wood_text, stone_text, gold_text;
	std::ostringstream convert; 

	farm * farm1;
	lumber_camp * lumber1;
	mining_camp * mine1;
	resources * resources1;

public:

/** \brief Maakt het object aan
  * \param farm2 vraagt de food_production op.
  * \param lumber2 vraagt wood_production op.
  * \param mine2 vraagt de stone_production en de gold_production op.
  * \param resource2 vraagt de resources op.
  */
market(farm * farm2, lumber_camp * lumber2, mining_camp * mine2, resources * resource2);

/// Vernietigt het object.
~market();

/** \brief Update de market.
  * \return void
  * 
  * Deze methode vraagt van elke resource zijn hoeveelheid op
  * dan vraagt hij de productie op en vermedigvuldigt dit met de factor
  * daarna telt hij het bij de resource op voor zijn nieuwe aantal.
  * Ook converteert hij de resources naar strings en zet deze in de text objecten
  */
void update();

/** \brief Tekent de text op het meegegeven window.
  * \param &Window Het window waar op getekent wordt.
  * \return void
  */
void draw(sf::RenderWindow &Window);

/** \brief Zet alle producties en de clock weer op de beginwaarden.
  * \return void
  */
void reset_market();
};