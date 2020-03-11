#ifndef PLANT_HPP
# define PLANT_HPP

# include <list>

std::list <Plant>	plantList;


class	Plant {
public:
unsigned char c;

unsigned char x;
unsigned char y;
};


void	plants_init(void);

#endif
