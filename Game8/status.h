#pragma once
class status{
private:
	int health_enemy, health_player;
public:
	status();
	~status();
	void health_down_enemy(int amount);
	void health_down_player(int amount);
	int get_health_player();
	int get_health_enemy();
};