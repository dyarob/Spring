#include "Plant.class.hpp"
#include <cstdlib>
#include <iostream>

std::list <Plant>	plantList;

void	plants_init(void) {
Plant ppinkherb, pviolet, predshroom, pfabulis;
ppinkherb.c = 'u'; pviolet.c = 'i'; predshroom.c = 'r'; pfabulis.c = 'v';
ppinkherb.y = 11; ppinkherb.x = 22; pviolet.y = 10; pviolet.x = 20;
predshroom.y = 18; predshroom.x = 28; pfabulis.y = 15; pfabulis.x = 18;
ppinkherb.i = pinkherb; pviolet.i = violet; predshroom.i = redshroom; pfabulis.i = fabulis;
plantList.push_back(ppinkherb);
plantList.push_back(pviolet);
plantList.push_back(predshroom);
plantList.push_back(pfabulis);
}

Inventory	pick(Character pl, Inventory inv) {
std::list <Plant> :: iterator p; 
for (p = plantList.begin(); p != plantList.end(); ++p) 
	if (std::abs((int)(pl.y-p->y))+std::abs((int)(pl.x-p->x)) < 3) {
		for (int i = 0; i < 20; i++)
			if (p->i.c == inv.items[i].i.c)
				inv.items[i].n++;
		plantList.erase(p);
		return inv;
	}
	return inv;
}
