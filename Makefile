all:
	g++ main.cpp Map.class.cpp Inventory.class.cpp -o Spring -l ncurses -I inc
clean:
	rm -rf Spring
