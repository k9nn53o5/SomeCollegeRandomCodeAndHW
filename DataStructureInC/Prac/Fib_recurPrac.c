#include <stdio.h>

int Fib_recursive(int n){
	if(n==1 || n==2){
		return 1;
	}
	else{
		return Fib_recursive(n-1)+Fib_recursive(n-2);
	}
}

int Fib_iterative(int n){
	int pre=1,now=1;
	int temp;
	for(int i=0;i<n-2;i++){
		temp = now;
		now = pre+now;
		pre = temp;
	}
	return now;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("The Answer Of Fib_recursive() is %d\n",Fib_recursive(n));
	printf("The Answer Of Fib_iterative() is %d\n",Fib_iterative(n));
	return 0;
}
