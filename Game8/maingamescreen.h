/**
 *\file maingamescreen.h
 *
 *\brief deze library bevat de klasse maingamescreen
 *
 * \class maingamescreen
 *
 *
 * \brief deze klasse is de superklasse voor SplashScreen en TitleScreen
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
#include "Inputmanager.h"

class maingamescreen  {
public:
	///dit is de defeault contsturctor van maingamescreen die alle variablen op de defeault waarde zet en een object aanmaakt
	maingamescreen ();
	///dit is de destructor die het object verwijderd
	~maingamescreen ();

	/**laad alle content voor het maingamescreen
	*\return void
	*/
	virtual void LoadContent();

	/**verwijderd alle content voor het maingamescreen uit het geheugen
	*\return void
	*/
	virtual void UnloadContent();

	/**update de content voor het maingamescreen
	*\param Window is het window waar de update naartoe geschreven moet worden
	*\param Event is het event waar de input vandaan komt
	*\return void
	*/
	virtual void Update(sf::RenderWindow &Window, sf::Event event);

	/**teken alle de content op het scherm die gebruikt word door de maingamescreen
	*\param Window is het window waar de draw geschreven moet worden
	*\return void
	*/
	virtual void Draw(sf::RenderWindow &Window);

protected:
	InputManager input;
	std::vector<int> keys;

};

