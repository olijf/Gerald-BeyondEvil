#include "market.h"
market::market(farm * farm2, lumber_camp * lumber2, mining_camp * mine2, resources * resources2):farm1(farm2),lumber1(lumber2),mine1(mine2),resources1(resources2){
	food = 0;
	wood = 0;
	stone = 0;
	gold = 0;
}
market::~market(){
}

void market::update(){
	time = clock.getElapsedTime();
	if (time.asSeconds() >= 2){
		resources1->food += farm1->get_production();
		resources1->wood += lumber1->get_production();
		resources1->stone += mine1->get_stone_production();
		resources1->gold += mine1->get_gold_production();

		clock.restart();
		std::cout << "\n food:" << resources1->food <<"\n wood:" << resources1->wood << "\n stone:" << resources1->stone << "\n gold:" << resources1->gold << "\n";
	}
}