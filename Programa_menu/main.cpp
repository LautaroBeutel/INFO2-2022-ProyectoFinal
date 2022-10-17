#include <iostream>
#include <ncurses.h>
#include <string>
using namespace std;

typedef struct{
	int a;
	int b;
}page_menu;

void menu(page_menu *main);
void seleccion(page_menu *main);

const char *opciones[] = {"opcion 1", "opcion 2", "opcion 3", "opcion 4"};

int main(){
	
	page_menu main_menu = {0, 0};

	initscr();

	keypad(stdscr, TRUE);
	curs_set(0);		
	
	WINDOW *main = newwin(20, 20, 0, 0);
	
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
					ptrmain->a = ptrmain->a > 4 ? 4 : ptrmain->a;
				break;
			case 'q':	ptrmain->b--;
					ptrmain->b = ptrmain->b < 0 ? 0 : ptrmain->b;
				break;
			case 10:	ptrmain->b++;
					ptrmain->b = ptrmain->b > 1 ? 1: ptrmain->b;
				break;
		}
		menu(ptrmain);
	}
}

void menu(page_menu *ptrmain){
	switch(ptrmain->a){
		case 0:	printw("\r%s", opciones[0]);
			printw("\t%d", ptrmain->b);
			break;
		case 1:	printw("\r%s", opciones[1]);
			printw("\t%d", ptrmain->b);
			break;
		case 2:	printw("\r%s", opciones[2]);
			printw("\t%d", ptrmain->b);
			break;
		case 3: printw("\r%s", opciones[3]);
			printw("\t%d", ptrmain->b);
			break;
	}
	refresh();
}
