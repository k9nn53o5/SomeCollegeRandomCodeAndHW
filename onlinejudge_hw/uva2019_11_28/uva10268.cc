#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	int xValue;
	int polyArr[1000000];
	while(scanf("%d",&xValue) != EOF){
		int l=0;
		int checkChar;
		do{
			scanf("%d",&polyArr[l]);
			l++;
		}while(getchar() != '\n');

		int orderOfPoly=l-1;
		
		int result=0;
		
//		printf("%d\n",orderOfPoly)
		for(int i=0;i<orderOfPoly;i++){
//			printf("%d %d %d\n",orderOfPoly-i,polyArr[i],(int)pow(xValue,orderOfPoly-i-1));
			result+=( (orderOfPoly-i) * polyArr[i] * (int)pow(xValue,orderOfPoly-i-1) );
//			printf("%d\n",result);
		}
		/*
		cout<<xValue<<endl;
			for(int i=0;i<orderOfPoly+1;i++){
				cout<<polyArr[i]<<" ";
			}
			printf("\n");
			*/
			printf("%d\n",result);
	
			}
	return 0;
}
