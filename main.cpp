#include <iostream>
#include <ncurses.h>
#include "Character.class.hpp"
#include "CharacterPlayer.class.hpp"

void	spring_init();
void	spring_end();

int	main(int ac, char **av) {
char	c;
WINDOW	*win = NULL;

CharacterPlayer	pl;
pl.x = 10;pl.y = 25;
pl.c = 'u';

spring_init();
win = newwin(20, 50, LINES/2-10, COLS/2-25);
mvaddstr(LINES/2-9, COLS/2-45, "Press a key");
while(1) {
	while((c=getch())==ERR);
	if (c=='q') break;
	switch (c) {}
	// display
	box(win, 0, 0);
	mvwaddch(win, 10, 25, pl.c);
	wrefresh(win);
}
delwin(win);
spring_end();
return 0; }

void	spring_init() {
	setlocale(LC_ALL, "");
	initscr(); cbreak(); noecho();
	nodelay(stdscr, TRUE);
}

void	spring_end() {
	endwin();
}
