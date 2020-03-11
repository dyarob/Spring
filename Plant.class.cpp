#include "Plant.class.hpp"

std::list <Plant>	plantList;

void	plants_init(void) {
Plant pinkherb, violet, redshroom, fabulis;
pinkherb.c = 'u'; violet.c = 'i'; redshroom.c = 'r'; fabulis.c = 'v';
pinkherb.y = 11; pinkherb.x = 22; violet.y = 10; violet.x = 20;
redshroom.y = 18; redshroom.x = 28; fabulis.y = 15; fabulis.x = 18;
plantList.push_back(pinkherb);
plantList.push_back(violet);
plantList.push_back(redshroom);
plantList.push_back(fabulis);
}

void	pick(Character pl) {
std::list <Plant> :: iterator p; 
for (p = plantList.begin(); p != plantList.end(); ++p) 
	if (std::abs((int)(pl.y-p->y))+std::abs((int)(pl.x-p->x)) < 3) {
		plantList.erase(p);
		return;
	}
}
