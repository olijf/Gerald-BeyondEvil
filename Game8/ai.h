#include <SFML/Graphics.hpp>
#include <time.h>
#include "field_manager.h"

#pragma once

class ai {

private:

sf::Clock global_clock, unit_clock;
bool spawn;
int spawn_time, unit_type;

public:

ai();
~ai();

void test(field_manager &player_manager, field_manager &enemy_manager);
int random_int(int begin, int max);

};