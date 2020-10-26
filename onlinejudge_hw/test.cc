#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int a,b,c,d1,d2,d3;
	double e1,e2,e3;
	while(scanf("%d",&a)){
		if(a==-1){
			break;
		}
		else{
			scanf("%d",&b);
			scanf("%d",&c);
			scanf("%d %d %d",&d1,&d2,&d3);
			scanf("%f %f %f",&e1,&e2,&e3);
		}
		printf("a %d\nb %d \nc %d\nd1 d2 d3 %d %d %d\ne1 e2 e3 %f %f %f\n",a,b,c,d1,d2,d3,e1,e2,e3);

	}
	cout<<endl<<"end";
	return 0;
}
