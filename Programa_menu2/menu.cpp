#include "menu.h"

Menu::Menu(std::string text, char trigger, std::string *items, int num_items){
    this->text = text;
    this->trigger = trigger;
    this->items = items;
    this->num_items = num_items;

    this->selected_item = 0;
}

void Menu::selectNextItem(){
	this->selected_item++;
	if(this->selected_item >= this->num_items){
		this->selected_item = 0;
	}
}

void Menu::selectPrevItem(){
	this->selected_item--;
	if(this->selected_item < 0){
		this->selected_item = this->num_items;
	}
}

Menu::~Menu(){

}

MenuBar::MenuBar(WINDOW *win, Menu *menus, int num_menus){
    this->win = win;
    this->menus = menus;
    this->num_menus = num_menus;
    this->selected_menu = -1;

    int yMax, xMax, yBeg, xBeg;
    getmaxyx(win, yMax, xMax);
    getbegyx(win, yBeg, xBeg);

    menuwin = newwin(yMax-2, xMax-2, yBeg+1, xBeg+1);
    keypad(menuwin, true);
    wrefresh(menuwin);

    int current_pos = 2;

    for (int i = 0; i < num_menus; i++)
    {
        this->menus[i].start_x = current_pos;
        current_pos += this->menus[i].text.length() + 1;
    }
}

void MenuBar::reset(){
    for (int i = 0; i < num_menus; i++)
    {
        int start_x = this->menus[i].start_x;
        std::string text = this->menus[i].text;
        mvwprintw(win, 0, start_x, text.c_str());
    }
    wrefresh(win);
}
void MenuBar::draw(){
    for (int i = 0; i < num_menus; i++)
    {
        drawMenu(menus[i], selected_menu == i);
    }
}

void MenuBar::drawMenu(Menu menu, bool is_selected){
    int start_x = menu.start_x;
    std::string text = menu.text;
    mvwprintw(win, 0, start_x, text.c_str());
    if(is_selected)
    {
        wattron(win, A_STANDOUT);
        mvwprintw(win, 0, start_x, text.c_str());
        wattroff(win, A_STANDOUT);
        wrefresh(win);
    }

    int ch;
    drawMenuItems(menu);
    wrefresh(menuwin);
    while (is_selected && (ch = wgetch(menuwin)) != 'q')
    {
        switch (ch)
        {
        case KEY_UP:
            menu.selectPrevItem();
            break;
        case KEY_DOWN:
            menu.selectNextItem();
            break;
        default:
            break;
        }
        drawMenuItems(menu);
    }
    werase(menuwin);
    wrefresh(menuwin);
    reset();
}

void MenuBar::drawMenuItems(Menu menu){
    int yMax, xMax;
    getmaxyx(menuwin, yMax, xMax);
    for (int  i = 0; i < menu.num_items; i++)
    {
        mvwprintw(menuwin, i, 0, menu.items[i].c_str());
        if (menu.selected_item == i)
        {
            mvwchgat(menuwin, i, 0, xMax, A_NORMAL, 1, NULL);
        }else{
            mvwchgat(menuwin, i, 0, xMax, A_NORMAL, 0, NULL);
        }
        
    }
    
}

void MenuBar::handleTrigger(char trigger){
    for (int i = 0; i < num_menus; i++)
    {
        if (trigger == this->menus[i].trigger)
        {
            selected_menu = i;
        }
    }
}

MenuBar::~MenuBar(){
    
}
