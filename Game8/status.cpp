#include "status.h"
#include <iostream>

status::status(){
	health_player = 10000;
	health_enemy = 10000;
}
status::~status(){}

void status::health_down_enemy(int amount){
	if((health_enemy - amount)>=0)
		health_enemy -= amount;
	else
		health_enemy = 0;
	
	if(health_enemy < 10)
	std::cout<<"health enemy:"<<health_enemy;
}
void status::health_down_player(int amount){
	if((health_player - amount)>=0)
		health_player -= amount;
	else
		health_player = 0;
	time = clock.getElapsedTime();
	if (time.asSeconds() >= 5){
		audio3.we_are_under_attack();
		clock.restart();
	}
	
	if(health_player < 10)
	std::cout<<"health player:"<<health_player;
}
int status::get_health_enemy(){
	return health_enemy;
}
int status::get_health_player(){
	return health_player;
}

void status::reset_health() {
	health_player = 10000;
	health_enemy = 10000;
}