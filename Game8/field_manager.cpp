#include "field_manager.h"

field_manager::field_manager() {
	n = 0;
	timer = 0;
}

field_manager::~field_manager() {
	unitlist::iterator itUnit;
	for (itUnit=p.begin(); itUnit!=p.end(); ++itUnit) {
		delete (*itUnit);
	}
	p.clear();
}

void field_manager::new_unit(int type, bool enemy) {
	n++;
	timer = 0;
	unit* s;

	switch (type) {
	case 1:
		s = new swordsman;
		break;
	case 2:
		s = new archer;
		break;
	case 3:
		s = new horseman;
		break;
	default:
		break;
	}
	
	if(!enemy){
		s->set_x(135);
	}else{
		s->set_x(1100);
	}


	p.insert(p.end(), s);
	
}

void field_manager::draw(sf::RenderWindow &Window, int dir, field_manager &m) {

	if (timer < n && clock.getElapsedTime().asSeconds() > 2) {
		timer++;
		clock.restart();
	}
	
	unitlist::iterator itUnit, priorUnit;
	
	int x_front = 1000;
	if (p.size() > 0 && m.p.size()>0) {
	if(dir>0){
		x_front = (*p.begin())->get_x() - (*(m.p.begin()))->get_x();
	}
	else		
		x_front = (*(m.p.begin()))->get_x() - (*p.begin())->get_x();
	}


	for (itUnit=p.begin(); itUnit!=p.end();priorUnit = itUnit, ++itUnit) {
		if ((*p.begin())!=(*itUnit))
			if((dir == 0 && (*(priorUnit))->get_x() - (*itUnit)->get_x() < 32) || (dir == 1 && (*itUnit)->get_x() - (*(priorUnit))->get_x() < 32))
				(*itUnit)->draw(Window, dir, false, false);
			else
				(*itUnit)->draw(Window, dir, true, false);
		else
			if (x_front < 32)		
				(*itUnit)->draw(Window, dir, false, true);
			else
				if ((*itUnit)->get_x() < 135 || (*itUnit)->get_x() > 1100)
					(*itUnit)->draw(Window, dir, false, true);
					//	delete_unit();
				else
					(*itUnit)->draw(Window, dir, true, false);
	}
}

void field_manager::delete_unit() {
	if (p.size() > 0) {
		delete (*(p.begin()));
		p.erase(p.begin());
	}
}