#include "ai.h"

ai::ai() {
	spawn = true;
}

ai::~ai() {
}

void ai::test(field_manager &player_manager, field_manager &enemy_manager) {
	if (spawn) {
		spawn = false;
		if (global_clock.getElapsedTime().asSeconds() < 120) {
			spawn_time = random_int(10, 15);
			unit_type = random_int(1, 2);
		}
		else if (global_clock.getElapsedTime().asSeconds() < 180) {
			spawn_time = random_int(10, 15);
			unit_type = random_int(1, 3);
		}
		else {
			spawn_time = random_int(5, 10);
			unit_type = random_int(1, 3);
		}
	}
	if (unit_clock.getElapsedTime().asSeconds() > spawn_time && enemy_manager.get_size() < 16) {
		enemy_manager.new_unit(unit_type, true);
		unit_clock.restart();
		spawn = true;
	}
}

int ai::random_int(int begin, int max) {
	srand(time(NULL));
	int temp = (rand() % max + begin);
	std::cout << temp << std::endl;
	return temp;
}

void ai::reset_ai() {
	global_clock.restart();
	unit_clock.restart();
}