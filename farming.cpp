#include "farming.hpp"

bool	tilled[32][64];

void	tilled_init() {
for (int i = 0; i < 32; i++)
	for (int j = 0; j < 64; j++)
		tilled[i][j] = false;
}

void	till(Character pl, Map mp) {
if (mp.s[(pl.y+1)*64+pl.x] == '.')
	tilled[pl.y+1][pl.x] = true;
}
