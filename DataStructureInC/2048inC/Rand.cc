#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Rand.h"

using namespace std;

int randval(int a,int b){
	srand(time(NULL));
	return rand()%(b-a+1) + a;
}
