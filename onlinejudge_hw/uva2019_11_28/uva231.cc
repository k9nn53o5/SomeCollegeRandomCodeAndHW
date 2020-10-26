#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	// missile height
	vector <int> mish;
	int testnum=0;
	while(1){
		int h;
		cin>>h;
		if(h==-1 && mish.size()==0){
			break;
		}
		else if(h==-1 && mish.size()!=0){
			//compute max height
			/*
			vector<int> temp(mish.size(),0);
			for(int i=mish.size()-1;i>=0;i--){
				temp[mish.size()-1-i]=mish[i];
			}
			for(int i=0;i<mish.size();i++){
				mish[i]=temp[i];
			}
			*/
			vector <int> dp(mish.size(),0);
			for(int i=0;i<=mish.size();i++){
				for(int j=i+1;j<mish.size();j++){
					if(mish[j] <= mish[i] && dp[j]<dp[i]+1){
						dp[j] = dp[i]+1;
					}
				}
			}		
		    int max=0;	
			//print answer
			for(int i=0;i<mish.size();i++){
				if(max<dp[i]){
					max=dp[i];
				}			
			}
			if(testnum)
				puts("");
			printf("Test #%d:\n", ++testnum);
			printf("  maximum possible interceptions: %d\n", max+1);
			/*
			cout<<"Test #"<<testnum<<":\n  maximum possible interceptions: "
				<<max+1<<endl;
			*/
			//clean vector mish
			mish.clear();


		}
		else{
			mish.push_back(h);
		}

	}


	return 0;
} 
