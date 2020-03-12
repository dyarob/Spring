#ifndef PLANT_HPP
# define PLANT_HPP

# include <list>
# include "Character.class.hpp"
# include "Item.class.hpp"
# include "Inventory.class.hpp"

class	Plant {
public:
unsigned char c;
Item	i;

unsigned char x;
unsigned char y;
};


extern std::list <Plant>	plantList;


void	plants_init(void);
void	pick(Character pl, Inventory inv);

#endif
