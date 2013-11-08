#include "resources.h"

resources::resources(){
	food = 0;
	wood = 0;
	stone = 0;
	gold = 0;
}

resources::~resources() {
}

void resources::reset_resources() {
	food = 0;
	wood = 0;
	stone = 0;
	gold = 0;
}