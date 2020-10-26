#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

void charArr2Vector(vector<int>& k,char* digitCh){
	for(int j=0;digitCh[j]!='\0';j++){
		k.insert(k.begin(),1,digitCh[j]-'0');
	}
}
void printLargeNum(vector<int>& k){
	for(int j=k.size()-1;j>=0;j--){
		cout<<k[j];
	}
}
int cmpVecNum(vector<int>& no1,vector<int>& no2){
	if(no1.size() != no2.size()){
		return no1.size() > no2.size() ? 1 : -1;
	}
	else{
		for(int i=0;i<no1.size();i++){
			if(no1[i] != no2[i]){
				return no1[i] > no2[i] ? 1 : -1;
			}
		}
	}
	return 0;
}

void mulADigit(vector<int>& a){
	
}

void power(vector<int>& a){
	vector<int> result;
	int digit;
	int tmp=0;
	
}
//use binary search sperit to hit target

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		long int p;
		char digitCh[101];
		scanf("%ld\n",&p);
		scanf("%[^\n]",digitCh);
		getchar();
		vector<int> k;
		charArr2Vector(k,digitCh);		
		
		cout<<endl;
	}
	return 0;
}
