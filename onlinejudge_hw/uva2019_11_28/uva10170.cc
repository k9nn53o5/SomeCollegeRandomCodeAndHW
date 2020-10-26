#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int main(){
	long int S,D;
	while(scanf("%ld %ld",&S,&D) != EOF){
//		printf("S D: %ld %ld\n",S,D);
//		long int groupSize = S;
//		long int n=1;
		while(D-S > 0){
			D = D - S;
			S = S + 1;
		}
		printf("%ld\n",S);
	}

	return 0;
}
