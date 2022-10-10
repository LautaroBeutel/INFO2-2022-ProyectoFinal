#include <iostream>
#include <ncurses.h>
using namespace std;

void menu(WINDOW *body, int);

const char* opciones[] = {"opcion 1", "opcion 2", "opcion 3", "opcion 4"};

int main(){
	initscr();

	keypad(stdscr, TRUE);
	curs_set(0);		
	
	int max_x, max_y, col, rowls;
	int start_x, start_y;

	int ch;
       	int op = 0;
	
	col = 50;
	rowls = 20;

	getmaxyx(stdscr, max_y, max_x);

	start_x = (max_x - col) / 2;
	start_y = (max_y - rowls) / 2;

	printw("press F1 to exit");

	refresh();

	WINDOW *main_body = newwin(rowls, col, start_y, start_x);
	
	box(main_body, 0, 0);
	wrefresh(main_body);
	
	for(int i = 1; i <= 4; i++){
		mvwprintw(main_body, i, 2,"%s", opciones[i-1]);
	}
	printw("\n");
	wrefresh(main_body);
	
	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	
			case KEY_UP:
				op--;
				op = op < 0 ? 0 : op;
				break;
			case KEY_DOWN:
				op++;
				op = op > 3 ? 3 : op;
				break;	
		}
		menu(main_body, op);
	}
	
	//getch();
	
	endwin();
	return 0;
}

void menu(WINDOW *body, int op){
	switch(op){
		case 0:	wattron(body, A_STANDOUT);
			mvwprintw(body, 1, 2, "%s", opciones[0]);
			wattroff(body, A_STANDOUT);
			mvwprintw(body, 2, 2, "%s", opciones[1]);
			mvwprintw(body, 3, 2, "%s", opciones[2]);
			mvwprintw(body, 4, 2, "%s", opciones[3]);
			wrefresh(body);
			break;
		case 1:	wattron(body, A_STANDOUT);
			mvwprintw(body, 2, 2, "%s", opciones[1]);
			wattroff(body, A_STANDOUT);
			mvwprintw(body, 1, 2, "%s", opciones[0]);
			mvwprintw(body, 3, 2, "%s", opciones[2]);
			mvwprintw(body, 4, 2, "%s", opciones[3]);
			wrefresh(body);
			break;
		case 2:	wattron(body, A_STANDOUT);
			mvwprintw(body, 3, 2, "%s", opciones[2]);
			wattroff(body, A_STANDOUT),
			mvwprintw(body, 1, 2, "%s", opciones[0]);
			mvwprintw(body, 2, 2, "%s", opciones[1]);
			mvwprintw(body, 4, 2, "%s", opciones[3]);
			wrefresh(body);
			break;
		case 3:	wattron(body, A_STANDOUT);
			mvwprintw(body, 4, 2, "%s", opciones[3]);
			wattroff(body, A_STANDOUT);
			mvwprintw(body, 1, 2, "%s", opciones[0]);
			mvwprintw(body, 2, 2, "%s", opciones[1]);
			mvwprintw(body, 3, 2, "%s", opciones[2]);
			wrefresh(body);
			break;
	}
}
