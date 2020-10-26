#include <stdio.h>
#include <limits.h>

int main(){
	int arr[100000] = {0};
	int dp[100000] = {0};
	int length=0,tmp=0;
	char space;

	while(scanf("%d",&tmp) != EOF){
		arr[length] = tmp;
		length++;
	}
	
	int i,j,k;
	int maxSumSoFar=0;
	int Max=0;
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			if(arr[ (j+length-i)%length ] + maxSumSoFar > 0){
				maxSumSoFar = arr[(j+length-i)%length] + maxSumSoFar;
				dp[j] = maxSumSoFar;			
			}
			else{
				maxSumSoFar = 0;
				dp[j] = 0;
			}
		}
		
		for(k=0;k<length;k++){
			if(Max < dp[k]){
				Max = dp[k];
			}		
		}
	
		for(k=0;k<length;k++){
			dp[k]=0;
		}
		maxSumSoFar = 0;
	}
	printf("%d",Max);
	
	return 0;
}
