#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_
#include <iostream>
#include "ElementValue.h"

class Game{
	Element arr[4][4];

public:
	void print();
	void keypress(char);	//the whole pic move
	void createEle(int,int,int); //(x,y) element value
	int endjudge();      // return  -1->not end and arr full 0->not end and arr not full;      1-> end win ;2-> end lose
	void elementmove();  // an element move
	int giveEleValue();  // 90% of 2 and 10% of 4
	Game(){
		}
};


#endif
