/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
}

#include <iostream>
#include <cassert>
#include "Card.h"
#include "SHPlayer.h"
#include "AnsiPrint.h"

using namespace std;


/**
 * Print my ID
 */
void
PrintMyID(const char* studId)
{
    char *str = new char[sizeof(studId) + 5];
    sprintf(str, "ID: %s", studId);
    AnsiPrint(str, yellow, red, true, true);
    cout << endl << endl;
    delete [] str;
}


/**
 * print the usage
 */
void
PrintUsage(const char* progName)
{
    assert(progName);
    cout << "Usage: " << progName << " [Seed] [ShowFirst(0/1)]" << endl;
}

int
main(int argc, char** argv)
{	
    bool showFirst = false;
    long seed = 0;
	int  countCard[52];
    if( argc > 3 ) {
        PrintUsage(argv[0]);
        exit(-1);
    }
    if( argc == 3 ) {
        showFirst = atoi(argv[2]);      // the third argument shows the first card
    }
  if( argc > 1 ) {
        seed = atoi(argv[1]);
    }                            
    srand(seed);
 	SHPlayer shplayer("Player");
    Card CardPlayer;
	// put your code here
	// take 5 random card in hand 
	for(int i=0;i<5;i++){
		if(i>0){
			countCard[i] = rand()%52;
			for(int j=0;j<i;j++){
				if(countCard[i] == countCard[j]){
					countCard[i] = rand()%52;
					j=0;
				}
			}
	}
		else{
			countCard[i] = rand()%52;	
		}
	}
	for(int i;i<5;i++){
		shplayer.addCard(CardPlayer,i);
		shplayer.getNumCards(i,countCard[i]);
	}			
	// output the cards
	if(showFirst == true){
		shplayer.openFirstCard();
	}
	else{
		shplayer.showCards();
	}

	//output what card u have in hand
	switch(shplayer.getHandPattern()){
		case 0:
			cout << "It's Stright Flush";
			break;
		case 1:
			cout << "It's Four Of A Kind";
			break;
		case 2:
			cout << "It's Full House";
		    break;	
		case 3:
		    cout << "It's Flush";
		    break; 
		case 4:
			cout << "It's Straight";
			break;
		case 5:
			cout << "It's Three Of A Kind";
			break;
		case 6:
			cout << "It's Two Pair";
			break;
		case 7:
			cout << "It's One Pair";
			break;
		case 8:
			cout << "It's Other";
			break;
	}
	
	cout << "\n";
	//output total points
	cout << "Total points: " << shplayer.totalPips() << endl;	
    PrintMyID("105703037");

    return 0;
}

