#include "market.h"
market::market(farm * farm2, lumber_camp * lumber2, mining_camp * mine2):farm1(farm2),lumber1(lumber2),mine1(mine2){
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
		food += farm1->get_production();
		wood += lumber1->get_production();
		stone += mine1->get_stone_production();
		gold += mine1->get_gold_production();

		clock.restart();
		std::cout << "\n food:" << food <<"\n wood:" << wood << "\n stone:" << stone << "\n gold:" << gold << "\n";
	}
}