#include "audio.h"

#pragma once

class status{
private:
	int health_enemy, health_player;
	audio audio3;
	sf::Time time;
	sf::Clock clock;
public:
	status();
	~status();
	void health_down_enemy(int amount);
	void health_down_player(int amount);
	int get_health_player();
	int get_health_enemy();
};