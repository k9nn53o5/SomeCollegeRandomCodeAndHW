#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;



int main(){
	int caseNum;
	scanf("%d\n",&caseNum);
	for(int i=0;i<caseNum;i++){
		int trainLen;
		int Arr[50];
		for(int j=0;j<50;j++){
			Arr[j]=0;
		}

		scanf("%d\n",&trainLen);
		for(int j=0;j<trainLen;j++){
			scanf("%d",&Arr[j]);
		}

		int swapCounter=0;
		for(int j=0;j<trainLen-1;j++){
			for(int k=0;k<trainLen-1-j;k++){
				if(Arr[k] > Arr[k+1]){
					int tmp = Arr[k];
					Arr[k] = Arr[k+1];
					Arr[k+1] = tmp;

					swapCounter++;
				}
			}
		}
/*
		for(int j=0;j<trainLen;j++){
			printf("%d ",Arr[j]);
		}
		printf("\n");
		printf("%d\n",swapCounter);
	*/
		printf("Optimal train swapping takes %d swaps.\n",swapCounter);
		}
	return 0;
}
