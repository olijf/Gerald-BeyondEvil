#include "status.h"
#include <iostream>

status::status(){
	health_player = 10000;
	health_enemy = 10000;
}
status::~status(){}

void status::health_down_enemy(int amount){
	if(health_enemy > 0)
	health_enemy -= amount;	
	//std::cout<<"health ènemy:"<<health_enemy;
}
void status::health_down_player(int amount){
	if(health_player > 0)
	health_player -= amount;
	time = clock.getElapsedTime();
	if (time.asSeconds() >= 5){
		audio3.we_are_under_attack();
		clock.restart();
	}
	//std::cout<<"health player:"<<health_player;
}
int status::get_health_enemy(){
	return health_enemy;
}
int status::get_health_player(){
	return health_player;
}