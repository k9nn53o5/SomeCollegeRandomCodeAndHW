#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

#define arrLen 10005


int modNum;
int sortArr[arrLen];



bool sortRule(int a,int b){
	// a < b ? true / false
	if(a == b){return true;}
	else if(a%modNum > b%modNum || a%modNum < b%modNum){
		return a%modNum < b%modNum ;//?  true : false;
	}
	else{
		// a%mod = b%mod
		if(a%2 == 0 && b%2 == 0){
			return a < b ;//? true : false;
		}
		else if(a%2 == 1 && b%2 == 1){
			return a > b ;//? false : true;
		}
		else{
			return a%2 == 1 ;//? true: false;
		}
	}	
}
/*
   void sort(int* arrPtr,int modNum,int pairNum){
   for(int i=0;i<pairNum-1;i++){
   for(int j=0;j<pairNum-1-i;j++){
   if(sortRule(arrPtr[j],arrPtr[j+1],modNum)){
   int temp = arrPtr[j];
   arrPtr[j] = arrPtr[j+1];
   arrPtr[j+1] = temp;				
   }
   }

   }	
   }

 */
int main(){

	while(1){
		int pairNum;
		scanf("%d %d",&pairNum,&modNum);
		if(pairNum == 0 && modNum == 0){break;}

		for(int i=0;i<arrLen;i++){
			sortArr[i]=1e9;
		}

		for(int i=0;i<pairNum;i++){
			scanf("%d",&sortArr[i]);
		}

		//int *sortArrPtr = sortArr;
		sort(sortArr, sortArr+pairNum, sortRule);
		printf("%d %d\n",pairNum,modNum);
		for(int i=0;i<pairNum;i++){
			printf("%d\n",sortArr[i]);
		}
	}
	printf("%d %d\n",0,0);
	return 0;
}

