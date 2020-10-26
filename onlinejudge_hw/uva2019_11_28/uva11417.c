#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int GCD(int i,int j){
	while(1){
		if(i<j){
			if(j%i == 0){return i;}
			j = j%i;
		}
		else if(i>j){
			if(i%j == 0){return j;}
			i = i%j;
		}
		else{
			return i;
		}
	}
}
int main(){
	int N;
	while(scanf("%d\n",&N) != EOF){
		if(N == 0){break;}
		int i,j;
		int G=0;
		for(i=1;i<N;i++){
			for(j=i+1;j<=N;j++){
				G += GCD(i,j);
			}
		}
		printf("%d\n",G);
	}
	
	return 0;
}
