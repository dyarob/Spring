all:
	g++ main.cpp Map.class.cpp Inventory.class.cpp Plant.class.cpp -o Spring -l ncurses -I inc
clean:
	rm -rf Spring
