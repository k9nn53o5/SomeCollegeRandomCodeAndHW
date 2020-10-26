#include <iostream>
#include <cstdio>
#include <cstdlib>
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
	/*
	   int comNum=0;
	   if(totalL>totalR){
	   comNum = countDifCombination(totalL,delNo);
	   }
	   else{
	   comNum = countDifCombination(totalR,delNo);
	   }
	 */
	// state 0 -> cotinue '(' ; 1 -> continue ')' in the segment ; 2 -> ')' then '('
	int state=0;
	int nowLbracketsNo=0,nowRbracketsNo=0;

	int curDiff=0;	

	int id=-1;

	if(strlen == 1){
		cout<<1;
		return 0;
	}


	if(delNo>0){
		result = factorial(totalL);

	}
	else if(delNo<0){
		result = factorial(totalR);
	}

	int curdup=0;
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
				nowLbracketsNo=0;
				nowRbracketsNo=0;
				state=0;
			}
			str[i]=='(' ? nowLbracketsNo++ : nowRbracketsNo++ ;

		}
		if(curDiff == delNo){
			id = i;
			break;
		}

	}
	if(id == -1){
		curDiff += nowLbracketsNo-nowRbracketsNo;
	}

	cout<<result;
	/*
	   for (int i = 0; i < n; ++i)
	   putchar(str[i]);

	   putchar('\n'); 
	 */

	return 0;
}
