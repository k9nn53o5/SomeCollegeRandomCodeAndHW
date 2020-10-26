#include <stdio.h>

int summation(int n){
	if(n==1){
		return 1;
	}
	else{
		return summation(n-1)+n;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	printf("The Summation of 1 to n is: %d",summation(n));
	return 0;
}
