#include <iostream>
#include "GamePlay.h"
#include "Rand.h"

using namespace std;

void Game::print(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout << arr[i][j].value;
		}
		cout<<endl;
	}
	
}

void Game::keypress(char){
		
}

void Game::createEle(int x,int y,int a){
	arr[x][y].value = a;
}

int Game::endjudge(){
// arr is full of element and all of them can't add the  element next to them
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(arr[i][j].value == 0){  // arr is not full 
				return 0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(arr[i][j].value == arr[i][j+1].value){
				return 0;
	//arr is full but still have element can add
			}
		}
	}
	for(int j=0;j<4;j++){
		for(int i=0;i<3;i++){
			if(arr[i][j].value == arr[i+1][j].value){
				return 0;
	//arr is full but still have element can add
			}
		}	
	}
// get 2048 and win
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(arr[i][j].value == 2048){
				return 1; 
			}
		}
	}

	return 2; // arr is full and no element can add


}

void Game::elementmove(){
			
}

int Game::giveEleValue(){
	return 0;
}
