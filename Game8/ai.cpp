#include "ai.h"

ai::ai() {
	spawn = true;
}

ai::~ai() {
}

void ai::test(field_manager &player_manager, field_manager &enemy_manager) {
	if (spawn) {
		spawn = false;
		temp = random_int(4, 10);
	}
	if (clock.getElapsedTime().asSeconds() > temp && enemy_manager.get_size() < 10) {
		enemy_manager.new_unit(random_int(1, 3), true);
		clock.restart();
		spawn = true;
	}
}

int ai::random_int(int begin, int max) {
	srand(time(NULL));
	int temp = (rand() % max + begin);
	std::cout << temp << std::endl;
	return temp;
}