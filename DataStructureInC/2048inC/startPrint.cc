#include "startPrint.h"
#include <iostream>
using namespace std;

void startprint(){

	cout<<"control   |W|  "<<endl<<"        |A|S|D|  to make 4x4 matrix to 2048\n"<<endl<<"Press \"g\" to start"<<endl;
	char startg;
	do{
		scanf("%c",&startg);
	}while(startg != 'g');
	cout<<"Good luck!"<<endl;

}
