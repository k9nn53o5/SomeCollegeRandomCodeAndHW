#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647

map<int,int> DPmap;

int countMinAssemble(vector<int> &coinArr,int targetAmount);

int main(){
	int lineNum;
	cin>>lineNum;
	for(int i=0;i<lineNum;i++){
		int coinCategoryNum,targetAmount,result;
		vector<int> coinArr;
		cin>>coinCategoryNum>>targetAmount;
		for(int j=0;j<coinCategoryNum;j++){
			int tmp;
			cin>>tmp;
			coinArr.push_back(tmp);
		}
		sort(coinArr.begin(),coinArr.end());
		result = countMinAssemble(coinArr,targetAmount);
		cout<<result<<"\n";
		DPmap.clear();
	}
	return 0;
}

int countMinAssemble(vector<int> &coinArr,int targetAmount){
	//targetAmount in DPmap
	if(DPmap.find(targetAmount) != DPmap.end()){
		return DPmap.find(targetAmount)->second;
	}
	
	//targetAmount not in DPmap
	//fill DPmap
	int min=INT_MAX;
	int haveNoMinCounter=0;
	for(int i=0;i<coinArr.size();i++){
		if(coinArr[i] > targetAmount && haveNoMinCounter < coinArr.size()){
		//coinArr[i] > targetAmount
			haveNoMinCounter++;
		}
		else if(coinArr[i] > targetAmount && haveNoMinCounter == coinArr.size()){
			DPmap.insert(pair<int,int>(targetAmount,-1));
			return -1;
		}
		else if(coinArr[i] == targetAmount){
		//coinArr[i] == targetAmount
			DPmap.insert(pair<int,int>(targetAmount,1));
			return 1;
		}
		else if(countMinAssemble(coinArr,targetAmount-coinArr[i]) == -1){
		//coinArr[i] < targetAmount
			continue;
		}
		else if( min > countMinAssemble(coinArr,targetAmount-coinArr[i])+1){
		//coinArr[i] < targetAmount
			min = countMinAssemble(coinArr,targetAmount-coinArr[i])+1;
		}	
	}

	if(min == INT_MAX){
		//there have no solution of assemble
		DPmap.insert(pair<int,int>(targetAmount,-1));
		return -1;
	}
	//there have a min assemble solution
	DPmap.insert(pair<int,int>(targetAmount,min));
	return min;
}
