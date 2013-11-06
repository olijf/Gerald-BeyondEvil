#include "market.h"
market::market(farm * farm2, lumber_camp * lumber2, mining_camp * mine2, resources * resources2):farm1(farm2),lumber1(lumber2),mine1(mine2),resources1(resources2){
	food_text.set_position(38, 7);
	wood_text.set_position(120, 7);
	stone_text.set_position(204, 7);
	gold_text.set_position(294, 7);
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

void market::draw(sf::RenderWindow &Window, hud &player_hud) {
	Window.draw(food_text.text1);
	Window.draw(wood_text.text1);
	Window.draw(stone_text.text1);
	Window.draw(gold_text.text1);
}