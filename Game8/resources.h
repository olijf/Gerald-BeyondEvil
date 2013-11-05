#pragma once

class resources{
protected:
	
public:
	int food, wood, stone, gold;
	resources();
	~resources();
	
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