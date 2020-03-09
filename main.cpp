#include <iostream>
#include <ncurses.h>

void	spring_init();
void	spring_end();

int	main(int ac, char **av) {
char	c;
WINDOW	*win = NULL;

spring_init();	//<== new window
win = newwin(20, 50, LINES/2-10, COLS/2-25);
box(win, 0, 0);
wrefresh(win);
while(1) {
	while((c=getch())==ERR);
	if (c=='q') break;
	switch (c) {} }
delwin(win);
spring_end();
return 0; }

void	spring_init() {
	setlocale(LC_ALL, "");
	initscr(); cbreak(); noecho();
	nodelay(stdscr, TRUE);

	addch('c');
	move(2, 0);
	refresh();
}

void	spring_end() {
	endwin();
}
