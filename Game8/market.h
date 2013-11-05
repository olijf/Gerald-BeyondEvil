#include "farm.h"
#include "lumber_camp.h"
#include "mining_camp.h"
#include "resources.h"
#pragma once
class market{
private:
sf::Clock clock;
sf::Time time;

int food, wood, stone, gold;

farm * farm1;
lumber_camp * lumber1;
mining_camp * mine1;
resources * resources1;
protected:

public:

market(farm * farm2, lumber_camp * lumber2, mining_camp * mine2, resources * resource2);
~market();
void update();

};