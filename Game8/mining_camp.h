/**
 *\file mining_camp.h
 *
 *\brief deze library bevat de klasse mining_camp
*
 * \class mining_camp
 *
 *
 * \brief deze klasse regelt de hud en het productie en level van de mining_camp
 *
 * Mining_camp zorgt er voor als je met de muis er opklitk dat de venster opent.
 * Dat als je op de button upgrade drukt dat er gecontroleerd wordt dat er genoeg resources zijn.
 * Als er genoeg resouces zijn dat de resouces dan een level omhoog gaat, dus extra grondstoffen geproduceert wordt.
 * Het plaat je van de resources verandert als minging_camp geupgrade wordt.
 * De muis is standaard rood als je je muis op het plaatje houd en wordt groen als er genoeg grondstoffen zijn om hem te upgrade.
 *
 * \author Peter Markotic
 * \author Benjamin Meulenberg
 * \author Hendrik Cornelisse
 *
 * \version 1.0 
 *
 * \date 2013/11/7 16:30:20 
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

class mining_camp {

private:

bool active, hover;
int stone_upgrade, gold_upgrade, stone_production, gold_production;
float stone_factor, gold_factor;

sf::Texture mining_campTexture, stone_buttons, gold_buttons;
sf::Sprite mining_campImage, stoneImage, goldImage;
text upgrade_cost, upgrade_info;
resources * resources1;
audio audio4;

tutorial * the_tutorial;

public:

/** \brief Maakt een object voor mining_camp.
  * \param resources2 Is het geheugen adres van de recourses.
  * \param player_tutorial Wijst naar de tutorial.
  */
mining_camp(resources * resources2, tutorial * player_tutorial);

///Verwijderd het mining_camp object.
~mining_camp();

/** \brief Controleert of de muis op het mining camp is en controleert of de hud voor het mining camp getekent moet worden.
  * \param Event Het event waaruit de muis interactie word gehaalt.
  * \param Window Het window waarop de muis interactie plaatsvind.
  * \param player_mouse Veranderd het uiterlijk van de muis.
  * \return void.
  */
void test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse);

/** \brief Tekent de hud als deze actief is voor mining_camp en tekent de tutorial als deze actief is.
  * \param Window Het window waarop het mining camp staat.
  * \param player_hud De hud waar de knoppen moeten worden afgebeeld.
  * \return void.
*/
void draw(sf::RenderWindow &Window, hud &player_hud);

/** \brief Returned de stone productie.
  * \return stone_production * stone_factor
  */
int get_stone_production();

/** \brief Returned de gold productie.
  * \return gold_production * gold_factor
  */
int get_gold_production();

/** \brief Zet het mining level weer op nul en de productie wee default
  * \return void
  */
void reset_mining();

/** \briefzet active true of false
  * \param b is de waarde waar active op gezet word
  */
void set_active(bool b);
};