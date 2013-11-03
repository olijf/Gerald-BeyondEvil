#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "swordsman.h"
#include "archer.h"
#include "horseman.h"

#pragma once

typedef std::vector<unit*> unitlist;

class field_manager {

private:

	unitlist p;
	unit* s;

public:
	field_manager();
	~field_manager();

	void new_unit(int type, bool enemy);

	void draw(sf::RenderWindow &Window, int dir, field_manager &m);

	void delete_unit();

};

