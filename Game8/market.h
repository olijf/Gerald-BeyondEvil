#include <stdlib.h>
#include <sstream>

#include "farm.h"
#include "lumber_camp.h"
#include "mining_camp.h"
#include "resources.h"

#include "text.h"

#pragma once
class market{
private:
sf::Clock clock;
sf::Time time;

int food, wood, stone, gold;

std::string food_string, wood_string, stone_string, gold_string;
text food_text, wood_text, stone_text, gold_text;
std::ostringstream convert;

farm * farm1;
lumber_camp * lumber1;
mining_camp * mine1;
resources * resources1;

public:

market(farm * farm2, lumber_camp * lumber2, mining_camp * mine2, resources * resource2);
~market();
void update();

void draw(sf::RenderWindow &Window, hud &player_hud);

};