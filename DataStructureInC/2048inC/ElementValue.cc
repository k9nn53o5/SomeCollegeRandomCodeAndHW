#include <iostream>
#include "ElementValue.h"
using namespace std;

void Element::addvalue(){
	value+=value;
}

void Element::be_0(){
	value = 0;
}

void Element::activate(){
	int rand = randval(0,9);
	if(rand < 9){
		value=4;
	}	
	else{
		value=2;
	}
}

Element::Element(){
	value=0;
}
