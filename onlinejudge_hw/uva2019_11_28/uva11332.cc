#include <iostream>
#include <cstdio>

using namespace std;

int dp[200000];


void updateDP(int inputNum){
	if(dp[inputNum] != 0){return;}

	if(inputNum >= 1 && inputNum <= 9){
		dp[inputNum] = inputNum;
		return;
	}
	else{
		int inputNum_1 = inputNum;
		int newinputNum=0;
		while(inputNum_1){
			newinputNum += (inputNum_1%10);
			inputNum_1 = inputNum_1 / 10;
		}
		if(dp[newinputNum] != 0){
			dp[inputNum] = dp[newinputNum];
			return;
		}
		else{
			updateDP(newinputNum);
			dp[inputNum] = dp[newinputNum];
			return;
		}
	}
}

int main(){
	int inputNum;
	do{
		scanf("%d",&inputNum);
		if(inputNum == 0){break;}
		
		while(inputNum >= 200000){
			int temp=0;
			while(inputNum){
				temp += (inputNum%10);
				inputNum = inputNum / 10;
			}
			inputNum = temp;
		}
		
		if(dp[inputNum] == 0){
			updateDP(inputNum);
		}

		cout<<dp[inputNum]<<endl;
	}while(1);

	return 0;
}
