#include <cstdio>

int isFactor(int x,int y){
	if(x%y == 0){
		return 1;
	}
	return 0;
}
int main(){
	while(1){
		int L,W,X,Y;
		scanf("%d %d %d %d",&L,&W,&X,&Y);
		
		if(L==0&&W==0&&X==0&&Y==0){
			break;
		}
		
		if(isFactor(L,X)&&isFactor(W,Y) || isFactor(W,X)&&isFactor(L,Y)){
			printf("%d\n",(L*W)/(X*Y));	
			continue;	
		}
		printf("-1\n");
	
		//printf("%d %d %d %d\n",isFactor(L,X),isFactor(L,Y),isFactor(W,X),isFactor(W,Y));

	};

	return 0;
}
