/**
 *\file audio.h
 *
 *\brief deze library bevat de klasse audio
*
* \class audio
*
* \brief Audio files worden ingeladen.
*
* Deze klasse is voor het audio van het spel.
* Voor het achtergrond muziekje wordt de SFML Music gebruikt.
* Voor de rest van de geluidjes wordt de SFML Sounds gebruitk.
* De Music maakt gebruik van een audio stream om geheugen te besparen.
* Verder maken we gebruik van verschillende de SFML SoundBuffer om soundbuffers om meerdere sound aftespelen.
*
* \author Hendrik Cornelisse 
*
* \version 1.0 
*
* \date 2013/11/07
*
*/
#include <SFML/Audio.hpp> 
#include <iostream>

#pragma once


class audio {
private:
	sf::Music music;
	sf::SoundBuffer buffer;
	sf::SoundBuffer buffer_spawn;
	sf::SoundBuffer buffer_up;
	sf::Sound sound;
	sf::Sound sound_spawn;
	sf::Sound sound_up;
	
public:
	///Constuctor wordt aangeroepen
	audio();
	
	/// Vernietigt het opject
	~audio();

	/** \brief Streamen achterground muziekje
	  *
	  * In Deze functie staat het adres van de het achergrond muziekje "Glorious_morning". 
	  * Veder staat er een beveiliging in voor als het muziekje in de map sounds ontbreekt.
	  * Als het muziekje er niet in staat wordt er weergegeven dat het muziekje ontbreekt.
	  * Het laatste wat er gebeurt is dat het muziekje gestart wordt.
	  * \return void.
	  */
	void play_background_music();

	/** \brief Het laden van het geluiden van het spawnen van een swordman.
	  *
	  * Het eerste wat deze functie doet is het resetten van de buffer_spawn.
	  * In Deze functie wordt het geluidje "Sword_spawn" in de buffer_spawn geladen.
	  * Veder staat er een beveiliging in voor als het geluidje in de map sounds ontbreekt.
	  * Als het geluidje er niet in staat wordt er weergegeven dat het geluidje ontbreekt
	  * Het laatste wat er gebeurt is dat het geluidje gestart wordt.
	  * \return void.
	  */
	void spawn_swordsman();

	/** \brief het laden van het geluidje van het spawnen van een archer.
	  *
	  * Het eerste wat deze functie doet is het resetten van de buffer_spawn.
	  * In Deze functie wordt het geluidje "Archer_spawn" in de buffer_spawn geladen.
	  * Veder staat er een beveiliging in voor als het geluidje in de map sounds ontbreekt.
	  * Als het geluidje er niet in staat wordt er in de dos box weergegeven dat het geluidje ontbreekt
	  * Het laatste wat er gebeurt is dat het geluidje gestart wordt.
	  * \return void.
	  */
	void spawn_archer();
	
	/** \brief Het laden van het geluidje van het spawnen van een horseman.
	  *
	  * Het eerste wat deze functie doet is het resetten van de buffer_spawn.
	  * In Deze functie wordt het geluidje "Horse_spawn" in de buffer_spawn geladen.
	  * Veder staat er een beveiliging in voor als het geluidje in de map sounds ontbreekt.
	  * Als het geluidje er niet in staat wordt er in de dos box weergegeven dat het geluidje ontbreekt
	  * Het laatste wat er gebeurt is dat het geluidje gestart wordt.
	  * \return void.
	  */
	void spawn_horseman();

	/** \brief Het laden van het geluidje wanneer een unit dood gaat.
	  *
	  * Het eerste wat deze functie doet is het resetten van de buffer.
	  * In Deze functie wordt het geluidje "Unit_down" in de buffer geladen.
	  * Veder staat er een beveiliging in voor als het geluidje in de map sounds ontbreekt.
	  * Als het geluidje er niet in staat wordt er in de dos box weergegeven dat het geluidje ontbreekt
	  * Het laatste wat er gebeurt is dat het geluidje gestart wordt.
	  * \return void.
	  */
	void unit_down();
	
	/** \brief Het laden van het geluidje van de lumber wordt geupdate.
	  *
	  * Het eerste wat deze functie doet is het resetten van de buffer_up.
	  * In Deze functie wordt het geluidje "Axe" in de buffer_up geladen.
	  * Veder staat er een beveiliging in voor als het geluidje in de map sounds ontbreekt.
	  * Als het geluidje er niet in staat wordt er in de dos box weergegeven dat het geluidje ontbreekt
	  * Het laatste wat er gebeurt is dat het geluidje gestart wordt.
	  * \return void.
	  */
	void lumber_up();

	/** \brief Het laden van het geluidje wanneer de farm wordt geupdate.
	  *
	  * Het eerste wat deze functie doet is het resetten van de buffer_up.
	  * In Deze functie wordt het geluidje "Scythe" in de buffer_up geladen.
	  * Veder staat er een beveiliging in voor als het geluidje in de map sounds ontbreekt.
	  * Als het geluidje er niet in staat wordt er in de dos box weergegeven dat het geluidje ontbreekt
	  * Het laatste wat er gebeurt is dat het geluidje gestart wordt.
	  * \return void.
	  */
	void farm_up();

	/** \brief Het laden van het geluidje wanneer de mine wordt geupdate.
	  *
	  * Het eerste wat deze functie doet is het resetten van de buffer_up.
	  * In Deze functie wordt het geluidje "Pickaxe" in de buffer_up geladen.
	  * Veder staat er een beveiliging in voor als het geluidje in de map sounds ontbreekt.
	  * Als het geluidje er niet in staat wordt er in de dos box weergegeven dat het geluidje ontbreekt
	  * Het laatste wat er gebeurt is dat het geluidje gestart wordt.
	  * \return void.
	  */
	void mine_up();
	
	/** \brief Het laden van het geluidje wanneer het kasteel aangevallen wordt.
	  *
	  *Het eerste wat deze functie doet is het resetten van de buffer.
	  * In Deze functie wordt het geluidje "We_are_under_attack" in de buffer geladen.
	  * Veder staat er een beveiliging in voor als het geluidje in de map sounds ontbreekt.
	  * Als het geluidje er niet in staat wordt er in de dos box weergegeven dat het geluidje ontbreekt
	  * Het laatste wat er gebeurt is dat het geluidje gestart wordt.
	  * \return void.
	  */
	void we_are_under_attack();

	///Het achterground muziekje wordt gestopt.
	///return void.
	void stop_music() {
		music.stop();
	}
};