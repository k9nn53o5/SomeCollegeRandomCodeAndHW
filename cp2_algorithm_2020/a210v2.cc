#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int factorial(int x){
	int f=1;
	for(int i = 1; i <=x; ++i)
	{
		f *= i;
	}
	return f;
}

int countDifCombination(int l,int r){
	int bNo,sNo;
	int result;
	if(l>r){
		bNo=l;
		sNo=r;
	}
	else{
		bNo=r;
		sNo=l;
	}
	result = factorial(bNo)  /  ( factorial(sNo)*factorial(bNo-sNo) );
	return result;
}
int main(){
	char str[36];
	int ch, n = 0;

	while ((ch = getchar()) != EOF && n < 36) {
		if(ch == '(' || ch == ')'){
			str[n] = ch;
			n++;
		}
	}
	int strlen = n;

	int delNo=0;
	int totalL=0,totalR=0;
	for(int i=0;i<strlen;i++){
		str[i]=='(' ? totalL++ : totalR++;
	}
	delNo = totalL-totalR;

	int state=0;
	int nowLbracketsNo=0,nowRbracketsNo=0;
	int curDiff=0;
	vector<int> dupNumArr;

	int result;
	//result = delNo>0 ? factorial(totalL): factorial(totalR);

	for(int i=0;i<strlen;i++){

		if(i==0){
			str[i]=='(' ? state=0 : state=1;
			str[i]=='(' ? nowLbracketsNo++ : nowRbracketsNo++ ;
		}

		else{
			if(str[i-1] != str[i])
			{
				state++;
			}
			if(state > 1)
			{
				curDiff += nowLbracketsNo-nowRbracketsNo;
				delNo > 0 ? dupNumArr.push_back(nowLbracketsNo) : dupNumArr.push_back(nowRbracketsNo);

				nowLbracketsNo=0;
				nowRbracketsNo=0;
				state=0;
			}
			str[i]=='(' ? nowLbracketsNo++ : nowRbracketsNo++ ;

		}
		if(curDiff == delNo){
			int tmp=0;
			for(int j=0;j<dupNumArr.size();j++){
				tmp+=dupNumArr[i];
			}
			result = factorial(tmp);
			for(int j=0;j<dupNumArr.size();j++){
				result /= factorial(dupNumArr[j]);
			}
			//for(int i=0;i<dupNumArr.size();i++){cout<<dupNumArr[i]<<" ";}
			cout<<result;
			return 0;
			break;
		}

	}

	curDiff += nowLbracketsNo-nowRbracketsNo;
	if(curDiff == delNo){

		int tmp=0;
		for(int j=0;j<dupNumArr.size();j++){
			tmp+=dupNumArr[j];
		}
		result = factorial(tmp);
		for(int j=0;j<dupNumArr.size();j++){
			result /= factorial(dupNumArr[j]);
		}

		//for(int i=0;i<dupNumArr.size();i++){cout<<dupNumArr[i]<<" ";}
		cout<<result;
		return 0;
	}
	for(int i=0;i<dupNumArr.size();i++){cout<<dupNumArr[i]<<" ";}
	cout<<"error";

	return 0;
}
