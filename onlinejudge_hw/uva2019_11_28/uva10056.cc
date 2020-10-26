#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	int S,N,I,X;//S input line num,N student num,I I's student win,X how many round
	float p;
	float q;
	scanf("%d",&S);


	//P(win) = (  q^i * p( 1 - q^(X*N) )   )/ (  1-q^N  )
	//i = I-1

	for(int i=0;i<S;i++){
		scanf("%d %f %d",&N,&p,&I);
		if(p==0){printf("%.4f\n",0.0000);continue;}
		q=1-p;
		X=20;
		printf("%.4f\n",                                                                         (float)( pow(q,I-1) *p*( 1-pow(q,X*N) )  )/( (float)(1-pow(q,N)) ) );     
	}		
	return 0;
}
