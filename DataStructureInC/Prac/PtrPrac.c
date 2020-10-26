#include <stdio.h>
#include <stdlib.h>

int main(){
	float *fPtr = (float*)malloc(8*sizeof(float));
	for(int i=0;i<8;i++){
		printf("Plz enter a float:");
		scanf("%f",fPtr);
		printf("\nThe content of fPtr is %f",*fPtr);
		printf("\nThe address of fPtr is %p",fPtr);
		printf("\n");
		fPtr++;
	}
	free(fPtr);

	return 0;
}
