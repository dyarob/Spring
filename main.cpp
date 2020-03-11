#include <iostream>
#include <ncurses.h>
#include <list>
#include "Character.class.hpp"
#include "Map.class.hpp"
#include "Plant.class.hpp"
#include "Inventory.class.hpp"

void	spring_init();
void	spring_end();
void	dsp_plants(WINDOW *w, Character pl);
void	dsp_inv(WINDOW *winv, Inventory inv);

void	plants_init(void) {

Plant pinkherb, violet, redshroom, fabulis;
pinkherb.c = 'u';
violet.c = 'i'; redshroom.c = 'r'; fabulis.c = 'v';
pinkherb.y = 11; pinkherb.x = 22;
violet.y = 10; violet.x = 20;
redshroom.y = 18; redshroom.x = 28;
fabulis.y = 15; fabulis.x = 18;
plantList.push_back(pinkherb);
plantList.push_back(violet);
plantList.push_back(redshroom);
plantList.push_back(fabulis);

}

void	pick(Character pl) {
std::list <Plant> :: iterator p; 
for (p = plantList.begin(); p != plantList.end(); ++p) 
	if (std::abs((int)(pl.y-p->y))+std::abs((int)(pl.x-p->x)) < 3) {
		plantList.erase(p);
		return;
	}
}


int	main(int ac, char **av) {

bool	inv_open = false;
char	c;
WINDOW	*win, *winv = NULL;

Character	pl;
pl.y = 10;pl.x = 25;
pl.c = '&';
Map	mp;
mp.map_init();
Inventory	inv;
inv.inv_init();

plants_init();

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
		case 'f': pl.x++; break;

		case 'p': pick(pl); break;
		case 't':break;

		case 'i': if (!inv_open) {
				inv_open = true;
				winv = newwin(20, 20, LINES/2-10, COLS/2+30);
				box(winv, 0, 0);
				mvwaddstr(winv, 1, 1, "Inventory");
				dsp_inv(winv, inv);
				wrefresh(winv); }
			else {
				inv_open = false;
				for (int i = 0; i < 20; i++)
					for (int j = 0; j <20; j++)
						mvwaddch(winv, i, j, ' ');
				wrefresh(winv);
				delwin(winv); } break; }

	// DISPLAY
	box(win, 0, 0);
	// spaces
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
	dsp_plants(win, pl);
	mvwaddch(win, 10, 25, pl.c);
	wrefresh(win);
	mvaddstr(LINES/2-7, COLS/2-45, "q to quit");
	mvaddstr(LINES/2-5, COLS/2-45, "esdf to move");
	mvaddstr(LINES/2-3, COLS/2-45, "p to pick (flower)");
	mvaddstr(LINES/2-1, COLS/2-45, "i for inventory");
	mvaddstr(LINES/2+1, COLS/2-45, "t to talk");
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

void	dsp_plants(WINDOW *w, Character pl) {
std::list <Plant> :: iterator p; 
for (p = plantList.begin(); p != plantList.end(); ++p) 
	mvwaddch(w, p->y-(pl.y-10), p->x-(pl.x-25), p->c);
}

void	dsp_inv(WINDOW *w, Inventory inv) {
char	buf[10];
for (int i=0; i<4; i++) {
	mvwaddstr(w, 3+i*3, 1, inv.items[i].i.name.c_str());
	mvwaddstr(w, 4+i*3, 1, inv.items[i].n); }
}
