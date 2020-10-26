/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include "AnsiPrint.h"
#include "Card.h"
#include "CardPattern.h"
#include "SHPlayer.h"

using namespace std;


const char* HandTypeName[9] = {
    "Straight flush",
    "Four of a kind",
    "Full house",
    "Flush",
    "Straight",
    "Three of a kind",
    "Two pair",
    "One pair",
    "Other"
};

// constructor
SHPlayer::SHPlayer(const char* playerName)
{

}

// initialize the number of cards to 0
void
SHPlayer::start()
{

}

// add a new card to the current hand
// need to protect the array from overflowing
void SHPlayer::addCard(Card newCard,int no)
{
	cards[no] = newCard;
}

// open the first card so it faces up
void
SHPlayer::openFirstCard()
{
	for(int n2=0;n2<11;n2++){
		for(int n1=0;n1<5;n1++){
			if(n1==0){
				for(int n0=0;n0<12;n0++){
				cout << card[13][n2][n0];
				}
			}
			else{
				for(int n0=0;n0<12;n0++){
					if(card[cards[n1].getPip()][n2][n0] == 'x'){
					//	if(cards[n1].getSuit() == 0 || cards[n1].getSuit() == 2)
					//		AnsiPrint(cardAbbrev[cards[n1].getSuit()],black,white,false,false);
					//	else
					//		AnsiPrint(cardAbbrev[cards[n1].getSuit()],red,white,false,false);
					cout << cardAbbrev[cards[n1].getSuit()];
					}
					else{
					//	if(cards[n1].getSuit() == 0 ||cards[n1].getSuit() == 2 )
					//		AnsiPrint(card[cards[n1].getPip()][n2][n0],black,white,false,false);
					//	else
					
					//		AnsiPrint(card[cards[n1].getPip()][n2][n0],red,white,false,false);
					cout << card[cards[n1].getPip()][n2][n0];
					}
				}
			}
			cout << " ";
		}
		cout << "\n";
	}
}

// print the current hand to the screen graphically
void
SHPlayer::showCards() const
{
	for(int n2=0;n2<11;n2++){	
		for(int n1=0;n1<5;n1++){
	//		replace(card[cards[n1].getPip()][n2].begin(),card[cards[n1].getPip()][n2].end()
	//				,'x',cardAbbrev[cards[n1].getSuit()]);
			for(int n0=0;n0<12;n0++){
				if(card[cards[n1].getPip()][n2][n0] == 'x'){
					cout <<	cardAbbrev[cards[n1].getSuit()];
				}
				else{
					cout << card[cards[n1].getPip()][n2][n0];
				}
			}
			cout<< " ";
			}
		cout << "\n";
		}
	
}


// get the total points of the current hand
int
SHPlayer::totalPips() const
{
	int total_pips=0;
	for(int i=0;i < 5;i++){
	total_pips+=(sortedCards[i].getPip()+1);
	}
	return total_pips;
}

// judge what kind of hand type you own
// you need to have 5 cards
HandType
SHPlayer::getHandPattern() 
{
	sortCards();
	if(isStraightFlush() == true)
		return STRAIGHT_FLUSH;
	else if(isFourOfAKind() == true)
		return FOUR_OF_A_KIND;
	else if(isFullHouse() == true)
		return FULL_HOUSE;
	else if(isFlush() == true)
		return FLUSH;
	else if(isStraight() == true)
		return STRAIGHT;
	else if(isThreeOfAKind() == true)
		return THREE_OF_A_KIND;
	else if(isTwoPair() == true)
		return TWO_PAIR;
	else if(isOnePair() == true)
		return ONE_PAIR;
	else
		return OTHER;
}

// return the number of cards at hand
void
SHPlayer::getNumCards(int k,int a) //const
{
   	cards[k].setID(a);
	//return cards[k].getID();
}

void
SHPlayer::sortCards() 
{
	Card temp;
	for(int i=0;i<5;i++){
	sortedCards[i] = cards[i];
	}
	for(int i=0;i<4;i++){
		for(int j=i+1;j<5;j++){
			if(sortedCards[i].getID() > sortedCards[j].getID()){
				temp = sortedCards[i];
				sortedCards[i] = sortedCards[j];
				sortedCards[j] = temp;
			}

		}
	}		
}

// any five card sequence of same suit
bool 
SHPlayer::isStraightFlush() const
{
	int count=0;
	if(sortedCards[0].getSuit() == sortedCards[1].getSuit() && 
			sortedCards[1].getSuit() == sortedCards[2].getSuit() &&
			sortedCards[2].getSuit() == sortedCards[3].getSuit() && 
			sortedCards[3].getSuit() == sortedCards[4].getSuit() 
			){
		count++;
	}
	for(int i = 0;i < 4;i++){
		if(sortedCards[i].getPip() == sortedCards[i+1].getPip() - 1)
			count++;
	}
	if(count == 5){
		return true;
	}
	else if(count != 5){
		return false;
	}
}

// four cards of the same pip
bool 
SHPlayer::isFourOfAKind() const
{
    // O O O O X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() &&
            sortedCards[0].getPip() == sortedCards[2].getPip() )
        return true;
    // X O O O O
    if( sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() &&
            sortedCards[1].getPip() == sortedCards[3].getPip() )
        return true;

    return false;
}

// three of a kind combined with a pair
bool 
SHPlayer::isFullHouse() const
{
    // O O O X X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;
    // X X X O O
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;

    return false;
}

// five cards of the same suit
bool
SHPlayer::isFlush() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getSuit() != sortedCards[i+1].getSuit() )
            return false;

    return true;
}

// five cards in sequence
bool 
SHPlayer::isStraight() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getPip() + 1 != sortedCards[i+1].getPip() )
            return false;

    return true;
}

// three cards of the same pip
bool 
SHPlayer::isThreeOfAKind() const
{
    for( int i = 0; i < kMaxCards - 2; i++ )
        if( sortedCards[i].getPip() == sortedCards[i+1].getPip() &&
                sortedCards[i].getPip() == sortedCards[i+2].getPip() )
            return true;

    return false;
}

// two cards of one pip, two cards of another pip
bool 
SHPlayer::isTwoPair() const
{
    // O O @ @ X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() )
        return true;
    // O O X @ @
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;
    // X O O @ @
    if( sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;

    return false;
}

// two cards of one pip
bool 
SHPlayer::isOnePair() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getPip() == sortedCards[i+1].getPip() )
            return true;

    return false;
}


