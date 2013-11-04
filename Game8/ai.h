#include <SFML/Graphics.hpp>
#include <time.h>
#include "field_manager.h"

#pragma once

class ai {

private:

sf::Clock clock;
bool spawn;
int temp;

public:

ai();
~ai();

void test(field_manager &player_manager, field_manager &enemy_manager);
int random_int(int begin, int max);

};