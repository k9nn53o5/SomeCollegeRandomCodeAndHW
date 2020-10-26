#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;


int dfs(int l,int r,int** sum2DPtr,int* nsPtr,int N,int** dp2DPtr){
	if(dp2DPtr[l][r] == -1){	
		if(l == r){
			dp2DPtr[l][r] = nsPtr[l];
		}
		else if(abs(l-r) == 1){
			dp2DPtr[l][r] = max(nsPtr[l],nsPtr[r]);
		}
		else{
			dp2DPtr[l+1][r] = dfs(l+1,r,sum2DPtr,nsPtr,N,dp2DPtr);
			dp2DPtr[l][r-1] = dfs(l,r-1,sum2DPtr,nsPtr,N,dp2DPtr);
			dp2DPtr[l][r] =  max(
					sum2DPtr[l+1][r]-dp2DPtr[l+1][r]+nsPtr[l],
					sum2DPtr[l][r-1]-dp2DPtr[l][r-1]+nsPtr[r]
					);
		}
		
	}
	return dp2DPtr[l][r];
}

void initSum(int** sum2DPtr,int* nsPtr,int N,int** dp2DPtr){
	for(int i=0;i<N;i++){
		int tmp=0;
		for(int j=i;j<N;j++){
			tmp += nsPtr[j];
			sum2DPtr[i][j] = tmp;
		}
		for(int k=0;k<N;k++){
			dp2DPtr[i][k]=-1;
		}
	}
}


int main(){
	int N;
	while(scanf("%d",&N) != EOF){
		int ns[N];
		int* nsPtr = ns;

		int sum[N][N]={{0}};
		int dp[N][N]={{0}};
		int* sumPtr[N];
		int* dpPtr[N];
		for(int i=0;i<N;i++){
			sumPtr[i] = sum[i];
			dpPtr[i] = dp[i];
		}
		int** sum2DPtr = sumPtr;
		int** dp2DPtr = dpPtr;

		for(int i=0;i<N;i++){
			scanf("%d",&ns[i]);
		}

		initSum(sum2DPtr,nsPtr,N,dp2DPtr);
		int a = dfs(0,N-1,sum2DPtr,nsPtr,N,dp2DPtr);
		//printf("%d & %d\n",a,sum[0][N-1]-a);
		/*
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}
		*/
		int Apoints = a;
		int Bpoints = sum[0][N-1]-a;

		Apoints >= Bpoints ? printf("True\n") : printf("False\n");

	}

	return 0;
}

