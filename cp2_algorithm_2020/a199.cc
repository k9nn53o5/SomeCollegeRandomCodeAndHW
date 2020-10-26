#include <cstdio>
#include <vector>
using namespace std;
int playResult(int k,vector<int> &pool){
	/*
	if(pool.size() == 1){
		return pool[0] > k ? 1 : 0; 
	}
	*/
	for(int i=0;i<pool.size();i++){
		if(pool[i] >= k){return 1;}
		else if(pool[i] < k){return 0;}

		vector<int> newPool = pool;
		newPool.erase(newPool.begin()+i);
		if(playResult(k-pool[i],newPool) == 0){
			return 1;
		}
	}
	return 0;
}
/*
void initSum(int k,int* pool,int** dp){
	for(int i=0;i<k;i++){
		pool[i] = i;
		for(int j=0;j<k;j++){
			dp[i][j]=-1;
		}
	}
}
*/
int main(){
	int n,k;
	while(scanf("%d\n%d",&n,&k) != EOF){
		vector<int> pool;
		for(int i=0;i<n;i++){
			pool.push_back(i+1);
		}
		if(playResult(k,pool)==1){
			printf("True\n");
		}
		else{
			printf("False\n");
		}
	}
	return 0;
}
