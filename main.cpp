#include <iostream>
#include <ncurses.h>
#include "Character.class.hpp"
#include "CharacterPlayer.class.hpp"
#include "Map.class.hpp"

void	spring_init();
void	spring_end();

int	main(int ac, char **av) {
char	c;
WINDOW	*win = NULL;

CharacterPlayer	pl;
pl.y = 10;pl.x = 25;
pl.c = 'u';
Map	mp;
mp.map_init();

spring_init();
win = newwin(20, 50, LINES/2-10, COLS/2-25);
mvaddstr(LINES/2-9, COLS/2-45, "Press a key");

int u, v, w, t = 0;
while(1) {
	while((c=getch())==ERR);
	if (c=='q') break;
	switch (c) {
		case 'e': pl.y--; break;
		case 's': pl.x--; break;
		case 'd': pl.y++; break;
		case 'f': pl.x++; break; }
	// display
	box(win, 0, 0);
u = 10-pl.y;
if (u<0) u = 0;
v = 25-pl.x;
if (v<0) v = 0;
w = 64-pl.x;
if (w>25) w = 25;
t = 24-pl.y;
if (t>10) t = 10;
	// spaces top of the map
	for(int j=u; j>0; j--) {
		for(int k=0; k<50; k++) {
			mvwaddch(win, j-1, k, ' '); }}
	// spaces bottom of the map
	for(int j=t; j<10; j++) {
		for(int k=0; k<50; k++) {
			mvwaddch(win, j+10, k, ' '); }}
	for(int i=0; i<20-u-(10-t); i++) {
		// spaces left of the map
		for(int k=v; k>0; k--) {
			mvwaddch(win, i+u, k-1, ' '); }
		// spaces right of the map
		for(int k=w; k<25; k++) {
			mvwaddch(win, i+u, k+25, ' '); }
		for(int j=0; j<50-v-(25-w); j++) {
			mvwaddch(win, i+u, j+v, mp.s[(u+i+pl.y-10)*64+pl.x-25+j+v]);}}
	mvwaddch(win, 10, 25, pl.c);
	wrefresh(win);
	mvaddstr(LINES/2-7, COLS/2-45, "q to quit");
	mvaddstr(LINES/2-5, COLS/2-45, "esdf to move");
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
