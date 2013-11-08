#include <SFML/Graphics.hpp>
#include <time.h>
#include "field_manager.h"

#pragma once
/**
 *\file ai.h
 *
 *\brief deze library bevat de klasse ai
*
 * \class ai
 *
 * \brief De ai bepaald wanneer de computer bepaalde eenheden op het scherm tekend
 *
 * \author Ben Meulenberg
 *
 * \version 1.0
 *
 * \date 2013/11/07
 */

class ai {

private:

sf::Clock global_clock, unit_clock;
bool spawn;
int spawn_time, unit_type;

public:

/** \brief maakt een ai object aan */
ai();
~ai();

/**\brief bepaald welke eenheid er wordt toegevoegd 
* \param &player_manager de field_manager van de speler
* \param &enemy_manager de field_manager van de vijand
*
* Deze functie spawnd de eerste 2 minuten van het spel om de 10 a 15 seconden alleen maar swordsman of archer objecten. \n
* Daarna maakt hij om de 10 a 15 seconden ook horseman objecten aan.\n
* Na 180 seconden voegt hij om de 5 a 10 seconden swordsman, archer of horseman objecten
* aan de enemy_manager toe
*/
void test(field_manager &player_manager, field_manager &enemy_manager);

/**\brief geeft een willekeurig getal
* \param begin laagste waarde om te tekenen
* \param max bepaald de maximale waarde
* \return int met het willekeurige getal
*/
int random_int(int begin, int max);

/**\brief hersteld de klok van ai
*/
void reset_ai();

};