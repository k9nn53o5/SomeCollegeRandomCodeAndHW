/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */
extern "C"{
#include <stdlib.h>
#include <time.h>
}
#include <cstring>
#include <cassert>
#include "SHPlayer.h"
#include "SHDealer.h"


// constructor
SHDealer::SHDealer(const char * dealerName)
{
	name = strdup(dealerName);
	start();
}


// destructor
SHDealer::~SHDealer()
{

}


// distribute a card to the player
int
SHDealer::giveCard(Card newcard)
{
	SHPlayer::addCard(newcard);
}


// give the dealer a card
void
SHDealer::addCard()
{
	if(nCards < kMaxCards){
		cards[nCards++];
	}
	else{
		cout << "Error: Exceed the maximal number of cards a player can have.\n";
	}
}


// determind who has win the game.
// if both of them have the same pattern,
// the one having more total pips wins the game.
Result
SHDealer::judge(SHPlayer& player)
{
	if(nCards < 5){
		return LOSE;
	}
	else{
		getHandPattern();

	}
}


// start a new game(round)
// before starting a new game(round), you should have
// a new deck, and then shuffle it.
// The deck only has pips A, 8, 9, 10, J, Q, K.
void
SHDealer::start()
{
	nCards=0;
	showAll = false;
}


// shuffle the deck of cards
void
SHDealer::shuffle(int *anArray)
{
	int temp;
	srand(time(NULL));
	for(int i=0;i<23;i++){
		if(anArray[rand()%24] != anArray[rand()%12+rand()%10]){
			temp = anArray[rand()%24];
			anArray[rand()%24] = anArray[rand()%12+rand()%10];
			anArray[rand()%12+rand()%10] = temp;
		}
	}
}


// open the dealer's first card
void
SHDealer::openFirstCard()
{
	showAll = true;
}


// show the dealer's hand to the screen
void
SHDealer::showCards() const
{

}
