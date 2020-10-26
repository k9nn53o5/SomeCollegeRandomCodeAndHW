#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int caseNum;
	scanf("%d\n",&caseNum);
	for(int i=0;i<caseNum;i++){

		int lineNum,charNum,poNum;
		char Matrix[100][100];
		char point2DArray[21][2];

		scanf("%d %d %d\n",&lineNum,&charNum,&poNum);
		printf("%d %d %d\n",lineNum,charNum,poNum);
		for(int j=0;j<lineNum;j++){
			for(int k=0;k<charNum;k++){
				scanf("%c",&Matrix[j][k]);
			}
			scanf("\n");
		}
		for(int j=0;j<poNum;j++){
			scanf("%d %d\n",&point2DArray[j][0],&point2DArray[j][1]);
		}
		for(int j=0;j<poNum;j++){
			int maxK = min(  min(point2DArray[j][0]-0,lineNum-1-point2DArray[j][0]),           min(point2DArray[j][1]-0,charNum-1-point2DArray[j][1])  );
			int maxSquareN=0;
			int isNFlag=1;
			for(int k=0;k<=maxK;k++){

				for(int l=point2DArray[j][0]-k;l<=point2DArray[j][0]+k;l++){
					for(int m=point2DArray[j][1]-k;m<=point2DArray[j][1]+k;m++){
						
						if( Matrix[l][m] != Matrix[point2DArray[j][0]][point2DArray[j][1]]){
							isNFlag=0;
						}
					}
				}
				if(isNFlag){
					maxSquareN = 2*k+1;
				}
				else{
					break;
				}
			}
			printf("%d\n",maxSquareN);
		}

	}
	return 0;
}
