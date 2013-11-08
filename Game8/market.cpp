#include "market.h"

market::market(farm * farm2, lumber_camp * lumber2, mining_camp * mine2, resources * resources2):farm1(farm2),lumber1(lumber2),mine1(mine2),resources1(resources2){
	food_text.set_position(38, 7);
	wood_text.set_position(120, 7);
	stone_text.set_position(204, 7);
	gold_text.set_position(294, 7);

	food_text.set_color(sf::Color::White);
	wood_text.set_color(sf::Color::White);
	stone_text.set_color(sf::Color::White);
	gold_text.set_color(sf::Color::White);
}

market::~market(){
}

void market::update(){
	time = clock.getElapsedTime();
	if (time.asMilliseconds() >= 10){
		if(time.asSeconds() >= 2){
			resources1->food += farm1->get_production();
			resources1->wood += lumber1->get_production();
			resources1->stone += mine1->get_stone_production();
			resources1->gold += mine1->get_gold_production();
			clock.restart();
		}

		convert << resources1->food;
		food_text.text1.setString(convert.str());
		convert.str("");
		convert.clear();

		convert << resources1->wood;
		wood_text.text1.setString(convert.str());
		convert.str("");
		convert.clear();

		convert << resources1->stone;
		stone_text.text1.setString(convert.str());
		convert.str("");
		convert.clear();

		convert << resources1->gold;
		gold_text.text1.setString(convert.str());
		convert.str("");
		convert.clear();

	}
}

void market::draw(sf::RenderWindow &Window) {
	Window.draw(food_text.text1);
	Window.draw(wood_text.text1);
	Window.draw(stone_text.text1);
	Window.draw(gold_text.text1);
}

void market::reset_market() {
	clock.restart();
	farm1->reset_farm();
	lumber1->reset_lumber();
	mine1->reset_mining();
}