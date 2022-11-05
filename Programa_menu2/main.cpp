#include <iostream>
#include <ncurses.h>

#include "menu.h"

using namespace std;

int main(){
    initscr();

    noecho();
    curs_set(0);

    if (!has_colors()){
    	return -1;
    }
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win =  newwin(yMax/2, xMax/2, yMax/4, xMax/4);
    box(win, 0, 0);

    string menu1[] = {"Enviar coord", "Solicitar coord", "Salir"};
    string menu2[] = {"no se", "aca va algo", "puto el que lee"};

    Menu menus[] = {
        Menu("Opciones", 'o', menu1, 3),
        Menu("Config", 'c', menu2, 3)
    };

    MenuBar menubar = MenuBar(win, menus, 2);
    menubar.draw();
    
    char ch;
    while (ch = wgetch(win))
    {
        menubar.handleTrigger(ch);
        menubar.draw();
    } 
    return 0;
}
