#include "Character.class.hpp"

void	talk(Character pl, Character anissa) {
if (std::abs((int)(pl.y-anissa.y))+std::abs((int)(pl.x-anissa.x)) < 3) {
	WINDOW	*w = newwin(5, 50, LINES/2+12, COLS/2-25);
	box(w, 0, 0);
	mvwaddstr(w, 2, 5, "Anissa: Welcome to Springs Isle!");
	wrefresh(w);
	char	c;
	while((c=getch())==ERR);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 50; j++)
			mvwaddch(w, i, j, ' ');
	wrefresh(w);
	delwin(w);
}
}
