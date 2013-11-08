/**
 *\file farm.h
 *
 *\brief deze library bevat de klasse farm
*
 * \class farm
 *
 * \brief de farm zorgt voor de hud van de farm en de productie en level van de farm.
 *
 * farm zorgt er voor als je met de muis er opklitk dat de venster opent.
 * Dat als je op de button upgrade drukt dat er gecontroleerd wordt dat er genoeg resources zijn.
 * Als er genoeg resouces zijn dat de resouces dan een level omhoog gaat, dus extra grondstoffen geproduceert wordt.
 * Het plaat je van de resources verandert als farm geupgrade wordt.
 * De muis is standaard rood als je je muis op het plaatje houd en wordt groen als er genoeg grondstoffen zijn om hem te upgrade.
 *
 *
 * \author Peter Markotic
 * \author Benjamin Meulenberg
 * \author Hendrik Cornelisse
 *
 * \version 1.0
 *
 * \date 2013/11/07
 *
 */

#include <SFML/Graphics.hpp>
#include <iostream>

#include "mouse.h"
#include "hud.h"
#include "text.h"
#include "resources.h"
#include "audio.h"

#include "tutorial.h"

#pragma once

class farm {

private:

bool active, hover;
int food_upgrade, production; 
float factor;
audio audio4;

sf::Texture farmTexture, food_buttons;
sf::Sprite farmImage, foodImage;
text upgrade_cost, upgrade_info;
resources * resources1;

tutorial * the_tutorial;

public:

/** \brief Constructor van de market.
  * \param resources2 Pointer naar de oorspronklijke resources.
  * \param player_tutorial Wijst naar de tutorial.
  */
farm(resources * resources2, tutorial * player_tutorial);

/// Vernietigt het opject
~farm();

/** \brief Controleert of de muis op het farm is en controleert of de hud voor het farm getekent moet worden.
  * \param Event Het event waaruit de muis interactie word gehaalt.
  * \param &window Het window waarop het farm staat.
  * \param &player_mouse Veranderd het uiterlijk van de muis.
  * \return void
  */
void test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse);

/** \brief Tekent de hud als deze actief is voor lumber_camp en tekent de tutorial als deze actief is.
  * \param &window Het window waarop het lumber_camp staat.
  * \param &player_hud De hud waar de knoppen moeten worden afgebeeld.
  * \return void
  */
void draw(sf::RenderWindow &Window, hud &player_hud);

/** \brief Geeft de waarde van de productie terug.
  * @return production * factor;
  */
int get_production();

/** \brief Geeft de waarde van de factor terug.
  * @return factor
  */
int get_factor();

/** \brief Reset de waardes van de farm.
  * \return void.
  */
void reset_farm();

/** \brief Zorgt voor het schermpje voor de farm opgrade.
  * \param b.
  * \return void.
  */
void set_active(bool b);
};





