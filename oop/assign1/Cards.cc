/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
  NAME
  Cards.cc
  NOTE
  You are asked to design this module.
  You need to draw the given number of cards and print them out.
  Assume that you are given a deck of 52 cards. The cards do not reappear.
  That is, you do not put a card back into the deck after it is drawn.
 ***************************************************************************/

#include <iostream>
#include "Cards.h"
extern "C"{
#include <stdio.h>
#include <stdlib.h>
}
using namespace std;

//void swepSuit(char *string,int i0);

int CardOut(int CardTaken,int Seed = 0){
//  int main(){
//	int CardTaken,Seed;
//	cin >> CardTaken >> Seed;
	int CardCount[52] = {0};		// 0 in the card heap <-> 1 be taken; S->D->H->C; A->2->3->...	
	int CardNum = 52,i,Wid;
	int random,multiple_5;
	int i0,i1,i2,i3,i4,i5;
	if(CardTaken > 52){
		cout << "Sorry, number of cards can not exceed 52" << endl;
	}
	else{
	srand(Seed);
	for(i=0;i<CardTaken;i++){
		random = rand()%52;
		if(CardCount[random] == 0)
			CardCount[random] = i+1;
		else
			i--;
		continue;
	}
/*	for(i=0;i<52;i++){
		cout << CardCount[i];
	}
	cout << endl;    */

	for(i2=0;i2<(int) CardTaken/5+1;i2++){
		if(CardTaken%5==0 && i2==CardTaken/5){
			continue;
		}
	for(i3=0;i3<11;i3++){
//		cout << "check2 ";
		for(i1=0;i1 < CardTaken && i1 < 5;i1++){
				for(i0=0;i0<52;i0++){
					if(CardCount[i0] == i1+i2*5+1)
  	/*					for(i5=0;i5<11;i5++){
							if(card[i0%13][i3][i5] == 'x')
								if(i0<=12)
									card[i0%13][i3][i5] = 's';
								else if(i0>12 && i0<=25)
									card[i0%13][i3][i5] = 'h';
								else if(i0>25 && i0<=38)
									card[i0%13][i3][i5] = 'd';
								else if(i0>38 && i0<=51)
									card[i0%13][i3][i5] = 'c';
						}	*/
//						swepSuit(card[i0%13][i3],i0);	
						cout << card[i0][i3] << " ";
				} 
		}
		cout << endl;
	}
	}
	}
	return 0;
}
/*
void swepSuit(char *string,int i0){
	int suit_num,i;
	suit_num = i0/13;  //0 s 1 h 2 d 3 c
	if(suit_num == 0)
		for(i=0;i<11;i++){
			if(*(string+i) == 120)
				*(string+i) = 83;

		}
	else if(suit_num == 1){
		for(i=0;i<11;i++){
			if(*(string+i) == 120)
				*(string+i) = 72;
		}
	}
	else if(suit_num == 2){
		for(i=0;i<11;i++){
			if(*(string+i) == 120)
				*(string+i) = 68;
		}
	}
	else if(suit_num == 3){
		for(i=0;i<11;i++){
			if(*(string+i) == 120)
				*(string+i) = 67;
		}
	}
}  */
