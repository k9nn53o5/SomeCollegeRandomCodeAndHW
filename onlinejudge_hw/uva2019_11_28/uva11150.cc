#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
	int N=0;
	while(scanf("%d",&N) != EOF){
		int maxTotal=0;	
		for(int k=0;k<=N/2;k++){
			int borrowNum=k;
			int nowNotEmptyBottle=N;
			int nowEmptyBottle=borrowNum;
			int tempLeft=0;
			int totalDrinkBottle =0;

			//		printf("k:%d\n",k);

			do{
				
				if(nowNotEmptyBottle < borrowNum){
					nowNotEmptyBottle=0;
					break;}
				
				nowEmptyBottle += nowNotEmptyBottle;
				totalDrinkBottle += nowNotEmptyBottle;
				nowNotEmptyBottle = 0;

				if(nowEmptyBottle/3 + nowEmptyBottle%3 < borrowNum){
					//nowNotEmptyBottle = (-1) * borrowNum;
					break;
				}

				nowNotEmptyBottle = nowEmptyBottle/3;
				nowEmptyBottle = nowEmptyBottle%3;

//				printf("totalDrinkBottle:%d  ",totalDrinkBottle);


			}while(nowNotEmptyBottle >= 3);

			nowEmptyBottle += nowNotEmptyBottle;
			nowEmptyBottle = nowEmptyBottle - borrowNum;
			totalDrinkBottle += nowNotEmptyBottle;
//			printf("nowNotEmptyBottle:%d  ",nowNotEmptyBottle);
			nowNotEmptyBottle = 0;	

			if(totalDrinkBottle > maxTotal){
				maxTotal = totalDrinkBottle;
				//printf("%d\n",maxTotal);
			}
//			printf("k:%d ->  %d\n",k,maxTotal);
		}
		printf("%d\n",maxTotal);
	}
	return 0;
}
