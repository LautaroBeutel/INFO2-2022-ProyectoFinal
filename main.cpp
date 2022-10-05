#include <iostream>
#include <ncurses.h>

using namespace std;

//WINDOW *create_wind(int height, int width, int startX, int startY);
//void destroy_win(WINDOW *local_win);

int main(){

	/*NCURSES INIT*/
	initscr();
		
	keypad(stdscr, TRUE);
		
	/*Create a new window*/
	WINDOW *menuwin = newwin(10, 10, 2, 2);
	refresh();

	box(menuwin, 0, 0);
	wrefresh(menuwin);	
	getch();
/*	while(1){
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
*/
	endwin();	//free the used memory 
	return 0;
}

/*WINDOW *create_wind(int height, int width, int startX, int startY){
	WINDOW *local_win;

	local_win = newwin(height, width, startX, startY);
	box(local_win, 0, 0);
	wrefresh(local_win);

	return local_win; 
}

void destroy_win(WINDOW local_win){
	
}*/
