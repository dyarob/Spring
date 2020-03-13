#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <curses.h>
# include "Character.class.hpp"
# include <cstdlib>	// abs

class	Character {
public:
unsigned char	c;

unsigned int	x;
unsigned int	y;
};

void	talk(Character pl, Character anissa);

#endif
