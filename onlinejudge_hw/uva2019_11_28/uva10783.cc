#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

int main(){
	int inputGroupNum=0;
	scanf("%d",&inputGroupNum);
	for(int i=0;i<inputGroupNum;i++){
		int a,b,result=0;
		scanf("%d\n%d\n",&a,&b);
		for(int j=a;j<=b;j++){
			if(j%2 == 1){
				result+=j;
			}
		}
		printf("Case %d: %d\n",i+1,result);
	}
	return 0;
}
