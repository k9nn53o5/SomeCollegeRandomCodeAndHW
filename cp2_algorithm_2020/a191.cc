#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int main(){
	int N;
	int matrix[100][100];
	int dp[100][100] = {0};
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			matrix[i][j] = INT_MAX;
			dp[i][j] = INT_MAX;
		}
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&matrix[i][j]);
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i!=0 && j!= 0){
				dp[i][j] = matrix[i][j] +  dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];	
			}
			else if(i==0 && j!= 0){
				dp[i][j] = matrix[i][j] + dp[i][j-1];
			}
			else if(j==0 && i!=0){
				dp[i][j] = matrix[i][j] + dp[i-1][j];
			}
			else{
				dp[i][j] = matrix[i][j];
			}

		}
	}
	int max=0;
	for(int rightCol=0;rightCol<N;rightCol++){
		for(int leftCol=0;leftCol<=rightCol;leftCol++){
			for(int highRow=0;highRow<N;highRow++){
				for(int lowRow=0;lowRow<=highRow;lowRow++){
					if(rightCol == leftCol && highRow == lowRow){
						max = (dp[rightCol][lowRow] > max) ? 
							dp[rightCol][lowRow] :
							max;
					}	
					else if (rightCol == leftCol && highRow != lowRow){
						max = (dp[rightCol][highRow]-dp[leftCol][lowRow] > max) ? 
							dp[rightCol][highRow]-dp[leftCol][lowRow] : 
							max;
					}
					else if (rightCol != leftCol && highRow == lowRow){
						max = (dp[rightCol][highRow]-dp[leftCol][lowRow] > max) ?
							dp[rightCol][highRow]-dp[leftCol][lowRow] :
							max;
					}
					else{
						max = 
							(dp[rightCol][highRow]-dp[rightCol][lowRow]-dp[leftCol][highRow]
							 +dp[leftCol][lowRow] > max) ?
							dp[rightCol][highRow]-dp[rightCol][lowRow]-dp[leftCol][highRow]
							+dp[leftCol][lowRow] :
							max	; 
					}
				}
			}
		}
	}
	/*
	   for(int i=0;i<N;i++){
	   for(int j=0;j<N;j++){
	   cout<<dp[i][j]<<" ";
	   }
	   cout<<endl;
	   }
	 */
	cout<<max;

	return 0;
}

