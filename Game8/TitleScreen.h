/**
 *\file TitleScreen.h
 *
 *\brief deze library bevat de klasse TitleScreen
 *
 * \class TitleScreen
 *
 *
 * \brief deze klasse laad het TitleScreen zien
 *
 * \author Matthijs Uit den Bogaard 
 *
 * \version 1.0 
 *
 * \date 2013/11/7 16:30:20 
 *
 */
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenManager.h"
#include "maingamescreen.h"
#include "SplashScreen.h"


class TitleScreen : public maingamescreen {
public:
	///dit is de defeault contsturctor van TitleScreen die alle variablen op de defeault waarde zet en een object aanmaakt
	TitleScreen();
	///dit is de destructor die het object verwijderd
	~TitleScreen();
	
	/**laad alle content voor het TitleScreen
	*\return void
	*/
	void LoadContent();
	/**verwijderd alle content voor het TitleScreen uit het geheugen
	*\return void
	*/
	void UnloadContent();
	/**update de content voor het TitleScreen
	*\param Window is het window waar de update naartoe geschreven moet worden
	*\param Event is het event waar de input vandaan komt
	*\return void
	*in de update staan 3 if-statements met x en y cooridinaten die worden vergleken met de muis coordinaten zodat de game kan detecteren op welke menuknop de muis staat of klikt.
	*/
	void Update(sf::RenderWindow &Window, sf::Event event);
	/**teken alle de content op het scherm die gebruikt word door de TitleScreen
	*\param Window is het window waar de draw geschreven moet worden
	*\return void
	*/
	void Draw(sf::RenderWindow &Window);
private:
	
	sf::Texture texture;
	sf::Texture sp;
	sf::Texture lb;
	sf::Texture c;
	sf::Texture e;
	sf::Sprite sprite;
};

