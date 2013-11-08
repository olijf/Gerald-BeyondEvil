/**
 *\file FadeAnimation.h
 *
 *\brief deze library bevat de klasse FadeAnimation
 *
 * \class FadeAnimation
 *
 *
 * \brief deze klasse behandeld de fade animaties voor het menu 
 *
 * \author Matthijs Uit den Bogaard 
 *
 * \version 1.0 
 *
 * \date 2013/11/7 16:30:20 
 *
 */
#pragma once

#include "Animation.h"

class FadeAnimation : public Animation {

public:
	///dit is de defeault contsturctor van FadeAnimation die alle variablen op de defeault waarde zet en een object aanmaakt
	FadeAnimation();
	///dit is de destructor die het object verwijderd
	~FadeAnimation();

	/**laad alle content voor de FadeAnimation
	*\param text is de text waarvoor de fade animatie moet worden uitgevoerd
	*\param image is het plaatje waarvoor de fade animatie moet worden uitgevoerd
	*\param position is de positie waar de fade animatie word uitgevoerd
	*\return void
	*/
	void LoadContent(std::string text, sf::Texture image, sf::Vector2f position);
	/**verwijderd alle content voor fade animation uit het geheugen
	*\return void
	*/
	void UnloadConent();
	
	/**update de content voor de FadeAnimation
	*\param Window is het window waar de update naartoe geschreven moet worden
	*\return void
	*/
	void Update(sf::RenderWindow &Window);
	/**teken alle de content op het scherm die gebruikt word voor de FadeAnimation
	*\param Window is het window waar de draw geschreven moet worden
	*\return void
	*/
	void Draw(sf::RenderWindow &Window);
	/**zet de alpha
	*\param value is de niewe waarde voor alpha
	*\return void
	*/
	void SetAlpha(float value);

private:
	bool increase;
	float fadeSpeed;

};

