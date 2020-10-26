/* ..####....####.....##........##......##...####...######......##...####...######.
 * .....##..##..##...###....##..##.....##...##..##.....##......##.......##.....##..
 * ..####...######....##....######....##....######....###.....##.....####.....##...
 * .##......##..##....##........##...##.....##..##......##...##.....##.......##....
 * .######...####...######......##..##.......####...#####...##......######..##.....
 * ................................................................................
 * .##..##...####...##......##..##..##...##...####...##..##.                       
 * .##..##..##......##.......####...###.###..##..##..###.##.                       
 * .##..##..##.###..##........##....##.#.##..######..##.###.                       
 * .##..##..##..##..##........##....##...##..##..##..##..##.                       
 * ..####....####...######....##....##...##..##..##..##..##.                       
 * .........................................................                       
 * .##..##...####...######..##..##..######..##..##...####...##.......####..        
 * .###.##..##..##....##....##..##....##....###.##..##......##......##..##.        
 * .##.###..##..##....##....######....##....##.###..##.###..##......##..##.        
 * .##..##..##..##....##....##..##....##....##..##..##..##..##......##..##.        
 * .##..##...####.....##....##..##..######..##..##...####...######...####..        
 * ........................................................................*/
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZEX 15
#define MAP_SIZEY 30
#define STRING_LENGTH 10
#define DIRECTION_NUM  4
#define SNAKE_MAX_LENGTH (MAP_SIZEX - 2) * (MAP_SIZEY - 2)
#define MOVE_DISTANCE_PERSECOND 9

/****** global variable ******/
int input = KEY_DOWN;
int isGameOver = 0;
const char spaceString[] = "  ";
const char snakeString[] = "³D";
const char blockString[] = "Àð";
const char foodString[] = "­¹";
/*****************************/

/******* struct define *******/
typedef struct _position {
	int x, y;
} Position;

typedef struct _food {
	Position pos;
	int isAppear;
} Food;

typedef struct _snake {
	Position pos[SNAKE_MAX_LENGTH];
	int length;
	int dir;
} Snake;

/****************************/
int isInBlockPosition(int x, int y) {
	return
		x == 0 || x == (MAP_SIZEX - 1) ||
		y == 0 || y == (MAP_SIZEY - 1);
}


int isInSnakePosition(Snake snake, int x, int y) {
	int i;
	for(i = 0; i < snake.length; ++i) {
		if(snake.pos[i].x == x && snake.pos[i].y == y) {
			return 1;
		}
	}
	return 0;
}
int isEatTheFood(int x, int y, Food food) {
	return (food.isAppear ? (x == food.pos.x && y == food.pos.y) : 0);
}
int isEatSnakeSelf(int x, int y, Snake snake) {
	int i, last2 = snake.length - 1;
	for(i = 1; i < last2; ++i) {
		if(snake.pos[i].x == x && snake.pos[i].y == y) {
			return 1;
		}
	}
	return 0;
}
void moveSnakePosition(Snake *snake, Position headPos) {
	int i;
	for(i = snake -> length - 1; i > 0; --i) {
		snake -> pos[i] = snake -> pos[i-1];
	}
	snake -> pos[0] = headPos;
}
void updateSnakePosition(Snake *snake, Food *food, char map[MAP_SIZEX][MAP_SIZEY][STRING_LENGTH]) {
	const int PositiveKey[DIRECTION_NUM] = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};
	const int NegativeKey[DIRECTION_NUM] = {KEY_DOWN, KEY_UP, KEY_RIGHT, KEY_LEFT};
	const int dy[DIRECTION_NUM] = {0, 0, -1, 1}, dx[DIRECTION_NUM] = {-1, 1, 0, 0};
	static int dir = 0;
	int i, nowInput = input;
	Position nextHeadPos;

	for(i = 0; i < DIRECTION_NUM; ++i) {
		if(nowInput == PositiveKey[i] && snake -> dir != NegativeKey[i]) {
			snake -> dir = nowInput;
			dir = i;
			break;
		}
	}
	/*********** same as the for loop ***********
	  switch(nowInput) {
	  case KEY_UP:
	  if(snake -> dir != KEY_DOWN) {
	  snake -> dir = nowInput;
	  dir = 0;
	  }
	  break;
	  case KEY_DOWN:
	  if(snake -> dir != KEY_UP) {
	  snake -> dir = nowInput;
	  dir = 1;
	  }
	  break;
	  case KEY_LEFT:
	  if(snake -> dir != KEY_RIGHT) {
	  snake -> dir = nowInput;
	  dir = 2;
	  }
	  break;
	  case KEY_RIGHT:
	  if(snake -> dir != KEY_LEFT) {
	  snake -> dir = nowInput;
	  dir = 3;
	  }
	  break;
	  }
	 *******************************************/
	nextHeadPos.x = snake -> pos[0].x + dx[dir];
	nextHeadPos.y = snake -> pos[0].y + dy[dir];

	if(isEatTheFood(nextHeadPos.x, nextHeadPos.y, *food)) {
		food->isAppear = 0;
		snake->length = snake->length + 1;
	} else if(//isInBlockPosition(nextHeadPos.x, nextHeadPos.y) ||
			isEatSnakeSelf(nextHeadPos.x, nextHeadPos.y, *snake)) {
		isGameOver = 1;
		return;
	}

	/* through the wall */

	else if(isInBlockPosition(nextHeadPos.x, nextHeadPos.y)){

		if(nextHeadPos.x ==0){

			nextHeadPos.x = MAP_SIZEX - 2;
		}

		else if(nextHeadPos.x == MAP_SIZEX-1){

			nextHeadPos.x = 1;
		}

		else if(nextHeadPos.y ==0){

			nextHeadPos.y = MAP_SIZEY -2;
		}

		else if(nextHeadPos.y == MAP_SIZEY-1){

			nextHeadPos.y = 1;
		}

	}

	moveSnakePosition(snake, nextHeadPos);
}



void setRandomFood(Snake snake, Food *food, char map[MAP_SIZEX][MAP_SIZEY][STRING_LENGTH]) {
	int i, j, listNum = 0, foodIndex, listSize = SNAKE_MAX_LENGTH - snake.length;
	Position foodPositionList[listSize];

	if(food -> isAppear == 1) return ;
	for(i = 1; i < MAP_SIZEX - 1; ++i) {
		for(j = 1; j < MAP_SIZEY - 1; ++j) {
			if(isInSnakePosition(snake, i, j) == 0) {
				foodPositionList[listNum].x = i, foodPositionList[listNum].y = j;
				++listNum;
			}
		}
	}
	foodIndex = rand() % listSize;
	food -> pos = foodPositionList[foodIndex];
	food -> isAppear = 1;
}
void setMap(Snake snake, Food food, char map[MAP_SIZEX][MAP_SIZEY][STRING_LENGTH]) {
	int i, j;
	/******** set space ********/
	for(i = 1; i < MAP_SIZEX - 1; ++i) {                          
		for(j = 1; j < MAP_SIZEY - 1; ++j) {                      
			strcpy(map[i][j], spaceString);                       
		}                                                         
	}
	/******** set snake *******/	
	for(i = 0; i < snake.length; ++i) {                           
		strcpy(map[snake.pos[i].x][snake.pos[i].y], snakeString); 
	} 
	/******** set  food *******/	
	strcpy(map[food.pos.x][food.pos.y], foodString); 
}
void draw(Snake snake, Food food, char map[MAP_SIZEX][MAP_SIZEY][STRING_LENGTH]) {
	int i, j, headX = snake.pos[0].x, headY = snake.pos[0].y;

	setMap(snake, food, map);
	clear();                         /* curses.h: clean the screen */
	for(i = 0; i < MAP_SIZEX; ++i) {
		for(j = 0; j < MAP_SIZEY; ++j) {
			if(i == headX && j == headY) {
				attron(A_REVERSE);
			} else {
				attroff(A_REVERSE);
			}
			printw("%s", map[i][j]); /* curses.h: print to screen  */
		}
		printw("\n");
	}
	refresh();
}
void initBlockMap(char map[MAP_SIZEX][MAP_SIZEY][STRING_LENGTH]) {
	int i, j;
	for(i = 0; i < MAP_SIZEX; ++i) {
		for(j = 0; j < MAP_SIZEY; ++j) {
			if(isInBlockPosition(i, j)) {
				strcpy(map[i][j], blockString);
			}
		}
	}
}
/********************************************/
void * getInput(void * parameter) {
	while(1) {
		input = getch(); /* curses.h: get input              */
	}
}
int startWindow() {
	pthread_t id;

	initscr();           /* curses.h: start windows          */
	noecho();            /* curses.h: let input no show      */
	keypad(stdscr, TRUE);/* curses.h: use KEY_UP KEY_DOWN... */
	if(pthread_create(&id, NULL, getInput, NULL) != 0) {
		printw("Something Error\n");
		refresh();
		return 0;
	}
	return 1;
}
void endWindows(Snake snake) {
	printw("Snake length = %d\n", snake.length);
	refresh();
	endwin();            /* curses.h: end windows            */
}
void sleep(double consumedTimeMS) {
	double sleepTimeMS = 1e6 / MOVE_DISTANCE_PERSECOND;
	consumedTimeMS = consumedTimeMS * 1e6 / CLOCKS_PER_SEC;
	usleep((unsigned int)(sleepTimeMS - consumedTimeMS));
}
/********************************************/
int main(void) {
	char map[MAP_SIZEX][MAP_SIZEY][STRING_LENGTH];
	Snake snake = {.pos[0].x = 1, .pos[0].y = 1, .length = 1, .dir = KEY_DOWN};
	Food food = {.isAppear = 0};
	clock_t start_time, end_time;

	if(startWindow()) {
		srand(time(NULL));
		initBlockMap(map);
		while(isGameOver == 0) {
			start_time = clock();
			updateSnakePosition(&snake, &food, map);
			setRandomFood(snake, &food, map);
			draw(snake, food, map);
			end_time = clock();
			sleep(end_time - start_time);
		}
		endWindows(snake);
	}
	return 0;
}


