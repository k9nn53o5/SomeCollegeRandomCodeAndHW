#include <iostream>
#include <cstdio>
using namespace std;

int dp[70000000]= {0};//1 2 3 5 8 13 21 ...

int dec2fib(int inputNum){
	int l=0;
	while(l<70000000){
		if(dp[l] == 0){
			if(l==0){dp[l] = 1;}
			else if(l==1){dp[l] = 2;}
			else{dp[l] = dp[l-1]+dp[l-2];}
		}
		else{
			if(inputNum < dp[l]){
				break;
			}
			l++;	
		}
	}
	int firNoIndex = l-1;
	int d2fNum = 0;
	for(int i=0;i<=firNoIndex;i++){
		if(inputNum >= dp[ firNoIndex-i ]){
			d2fNum = d2fNum*10 + 1;
			inputNum = inputNum - dp[ firNoIndex-i ];
		}
		else{
			d2fNum = d2fNum*10;
		}
	}

	return d2fNum;
}


int main(){
	int lineNum=0;
	int inputNum;
	cin>>lineNum;
	for(int i=0;i<lineNum;i++){
		cin>>inputNum;
		cout<<inputNum<<" = "<< dec2fib(inputNum) <<" (fib)"<<endl;	
	}
	return 0;
}
