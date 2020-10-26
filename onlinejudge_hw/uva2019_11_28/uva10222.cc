#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
using namespace std;

const char keyBoardTable[]="1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";

int main(){
	char getChar;
	while(scanf("%c",&getChar) != EOF){
		for(int i=0;i<45;i++){
			if(tolower(getChar) == keyBoardTable[i]){
				getChar = keyBoardTable[((i-2)+45)%45];
			}
		}
		printf("%c",getChar);
	}
	return 0;
}

