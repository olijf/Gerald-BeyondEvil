/**
 *\file SplashScreen.h
 *
 *\brief deze library bevat de klasse SplashScreen
 *
 * \class SplashScreen
 *
 *
 * \brief deze klasse laad het splashscreen zien
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
#include "TitleScreen.h"


class SplashScreen : public maingamescreen {

public:
	///dit is de defeault contsturctor van SplashScreen die alle variablen op de defeault waarde zet en een object aanmaakt
	SplashScreen();
	///dit is de destructor die het object verwijderd
	~SplashScreen();
	
	/**laad alle content voor het SplashScreen
	*\return void
	*/
	void LoadContent();
	
	/**verwijderd alle content voor het SplashScreen uit het geheugen
	*\return void
	*/
	void UnloadContent();
	
	/**update de content voor het SplashScreen
	*\param Window is het window waar de update naartoe geschreven moet worden
	*\param Event is het event waar de input vandaan komt
	*\return void
	*/
	void Update(sf::RenderWindow &Window, sf::Event event);
	
	/**teken alle de content op het scherm die gebruikt word door de SplashScreen
	*\param Window is het window waar de draw geschreven moet worden
	*\return void
	*/
	void Draw(sf::RenderWindow &Window);

private:
	sf::Texture texture;
	sf::Sprite sprite;
};

