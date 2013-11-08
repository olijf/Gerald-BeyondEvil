/**
 *\file resources.h
 *
 *\brief deze library bevat de klasse resources
*
 * \class resources
 * \brief Deze houdt het aantal resources bij van alle gebouwen
 *
 * Deze klasse haalt van een resource object zijn grondstoffen 
 * en verhoogt die met de productie maal de factor. Ook reset 
 * hij zijn clock en de grondstoffen van de resources.
 *
 * \author Peter Markotic
 *
 * \version 1.0 
 *
 * \date 2013/11/07
 */

#pragma once
class resources {
	
public:
	int food, wood, stone, gold;
	
	/// Maakt het object aan
	resources();

	/// Vernietigt een object
	~resources();
	
	/** \brief Geeft de waarde van food terug.
	  * @return food
	  */
	int get_food(){
		return food;
	}

	/** \brief Geeft de waarde van wood terug.
	  * @return wood
	  */
	int get_wood(){
		return wood;
	}

	/** \brief Geeft de waarde van stone terug.
	  * @return stone
	  */
	int get_stone(){
		return stone;
	}

	/** \brief Geeft de waarde van gold terug.
	  * @return gold
	  */
	int get_gold(){
		return gold;
	}

	/** \brief Vermindert food met amount. 
	  * \param amount Aantal waarmee het vermidert moet worden.
	  * \return void
	  */
	void decrease_food(const int amount){
		food -= amount;
	}

	/** \brief Vermindert wood met amount. 
	  * \param amount Aantal waarmee het vermidert moet worden.
	  * \return void
	  */
	void decrease_wood(const int amount){
		wood -= amount;
	}

	/** \brief Vermindert stone met amount. 
	  * \param amount Aantal waarmee het vermidert moet worden.
	  * \return void
	  */
	void decrease_stone(const int amount){
		stone -= amount;
	}

	/** \brief Vermindert gold met amount. 
	  * \param amount Aantal waarmee het vermidert moet worden.
	  * \return void
	  */
	void decrease_gold(const int amount){
		gold -= amount;
	}

	/** \brief Zet alle resources op 0.
	  * \return void
	  */
	void reset_resources();
};