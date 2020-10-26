#ifdef MAIN_H_
#define MAIN_H_

#include <iostream>
#include "startPrint.h"
#include "ElementValue.h"
#include "GamePlay.h"
#include "Rand.h"
using namespace std;

int main(){
	startprint();
	Game g;
	char keyin;
	g.print();
	while(scanf("%c",&keyin) != 'c'  || g.endjudge() != 1 || g.endjudge() != 2){
		g.keypress(keyin);
		g.print();
	}

	cout << "game end";
return 0;
}

#endif
