#ifndef INVENTORY_HPP
# define INVENTORY_HPP

# include "Item.class.hpp"

typedef struct {
Item	i;
char	n[10];
} invItem;


class	Inventory {
public:
invItem	items[20];

void	inv_init(void);
};

#endif
