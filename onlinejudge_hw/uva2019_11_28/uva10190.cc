#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	long int a,m;
	while(scanf("%d %d\n",&a,&m) != EOF){
		int a_Is_mPowerFlag=0;
		int aTmp=a;
		while(1){
			if(aTmp == 1){
				a_Is_mPowerFlag=1;	
				break;
			}
			else if( aTmp!=1 && aTmp%m!=0){
				break;
			}
			/*
			else if(aTmp != 1 && aTmp < m){
				break;
			}
			*/
			aTmp = aTmp / m;
		}
		if(a_Is_mPowerFlag){
			while(a > 0){
				printf("%d ",a);
				a = a/m;
			}
			printf("\n");
		}
		else{
			printf("Boring!\n");	
		}
	}
	return 0;
}
