#include "farm.h"
#include "lumber_camp.h"
#include "mining_camp.h"
#pragma once
class market{
private:
sf::Clock clock;
sf::Time time;

int food, wood, stone, gold;

farm * farm1;
lumber_camp * lumber1;
mining_camp * mine1;
protected:

public:

market(farm * farm2, lumber_camp * lumber2, mining_camp * mine2);
~market();
void update();

int get_food(){
	return food;
}
int get_wood(){
	return wood;
}
int get_stone(){
	return stone;
}
int get_gold(){
	return gold;
}
void decrease_food(const int amount){
	food -= amount;
}
void decrease_wood(const int amount){
	wood -= amount;
}
void decrease_stone(const int amount){
	stone -= amount;
}
void decrease_gold(const int amount){
	gold -= amount;
}


};