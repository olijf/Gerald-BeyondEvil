#include "status.h"
#include <iostream>

status::status(){
	health_player = 100000;
	health_enemy = 100000;
}
status::~status(){}

void status::health_down_enemy(int amount){
	health_enemy -= amount;	
	//std::cout<<"health ènemy:"<<health_enemy;
}
void status::health_down_player(int amount){
	health_player -= amount;
	//std::cout<<"health player:"<<health_player;
}
int status::get_health_enemy(){
	return health_enemy;
}
int status::get_health_player(){
	return health_player;
}