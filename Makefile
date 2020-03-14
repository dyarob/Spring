all:
	g++ main.cpp Map.class.cpp Inventory.class.cpp Plant.class.cpp Item.class.cpp Character.class.cpp farming.cpp -o Spring -l ncurses -I inc
clean:
	rm -rf Spring
