all:
	g++ main.cpp Character.class.cpp CharacterPlayer.class.cpp -o Spring -l ncurses -I inc
clean:
	rm -rf Spring
