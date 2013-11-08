/**
 *\file Animation.h
 *
 *\brief deze library bevat de klasse Animation
 *
 * \class Animation
 *
 *
 * \brief deze klasse behandeld de animaties voor het menu 
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
#include <string>


class Animation {

public:
	///dit is de defeault contsturctor van animation die alle variablen op de defeault waarde zet en een object aanmaakt
	Animation();
	///de destructor van animation die het object verwijderd
	~Animation();

	/**laad alle content voor de animatie
	*\param text is de text waarvoor de animatie moet worden uitgevoerd
	*\param image is het plaatje waarvoor de animatie moet worden uitgevoerd
	*\param position is de positie waar de animatie word uitgevoerd
	*\return void
	*/
	virtual void LoadContent(std::string text, sf::Texture image, sf::Vector2f position);
	
	/**verwijderd alle content voor animation uit het geheugen
	*\return void
	*/
	virtual void UnloadContent();

	/**update de content voor de animation
	*\param Window is het window waar de update naartoe geschreven moet worden
	*\return void
	*/
	virtual void Update(sf::RenderWindow &Window);

	/**teken alle de content op het scherm die gebruikt word voor de animatie
	*\param Window is het window waar de draw geschreven moet worden
	*\return void
	*/
	virtual void Draw(sf::RenderWindow &Window);

	/**zet de alpha
	*\param value is de niewe waarde voor alpha
	*\return void
	*/
	virtual void SetAlpha(float value);
	
	/**geeft de alpha terug
	*\return alpha
	*/
	float GetAlpha();

	/**set the animation active
	*\param value value is the nieuwe waarde van active
	*\return void
	*/
	void SetActive(bool value);
	

protected:
	
	float alpha;
	
	std::string preText;
	
	sf::Text text;
	
	sf::Texture image;
	
	sf::Sprite sprite;
	
	sf::Vector2f position;
	
	sf::Color textColor;
	
	
	
	
	bool active;

};

