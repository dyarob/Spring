#include "Plant.class.hpp"

void	plants_init(void) {

Plant pinkherb, violet, redshroom, fabulis;
plantList.push_back(pinkherb);
plantList.push_back(violet);
plantList.push_back(redshroom);
plantList.push_back(fabulis);
pinkherb.c = 'u';
violet.c = 'i';
redshroom.c = 'r';
fabulis.c = 'v';
pinkherb.y = 11; pinkherb.x = 22;
violet.y = 10; violet.x = 20;
redshroom.y = 18; redshroom.x = 28;
fabulis.y = 15; fabulis.x = 18;

}
