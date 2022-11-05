#include <curses.h>
#include <string>

#ifndef _MENU_H_
#define _MENU_H_

class Menu
{
    private:
        /* data */
    public:
        Menu(std::string text, char trigger, std::string *items, int num_items);
        ~Menu();

        int start_x;
        std::string text;
        char trigger;

        std::string *items;
        int num_items;
        int selected_item;

        void selectNextItem();
        void selectPrevItem();
};

class MenuBar
{
    private:
        /* data */
    public:
        MenuBar(WINDOW *win, Menu *menus, int num_menus);
        ~MenuBar();
        void reset();

        void draw();
        
        void drawMenu(Menu menu, bool is_selected);
        void drawMenuItems(Menu menu);

        void handleTrigger(char triger);

	    WINDOW *menuwin;
        WINDOW *win;
        Menu *menus;
        int num_menus;
        int selected_menu;
};
#endif
