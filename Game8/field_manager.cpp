#include "field_manager.h"

field_manager::field_manager() {
}

field_manager::~field_manager() {
	unitlist::iterator itUnit;
	for (itUnit=p.begin(); itUnit!=p.end(); ++itUnit) {
		delete (*itUnit);
	}
	p.clear();
}

void field_manager::new_unit(int type, bool enemy) {

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
			if((dir == 0 && (*(priorUnit))->get_x() - (*itUnit)->get_x() < 40) || (dir == 1 && (*itUnit)->get_x() - (*(priorUnit))->get_x() < 40)){
				if((*itUnit)->get_range()>15 && m.p.size()>0 && priorUnit==p.begin() && x_front < 40){
					(*itUnit)->draw(Window, dir, false, true);
					(*(m.p.begin()))->health_down((*itUnit)->get_damage()*0.04);
				}
				else
					(*itUnit)->draw(Window, dir, false, false);
			}
			else
				(*itUnit)->draw(Window, dir, true, false);
		else
			if (x_front < 40){		
				(*itUnit)->draw(Window, dir, false, true);
				(*itUnit)->health_down((*m.p.begin())->get_damage()*0.04);
			}
			else
				if ((*itUnit)->get_x() < 135 || (*itUnit)->get_x() > 1100)
					(*itUnit)->draw(Window, dir, false, true);
		//	delete_unit();
				else
					(*itUnit)->draw(Window, dir, true, false);
	}
	if(p.size() > 0 && ((*p.begin())->get_health()<1)){
		std::cout<<"unit dood";			
		delete_unit();
	}
}

void field_manager::delete_unit() {
	if (p.size() > 0) {
		delete (*(p.begin()));
		p.erase(p.begin());
	}
}