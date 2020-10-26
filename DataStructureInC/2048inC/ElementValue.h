#ifndef _ELEMENTNUM_H_
#define _ELEMENT_H_
#include "Rand.h"

using namespace std;

class Element{
	int value;
	bool beadd;
	friend class Game;
public:
	void addvalue();   // the num add together
	void be_0();		
	void activate(); // 0->2or4
	Element();
};


#endif
