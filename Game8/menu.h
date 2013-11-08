/**
 * 
 * \file menu.h
 *
 * \brief deze library bevat de event loop voor het menu
 *
 * \author Matthijs Uit den Bogaard 
 *
 * \version 1.0 
 *
 * \date 2013/11/7 16:30:20 
 *
 */


/**initialiseert het menu
*\param Window is het window waarvoor het menu word geinitializeerd
*\return void
*/
void initializeMenu(sf::RenderWindow &Window);

/**deze funcite bevat de gameloop voor het menu
*\param Window is het window waarop het menu geprint moet worden
*\return void
*/
void drawMenu(sf::RenderWindow &Window);