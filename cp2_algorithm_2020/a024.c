#include <stdio.h>
int main(){
	int skyline[10001] = {0};
	int l,h,r;
	int maxLen = 0;
	int outputSpace = 0;
	int i;
	while(scanf("%d %d %d",&l,&h,&r) != EOF){
		for(i=l;i<r;i++){
			if(h>skyline[i]){skyline[i] = h;}
		}
		if(r>maxLen){maxLen = r;}
	}

	for(i=1;i<=maxLen;i++)
		if(skyline[i-1] != skyline[i]){
			if(outputSpace) printf(" ");
			outputSpace = 1;
			printf("%d %d",i,skyline[i]);
		}

	printf("\n");

	return 0;
}

