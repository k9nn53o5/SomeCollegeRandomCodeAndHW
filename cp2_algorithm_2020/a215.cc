#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int dX[4] = { 1, 0 , 0, -1};
int dY[4] = { 0, 1 , -1, 0};

int n, m;
bool matrix[12][12];
int counter,result;
int nXm;

void init();
void pruning(int curX, int curY);

int main(){
	while(scanf("%d %d",&m,&n) != EOF){
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) {
				matrix[i][j] = true;
			   	counter++;
				pruning(j,i);
				matrix[i][j] = false; 
				counter--;
			}
		}

		result/=2;
		printf("%d\n",result);
	}
	return 0;
}


void init() {
	nXm = n*m;
	result = 0;
	counter = 0;

	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			matrix[i][j] = false;
		}
	}

	for(int i=0;i<=n+1;i++){
		matrix[i][0] = true;
		matrix[i][m+1] = true;
	}
	for(int i=0;i<=m+1;i++){
		matrix[0][i] = true;
		matrix[n+1][i] = true;
	}
}
void pruning(int curX, int curY){
	// all the elements are visit , it is one of the path
	if(counter == nXm){
		result++;
		return;
	}
	int tmpX, tmpY;

	//check down left up right
	for(int i = 0; i < 4; ++i){
		tmpX = curX + dX[i]; 
		tmpY = curY + dY[i];
		if(matrix[tmpY][tmpX] == false){
			matrix[tmpY][tmpX] = true;
			counter++;
			pruning(tmpX, tmpY);
			matrix[tmpY][tmpX] = false;
		   	counter--;
		}
	}
}
