#include <curses.h>

int main(){
	int ch;
	int flag=1;
	initscr();

	keypad(stdscr,TRUE);
	//keypad(stdscr,FALSE);

	while(flag){
		ch = getch();
		clear();
		switch(ch){
			case KEY_UP:
				printw("up\n");
				break;
			case KEY_DOWN:
				printw("down\n");
				break;
			case KEY_LEFT:
				printw("left\n");
				break;
			case KEY_RIGHT:
				printw("right\n");
				break;
			case 27:
				endwin();
				return 0;
			default:
				addch(ch);
				break;
		}
		
		//flag=0;

		//clear();
		refresh();
	}
	endwin();
	return 0;
}
