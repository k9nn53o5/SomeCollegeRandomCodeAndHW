#include <iostream>
#include <vector>
using namespace std;
/*
int move(vector<int> puzzleB,int dir){
	//dir: 0 1 2 3 -> up right down left
	switch(dir){
		case 0:
			if(puzzleB[0]==1||puzzleB[1]==2||puzzle[2]==3){return -1;}
			for(int i=0;i<9;i++){ if(puzzleB[i]!=0){puzzleB[i]-=3;}}
			break;
		case 1:
			if(puzzleB[2]==3||puzzleB[5]==6||puzzle[8]==9){return -1;}
			for(int i=0;i<9;i++){ if(puzzleB[i]!=0){puzzleB[i]-=3;}}
			break;
		case 2:
			if(puzzleB[6]==7||puzzleB[7]==8||puzzle[8]==9){return -1;}
			for(int i=0;i<9;i++){ if(puzzleB[i]!=0){puzzleB[i]-=3;}}
			break;
		case 3:
			if(puzzleB[0]==1||puzzleB[3]==4||puzzle[6]==7){return -1;}
			for(int i=0;i<9;i++){ if(puzzleB[i]!=0){puzzleB[i]-=3;}}
			break;		
	}
	return 1;
}
*/
/*
void moveToCenter(vector<int> puzzleB,int po){
	switch(po){
		case 0:
			move(puzzleB,2);
			move(puzzleB,1);			
			break;
		case 1:
			move(puzzleB,2);
			break;
		case 2:
			move(puzzleB,2);
			move(puzzleB,4);
			break;
		case 3:
			move(puzzleB,1);
			break;
		case 4:
			break;
		case 5:
			move(puzzleB,4);
			break;
		case 6:
			move(puzzleB,0);
			move(puzzleB,1);
			break;
		case 7:
			move(puzzleB,0);
			break;
		case 0:
			move(puzzleB,0);
			move(puzzleB,4);
			break;
	}
}
*/
int rotate(vector<int>puzzleB){
	if(puzzleB[0]==0){}
	if(puzzleB[]==0){

	}
	if(puzzleB[]==0){

	}
	if(puzzleB[]==0){

	}
	if(puzzleB[]==0){

	}
	if(puzzleB[]==0){

	}
	if(puzzleB[]==0){

	}
	if(puzzleB[]==0){

	}
	if(puzzleB[]==0){

	}
	if(puzzleB[]==0){

	}
}

int main(){
	vector<int> puzzleA = {1,2,3,4,5,6,7,8,9};
	vector<int> puzzleB = {1,2,3,4,5,6,7,8,9};
	for(int j=0;j<3;j++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a == '.'){
			puzzleA[0+j]=0;
		}
		if(b == '.'){
			puzzleA[1+j]=0;
		}
		if(c == '.'){
			puzzleA[2+j]=0;
		}
	}

	for(int j=0;j<3;j++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a == '.'){
			puzzleB[0+j]=0;
		}
		if(b == '.'){
			puzzleB[1+j]=0;
		}
		if(c == '.'){
			puzzleB[2+j]=0;
		}
	}
	return 0;
}
