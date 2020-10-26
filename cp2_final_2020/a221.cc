#include <cstdio>

int main(){
	int N;
	scanf("%d",&N);
	int dp[38];
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<38;i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		printf("%d\n",dp[tmp]);
	}

	return 0;
}
