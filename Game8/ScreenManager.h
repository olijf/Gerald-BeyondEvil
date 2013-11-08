/**
 *\file ScreenManager.h
 *
 *\brief deze library bevat de klasse ScreenManager
 *
 * \class ScreenManager
 *
 *
 * \brief deze klasse regelt het scherm dat word getoont
 *
 * \author Matthijs Uit den Bogaard 
 *
 * \version 1.0 
 *
 * \date 2013/11/7 16:30:20 
 *
 */
#pragma once

#include <string>
#include <iostream>
#include "maingamescreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include "FadeAnimation.h"

#define ScreenWidth 1280
#define ScreenHeight 720

class ScreenManager {
public:
	/** zet inMenu zodat het progamma uit het menu kan komen
	*\param x is de nieuwe waarde van inMenu
	*\return void
	*/
	void setInMenu(bool x){
		inMenu=x;
	}
	/**returned de waarde van inMenu
	*\return bool
	*/
	bool getInMenu(){return inMenu;}
	
	///destructor van de ScreenManger
	~ScreenManager();

	/**returend welk scherm er word weergegeven
	*return ScreenManager
	*/
	static ScreenManager &GetInstance();

	/**Initializeerd het menu zodat het SplashScreen getoont word.
	*\return void
	*/
	void Initialize();

	/**laad alle content voor de ScreenManager
	*\return void
	*/
	void LoadContent();

	/**verwijderd alle content voor de ScreenManager uit het geheugen
	*\return void
	*/
	void UnloadContent();

	/**update de content voor het ScreenManager
	*\param Window is het window waar de update naartoe geschreven moet worden
	*\param Event is het event waar de input vandaan komt
	*\return void
	*/
	void Update(sf::RenderWindow &Window, sf::Event event);

	//!draw the current screen on window
	void Draw(sf::RenderWindow &Window);

	/**plaats een nieuw scherm op het scherm
	*\param screen is het TitleScreen of SplashScreen dat moet worden afgedrukt op het scherm
	*\return void
	*/
	void AddScreen(maingamescreen *screen);

	/**geeft de alpha terug
	*\return alpha
	*/	
	float GetAlpha();

private:
	
	bool inMenu;
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);
	bool wStartAnimation;
	void Transition(sf::RenderWindow &Window);
	bool transition;
	
	FadeAnimation fade;
	maingamescreen *newScreen;

};

