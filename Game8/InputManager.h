/**
 *\file InputManager.h
 *
 *\brief deze library bevat de klasse InputManager
 *
 * \class InputManager
 *
 *
 * \brief deze klasse behandeld de input voor het menu
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
#include <vector>

class InputManager {

public:
	///dit is de defeault contsturctor van InputManager die alle variablen op de defeault waarde zet en een object aanmaakt
	InputManager();
	///dit is de destructor die het object verwijderd
	~InputManager();

	/**update de content voor de InputManager
	*\param Event is het event waar de input vandaan komt
	*\return void
	*/
	void Update(sf::Event event);

	/**controleerd of een willekeurge knop is ingederukt
	*\return bool
	*/
	bool KeyPressed();

	/**controleerd of een knop is ingederukt
	*\param key is de knop die moet worden ingedrukt
	*\return bool
	*/
	bool KeyPressed(int key);

	/**controleerd of een knop is ingederukt
	*\param keys is een lijst met knopen die ingedrukt mogen worden voor de return true
	*\return bool
	*/
	bool KeyPressed(std::vector<int> keys);

	/**controleerd of een knop is losgelaten
	*\param key is de knop die moet worden losgelaten
	*\return bool
	*/
	bool KeyReleased(int key);

	/**controleerd of een knop is losgelaten
	*\param keys is een lijst met knopen die losgelaten mogen worden voor de return true
	*\return bool
	*/
	bool KeyReleased(std::vector<int> keys);
	/**controleerd of een knop is ingederukt
	*\param Window is het window waarin de knop moet zijn ingedrukt
	*\param keys is een lijst met knopen die ingedrukt mogen worden voor de return true
	*\return bool
	*/
	bool KeyDown(sf::RenderWindow &Window, sf::Keyboard::Key key);
	/**controleerd of een knop is losgelaten
	*\param key is de knop die moet worden losgelaten
	*\param Window is het window waarin de knop moet zijn ingedrukt
	*\return bool
	*/
	bool KeyDown(sf::RenderWindow &Window, std::vector<sf::Keyboard::Key> keys);

private:
	sf::Event event;

};

