/**
 *\file castle.h
 *
 *\brief deze library bevat de klasse castle
*
 * \class castle
 *
 * \brief Toont het kasteel op het scherm en handelt 
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

#include "mouse.h"
#include "hud.h"
#include "text.h"
#include "field_manager.h"
#include "resources.h"
#include "audio.h"
#include "tutorial.h"

#pragma once

class castle {

private:

bool active, hover, spawn;

sf::Texture castleTexture, player_buttons;
sf::Sprite castleImage, swordsmanImage, archerImage, horsemanImage;
text upgrade_cost, upgrade_info;

resources * resources1;
audio audio1;

tutorial * the_tutorial;

public:

/** \brief Constructor van de castle.
  * \param Resources2 poiner naar de oorspronkelijk resources.
  * \param Player_turorial wijst naar de tutorial.
  */
castle(resources * resources2, tutorial * player_tutorial);

/// Vernietig het opject.
~castle();

/** \brief Controleert of de muis op het lumber_camp is en controleert of de hud voor het lumber_camp getekent moet worden.
  * \param Event Het event waaruit de muis interactie word gehaalt.
  * \param &window Het window waarop het lumber_camp staat.
  * \param &player_mouse Veranderd het uiterlijk van de muis.
  * \param &player_manager Voor het aanmaken van nieuwe units.
  * \retrun Void.
  */
void test(sf::Event &Event, sf::RenderWindow &Window, mouse &player_mouse, field_manager &player_manager);

/** \brief ekent De hud als deze actief is voor lumber_camp en tekent de tutorial als deze actief is
  * \param &window Het window waarop het lumber_camp staat
  * \param &player_hud De hud waar de knoppen moeten worden afgebeeld
  * \retunr void
  */
void draw(sf::RenderWindow &Window, hud &player_hud);

/** \brief zorgt voor het schermpje voor de castle upgrade.
  * \param b.
  * \return void.
  */
void set_active(bool b);

};
