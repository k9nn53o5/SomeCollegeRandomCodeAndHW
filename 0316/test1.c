#include <curses.h>

int main(){

	int ch;
	char string[50];	
	initscr();

	//echo();
	noecho();

	ch=getch();
	scanw("%s",string);

	mvaddch(7,7,ch);
	mvprintw(8,8,"%s",string);

	refresh();
	endwin();
	return 0;

}
