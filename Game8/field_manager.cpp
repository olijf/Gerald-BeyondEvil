#include "field_manager.h"

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

	for (itUnit=p.begin(); itUnit!=p.end();priorUnit = itUnit, ++itUnit) {
		if ((*p.begin())!=(*itUnit))
			if(calculate_distance((*(priorUnit)),(*itUnit)) < 40){
				if((*itUnit)->get_range() > 15 && m.p.size()> 0 && priorUnit==p.begin() && calculate_distance((*p.begin()),(*m.p.begin())) < 40){
					(*itUnit)->draw(Window, dir, false, true);
					(*(m.p.begin()))->health_down((*itUnit)->get_damage()*0.04);
				}
				else
					(*itUnit)->draw(Window, dir, false, false);
			}
			else
				(*itUnit)->draw(Window, dir, true, false);
		else
			if (p.size() >0 && m.p.size() > 0 && calculate_distance((*p.begin()),(*m.p.begin())) < 40){		
				(*itUnit)->draw(Window, dir, false, true);
				(*itUnit)->health_down((*m.p.begin())->get_damage()*0.04);
			}
			else
				if ((*itUnit)->get_x() < 225 && dir == 1){
					(*itUnit)->draw(Window, dir, false, true);
					stat.health_down_player((*itUnit)->get_damage()*0.04);
				}else if((*itUnit)->get_x() > 990 && dir == 0){					
					(*itUnit)->draw(Window, dir, false, true);
					stat.health_down_enemy((*itUnit)->get_damage()*0.04);
				}
				else
					(*itUnit)->draw(Window, dir, true, false);
	}
	if(p.size() > 0 && !((*p.begin())->get_health()>0)){
		std::cout<<"unit dood";			
		delete_unit();
	}
}

float field_manager::calculate_distance(unit * &obj1, unit * &obj2){
	if(obj1->get_x() - obj2->get_x() < -1.0)
		return obj2->get_x() - obj1->get_x();	
	return obj1->get_x() - obj2->get_x();
}

int field_manager::get_size() {
	return p.size();
}

void field_manager::delete_unit() {
	if (p.size() > 0) {
		delete (*(p.begin()));
		p.erase(p.begin());
	}
}