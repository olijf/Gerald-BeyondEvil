/**
 *\file lumber_camp.h
 *
 *\brief deze library bevat de klasse lumber_camp
*
 * \class lumber_camp
 *
 * \brief de lumber_camp zorgt voor de hud van de lumber_camp en de productie en level van de lumber_camp.
 *
 * Lumber_camp zorgt er voor als je met de muis er opklitk dat de venster opent.
 * Dat als je op de button upgrade drukt dat er gecontroleerd wordt dat er genoeg resources zijn.
 * Als er genoeg resouces zijn dat de resouces dan een level omhoog gaat, dus extra grondstoffen geproduceert wordt.
 * Het plaat je van de resources verandert als lumber_camp geupgrade wordt.
 * De muis is standaard rood als je je muis op het plaatje houd en wordt groen als er genoeg grondstoffen zijn om hem te upgrade.
 *
 * \author Peter Markotic
 * \author Benjamin Meulenberg
 * \author Hendrik Cornelisse
 *
 * \version 1.0
 *
 * \date 2013/11/07
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

class lumber_camp {

private:

bool active, hover;
int wood_upgrade, production;
float factor;

sf::Texture lumber_campTexture, wood_buttons;
sf::Sprite lumber_campImage, woodImage;
text upgrade_cost, upgrade_info;
resources * resources1;
audio audio4;

tutorial * the_tutorial;

public:

/** \brief Constructor van de lumber_camp.
  * \param resources2 Poiner naar de oorspronkelijk resources.
  * \param player_turorial Wijst naar de tutorial.
  */
lumber_camp(resources * resources2, tutorial * player_tutorial);

/// Vernietigt het opject.
~lumber_camp();

/** \brief Controleert of de muis op het lumber_camp is en controleert of de hud voor het lumber_camp getekent moet worden.
  * \param Event Het event waaruit de muis interactie word gehaalt.
  * \param &window Het window waarop het lumber_camp staat.
  * \param &player_mouse Veranderd het uiterlijk van de muis.
  * \returnVoid.
  */
void test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse);

/** \brief Tekent De hud als deze actief is voor lumber_camp en tekent de tutorial als deze actief is.
  * \param &window Het window waarop het lumber_camp staat.
  * \param &player_hud De hud waar de knoppen moeten worden afgebeeld.
  * \return void
  */
void draw(sf::RenderWindow &Window, hud &player_hud);

/** \brief Geeft de waarde van de productie terug.
  * @return production * factor;
  */
int get_production();

/** \brief Geeft de waardes van de factor tergug.
  * @return factor
  */
float get_factor();

/** \brief Reset de waardes van de lumber_camp.
  * \return void.
  */
void reset_lumber();

/** \brief Zorgt voor het schermpje voor de lumber_camp upgrade.
  * \param b.
  * \return void.
  */
void set_active(bool b);
};