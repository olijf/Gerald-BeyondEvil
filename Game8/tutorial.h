/**
 * \file tutorial.h
 *
 * \brief deze library bevat de klasse Tutorial
 *
 * \class tutorial
 *
 * \brief Zorgt voor de tutorial in het spel.
 *
 * Deze klasse is verantwoordelijk voor het regelen van de tutorial. De bedoeling
 * van deze korte tutorial is om de speler simpele uitleg te voorzien tijdens het spel.
 *
 * \author Benjamin Meulenberg
 *
 * \version 1.1b
 *
 * \date 06/11/2013
 *
 */

#include <SFML/Graphics.hpp>
#include <iostream>

#include "mouse.h"
#include "text.h"

#pragma once

class tutorial {

private:

	sf::Texture questionTexture, tutorialTexture;
	sf::Sprite questionImage, tutorialImage;
	sf::RectangleShape focus, text_back;

	text tutorial_text;

	bool tutorial_active, hover;
	int tutorial_step, farm_active, lumber_camp_active, mining_camp_active, castle_active;

	mouse *tutorial_mouse;

public:
	
	/** \brief Initialiseert de benodigheden voor de tutorial.
      * \param *player_mouse Krijgt pointer van de in de main geinitialiseerde muis mee.
	  * 
      * Initialiseert de benodigde afbeeldingen voor de tutorial en zet de variablen op de juiste beginwaarden.
      */
	tutorial(mouse *player_mouse);
	
	~tutorial();
	
	/** \brief Zet de hover staat van de muis aan/uit.
      * \param step Deze waarde bepaald welke naar welke stap de tutorial moet gaan.
      * \return void
	  * 
      * Deze methode maakt het mogelijk om door de stappen van de tutorial te gaan.
      * Hier is er bijvoorbeeld voor gekozen om na het drukken van de spatie toets naar de volgende stap te gaan
      */
	void next_step(int step);
	
	/** \brief Kijkt of de tutorial actief is.
      * \return bool Geeft de waarde van tutorial_active terug 
	  * 
      * Deze methode zorgt voor een controle om te kijken of de tutorial actief is.
      * Als de tutorial actief mag bijvoorbeeld onder bepaalde omstandigheden de farm niet geselecteerd worden.
      */
	bool active();
	
	/** \brief Zet de staat waarin de farm moet fungeren.
      * \return int De integer waarde bepaalt in welke staat de farm gezet moet worden.
	  * 
      * Deze methode maakt het mogelijk om de farm in een bepaalde staat te zetten. Bij een return waarde 1 is de farm klikbaar,
	  * return waarde 2 verplicht de farm om actief te zijn. Bij een iedere andere waarde is de farm altijd niet actief.
      */
	int farm_state();
	
	/** \brief Zet de staat waarin de lumber camp moet fungeren.
      * \return int De integer waarde bepaalt in welke staat de lumber camp gezet moet worden.
	  * 
      * Deze methode maakt het mogelijk om de lumber camp in een bepaalde staat te zetten. Bij een return waarde 1 is de lumber camp klikbaar,
	  * return waarde 2 verplicht de lumber camp om actief te zijn. Bij een iedere andere waarde is de lumber camp altijd niet actief.
      */
	int lumber_camp_state();
	
	/** \brief Zet de staat waarin de mining camp moet fungeren.
      * \return int De integer waarde bepaalt in welke staat de mining camp gezet moet worden.
	  * 
      * Deze methode maakt het mogelijk om de mining camp in een bepaalde staat te zetten. Bij een return waarde 1 is de mining camp klikbaar,
	  * return waarde 2 verplicht de mining camp om actief te zijn. Bij een iedere andere waarde is de mining camp altijd niet actief.
      */
	int mining_camp_state();
	
	/** \brief Zet de staat waarin de castle moet fungeren.
      * \return int De integer waarde bepaalt in welke staat de mining camp gezet moet worden.
	  * 
      * Deze methode maakt het mogelijk om de castle in een bepaalde staat te zetten. Bij een return waarde 1 is de castle klikbaar,
	  * return waarde 2 verplicht de castle om actief te zijn. Bij een iedere andere waarde is de castle altijd niet actief.
      */
	int castle_state();

	/** \brief Zorgt voor het afspelen van de tutorial.
      * \param &Window Krijgt de benodigde window mee waar de onderdelen van de tutorial op getekend worden.
      * \param &Event Krijgt de laatst opgegeven event mee. Kan gebruikt worden om bijvoorbeeld te controleren of de spatie toets is ingedrukt.
      * \return void
	  * 
      * Deze methode zorgt ervoor dat de benogigde afbeeldingen getoond worden. Een voorbeeld hiervan is het vraagteken om de tutorial te starten.
      * Verder handelt het de gegeven events af. Na het drukken van spatie wordt bijvoorbeeld de volgende stap van de tutorial geladen. De events die opgevangen worden zijn de spatie event en mouse event.
      */
	void draw(sf::RenderWindow &Window, sf::Event &Event);

};
