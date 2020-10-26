#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;

#define EMPTY 10e-8

int main(){
	int n;
	int numArr[3000];
	int diffArr[3000];
	int* diffArrptr;
	for(int i=0;i<3000;i++){
		numArr[i]=EMPTY;
		diffArr[i]=EMPTY;
	}

	while(scanf("%d ",&n) != EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&numArr[i]);
		}
		for(int i=0;i<n-1;i++){
			diffArr[i]=abs(numArr[i]-numArr[i+1]);
		}
		diffArrptr = diffArr;

		sort(diffArrptr,diffArrptr+n-1);
		/*	
		for(int i=0;i<n-1;i++){
			cout<<diffArr[i]<<" ";
		}
		printf("\n");
		*/
		int isJolly=1;
		for(int i=0;i<n-1;i++){
			if(diffArr[i] != i+1){
				isJolly=0;
			}
		}
		if(isJolly==1){
			printf("Jolly\n");
		}
		else{
			printf("Not jolly\n");
		}
		
		for(int i=0;i<3000;i++){
			numArr[i]=EMPTY;
			diffArr[i]=EMPTY;
		}

	}
	return 0;
}
