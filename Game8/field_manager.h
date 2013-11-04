#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "swordsman.h"
#include "archer.h"
#include "horseman.h"
#include "status.h"

#pragma once

typedef std::vector<unit*> unitlist;

class field_manager {

private:

	unitlist p;
	unit* s;
	status &stat;

public:
	field_manager();
	field_manager(status &blah):stat(blah){}
	~field_manager();

	void new_unit(int type, bool enemy);

	void draw(sf::RenderWindow &Window, int dir, field_manager &m);

	float calculate_distance(unit * &obj1, unit * &obj2);

	int get_size();

	void delete_unit();

};

