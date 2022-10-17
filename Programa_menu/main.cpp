#include <iostream>
#include <ncurses.h>
#include <string>
using namespace std;

typedef struct{
	int a;
	int b;
}page_menu;

void menu(page_menu *ptrmain);
void seleccion(page_menu *ptrmain);
void enter(page_menu *ptrmain);

const char *opciones[] = {"opcion 1", "opcion 2", "opcion 3", "Salir"};

int main(){
	
	page_menu main_menu = {0, 0};

	initscr();

	keypad(stdscr, TRUE);
	curs_set(0);		
	
	WINDOW *main = newwin(20, 20, 0, 0);
	menu(&main_menu);	
	seleccion(&main_menu);

	endwin();
	return 0;
}

void seleccion(page_menu *ptrmain){
	int ch;
	while((ch = getch()) != KEY_F(1)){	
		switch(ch){
			case KEY_UP:	ptrmain->a--;
					ptrmain->a = ptrmain->a < 0 ? 0 : ptrmain->a;
				break;
			case KEY_DOWN:	ptrmain->a++;
					ptrmain->a = ptrmain->a > 3 ? 3 : ptrmain->a;
				break;
			case 10: 	enter(ptrmain);
					break;
		}
		menu(ptrmain);
	}
}

void menu(page_menu *ptrmain){
	switch(ptrmain->a){
		case 0:	clear();
			attron(A_STANDOUT);
			mvprintw(1, 2, "%s", opciones[0]);
			attroff(A_STANDOUT);
			mvprintw(2, 2, "%s", opciones[1]);
			mvprintw(3, 2, "%s", opciones[2]);
			mvprintw(4, 2, "%s", opciones[3]);
			refresh();
			break;
		case 1:	clear();
			attron(A_STANDOUT);
			mvprintw(2, 2, "%s", opciones[1]);
			attroff(A_STANDOUT);
			mvprintw(1, 2, "%s", opciones[0]);
			mvprintw(3, 2, "%s", opciones[2]);
			mvprintw(4, 2, "%s", opciones[3]);
			refresh();
			break;
		case 2:	clear();
			attron(A_STANDOUT);
			mvprintw(3, 2, "%s", opciones[2]);
			attroff(A_STANDOUT),
			mvprintw(1, 2, "%s", opciones[0]);
			mvprintw(2, 2, "%s", opciones[1]);
			mvprintw(4, 2, "%s", opciones[3]);
			refresh();
			break;
		case 3:	clear();
			attron(A_STANDOUT);
			mvprintw(4, 2, "%s", opciones[3]);
			attroff(A_STANDOUT);
			mvprintw(1, 2, "%s", opciones[0]);
			mvprintw(2, 2, "%s", opciones[1]);
			mvprintw(3, 2, "%s", opciones[2]);
			refresh();
			break;
	}
	refresh();
}

void enter(page_menu *ptrmain){
	switch(ptrmain->a){
		case 2:	clear();
			int i;
			while((i = getch()) != 'q'){
				printw("hola mundo\n");
				refresh();
			}	
			break;
		case 3: system("clear");
			exit(1);
			break;
		default:
			break;
	}
}
