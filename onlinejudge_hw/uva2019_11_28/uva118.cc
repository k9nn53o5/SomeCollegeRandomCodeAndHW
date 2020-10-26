#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


char nowDir = 'N';
int nowPo_x = 0;
int nowPo_y = 0;
int outOfBounder=0;

char dirArr[4]={'E','S','W','N'};

int mapBound_x=0;
int mapBound_y=0;

int lostPo2DArr[51][51]={0};

void poChange(){
	char tmpDir = nowDir;
	int tmpX = nowPo_x;
	int tmpY = nowPo_y;
	switch(nowDir){
		case 'E':
			nowPo_x++;
			break;
		case 'S':
			nowPo_y--;
			break;
		case 'W':
			nowPo_x--;
			break;
		case 'N':
			nowPo_y++;
			break;
		default:
			printf("poChange error");
			break;
	}
	//out of bounder
	if(nowPo_x > mapBound_x || nowPo_y > mapBound_y){
		nowDir = tmpDir;
		nowPo_x = tmpX;
		nowPo_y = tmpY;
		if(lostPo2DArr[nowPo_x][nowPo_y] == 1){
			outOfBounder = 0;
		}
		else if(lostPo2DArr[nowPo_x][nowPo_y] == 0){
			lostPo2DArr[nowPo_x][nowPo_y] = 1;
			outOfBounder = 1;
		}
		else{
			printf("checking bounder error");
		}
	}
}

void dirChange(char inputRL){
	int nowDirIndex;
	for(int i=0;i<4;i++){
		if(nowDir == dirArr[i]){
			nowDirIndex = i;
		}
	}
	if(inputRL == 'R'){
		nowDir = dirArr[ (nowDirIndex+1)%4 ];
	}
	else if(inputRL == 'L'){
		nowDir = dirArr[ (4+nowDirIndex-1)%4 ];
	}
	else{
		printf("dir change error");
	}	
}


void robotMoving(char inputChar){
	switch(inputChar){
		case 'F':
			poChange();
			break;
		case 'R':
			dirChange('R');
			break;
		case 'L':
			dirChange('L');
			break;
	}
}

void robotInitial(){
	char nowDir = 'N';
	int nowPo_x = 0;
	int nowPo_y = 0;
}


int main(){
	scanf("%d %d\n",&mapBound_x,&mapBound_y);
	while(scanf("%d %d %c\n",&nowPo_x,&nowPo_y,&nowDir) != EOF){
		printf("2");
		char inputChar;
		while(scanf("%c",&inputChar)){
			robotMoving(inputChar);
		}
		scanf("\n");
		printf("%d %d %c",nowPo_x,nowPo_y,nowDir);
		if(outOfBounder == 1){
			printf(" Lost");
		}		
		printf("\n");
		robotInitial();
	}

	return 0;
}
