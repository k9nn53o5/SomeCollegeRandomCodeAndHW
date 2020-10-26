#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int inf = 99999999;
int cutpo[55]={0};
int dparr[55][55];

int dp(int x,int y){
	if(dparr[x][y] > -1){
		return dparr[x][y];
	}	
	if(x == y-1){
		dparr[x][y]=0;
		return 0;
	}
	int ans=inf;
	for(int i=x+1;i<y;i++){
		ans = min(ans,dp(x,i)+dp(i,y));
	}
	dparr[x][y] = ans + cutpo[y]- cutpo[x];
	return dparr[x][y];
}


int main(){
	int l=0,n=0;
	while(cin>>l){
		if(l==0){break;}
		memset(dparr, -1, sizeof(dparr));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cutpo[i];
		}
		cutpo[0]=0; 
		cutpo[n+1]=l;
		/*
		cout<<l<<" "<<n<<endl;
		for(int i=0;i<=n+1;i++){
			cout<<cutpo[i]<<" ";
		}
		cout<<endl;
		*/
		cout<<"The minimum cutting is "<<dp(0,n+1)<<"."<<endl;
		/*
		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				cout<<dparr[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
	}
	return 0;
}
