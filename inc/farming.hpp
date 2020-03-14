#ifndef FARMING_HPP
# define FARMING_HPP

# include "Character.class.hpp"
# include "Map.class.hpp"

extern bool	tilled[32][64];

void	tilled_init();

void	till(Character pl, Map mp);

#endif
