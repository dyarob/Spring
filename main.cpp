#include <iostream>
#include <ncurses.h>
#include <list>
#include "Character.class.hpp"
#include "Map.class.hpp"
#include "Plant.class.hpp"
#include "Inventory.class.hpp"
#include "farming.hpp"

void	spring_init();
void	spring_end();
void	dsp_map(WINDOW *w, Character pl, Map mp);
void	dsp_tilled(WINDOW *w, Character pl);
void	dsp_plants(WINDOW *w, Character pl);
void	dsp_inv(WINDOW *winv, Inventory inv);
void	dsp_chars(WINDOW *win, Character pl, Character anissa);


int	main(int ac, char **av) {

bool	inv_open = false;
char	c;
WINDOW	*win, *winv = NULL;

Character	pl;
pl.y = 10; pl.x = 25; pl.c = '&';
Character	anissa;
anissa.y = 14; anissa.x = 35; anissa.c = '&';
Map	mp; mp.map_init();
tilled_init();
Inventory	inv; inv.inv_init();
plants_init();

spring_init();
win = newwin(20, 50, LINES/2-10, COLS/2-25);
mvaddstr(LINES/2-10, COLS/2-45, "Press a key");
mvaddstr(LINES/2-7, COLS/2-45, "q to quit");
mvaddstr(LINES/2-5, COLS/2-45, "esdf to move");
mvaddstr(LINES/2-3, COLS/2-45, "t to talk");
mvaddstr(LINES/2-1, COLS/2-45, "i for inventory");
mvaddstr(LINES/2+1, COLS/2-45, "p to pick (flower)");
mvaddstr(LINES/2+3, COLS/2-45, "l/o to till/plant");


while(1) {
	while((c=getch())==ERR);
	if (c=='q') break;
	switch (c) {
		case 'e': if (mp.s[(pl.y-1)*64+pl.x] == '.') pl.y--; break;
		case 's': if (mp.s[(pl.y)*64+pl.x-1] == '.') pl.x--; break;
		case 'd': if (mp.s[(pl.y+1)*64+pl.x] == '.') pl.y++; break;
		case 'f': if (mp.s[(pl.y)*64+pl.x+1] == '.') pl.x++; break;
		case 't': talk(pl, anissa); break;
		case 'i': if (!inv_open) {
				inv_open = true;
				winv = newwin(20, 20, LINES/2-10, COLS/2+30);
				box(winv, 0, 0);
				mvwaddstr(winv, 1, 1, "Inventory");
				wrefresh(winv); }
			else {
				inv_open = false;
				for (int i = 0; i < 20; i++)
					for (int j = 0; j <20; j++)
						mvwaddch(winv, i, j, ' ');
				wrefresh(winv);
				delwin(winv); } break;
		case 'p': inv = pick(pl, inv); break;
		case 'l': till(pl, mp); break;
		case 'o':break;
	}

	// DISPLAY
	dsp_map(win, pl, mp);
	dsp_tilled(win, pl);
	dsp_plants(win, pl);
	dsp_chars(win, pl, anissa);
	mvwaddch(win, 10, 25, pl.c);
	wrefresh(win);
	if (inv_open) {
		dsp_inv(winv, inv);
		wrefresh(winv); }
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

void	dsp_map(WINDOW *win, Character pl, Map mp) {
// spaces
int	u = 10-pl.y;
if (u<0) u = 0;
int	v = 25-pl.x;
if (v<0) v = 0;
int	w = 64-pl.x;
if (w>25) w = 25;
int	t = 24-pl.y;
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
}

void	dsp_plants(WINDOW *w, Character pl) {
std::list <Plant> :: iterator p; 
for (p = plantList.begin(); p != plantList.end(); ++p) 
	mvwaddch(w, p->y-(pl.y-10), p->x-(pl.x-25), p->c);
}

void	dsp_inv(WINDOW *w, Inventory inv) {
for (int i=0; i<4; i++) {
	mvwaddstr(w, 3+i*3, 1, inv.items[i].i.name.c_str());
	mvwaddstr(w, 4+i*3, 1, std::to_string(inv.items[i].n).c_str()); }
}

void	dsp_chars(WINDOW *w, Character pl, Character anissa) {
mvwaddch(w, anissa.y-(pl.y-10), anissa.x-(pl.x-25), anissa.c);
}

void	dsp_tilled(WINDOW *w, Character pl) {
for (int i = pl.y - 10; i < pl.y + 10; i++)
	for(int j = pl.x - 25; j < pl.x + 25; j++)
		if (tilled[i][j])
			mvwaddch(w, i-(pl.y-10), j-(pl.x-25), '^');
}
