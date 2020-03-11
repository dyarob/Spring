#include "Inventory.class.hpp"

void	Inventory::inv_init(void) {
Item	pinkherb, violet, redshroom, fabulis;
pinkherb.c = 'u'; pinkherb.name = "Pink Herb";
violet.c = 'i'; violet.name = "Violet";
redshroom.c = 'r'; redshroom.name = "Red Mushroom";
fabulis.c = 'v'; fabulis.name = "Fabulis";
invItem	ipinkherb={pinkherb,"3"}, iviolet={violet,"2"}, iredshroom={redshroom,"1"}, ifabulis={fabulis,"4"};
items[0]=ipinkherb; items[1]=iviolet; items[2]=iredshroom; items[3]=ifabulis;
}
