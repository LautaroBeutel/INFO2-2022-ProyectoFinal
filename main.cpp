#include <iostream>
#include <ncurses.h>

using namespace std;

int main(){
	initscr();	//screan init
	int ch;	
	keypad(stdscr, TRUE);	//allows function keys and arrows

//	refresh();	//refresh the screen to print what is in the memory

	while(1){
		while((ch = getch()) != KEY_F(1)){
			switch(ch){
				case KEY_LEFT:	printw("izquierda\n");
					break;
				case KEY_UP:	printw("arriba\n");
					break;
				case KEY_DOWN:	printw("abajo\n");
					break;
				case KEY_RIGHT:	printw("derecha\n");
					break;
			}
			refresh();
		
		}
	}

	endwin();	//free the used memory 
	return 0;
}
