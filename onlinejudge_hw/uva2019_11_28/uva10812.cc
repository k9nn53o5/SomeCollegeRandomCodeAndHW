#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	int inputPairNum;
	long int sum,diff;
	long int a=0,b=0;

	scanf("%d",&inputPairNum);
	for(int i=0;i<inputPairNum;i++){
		scanf("%ld %ld",&sum,&diff);
		a = (sum + diff) / 2;
		b = (sum - diff) / 2;
		if(a >= 0 && (sum+diff)%2 == 0 && b >= 0 && (sum-diff)%2 == 0){
			printf("%ld %ld\n",a,b);
		}
		else{
			printf("impossible\n");
		}
	}

	return 0;
}
