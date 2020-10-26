#include <cstdio>
#include <string>
#include <map>
#include <bits/stdc++.h>
using namespace std;

void showstack(stack <int> s) 
{ 
	while (!s.empty()) 
	{ 
		cout << '\t' << s.top(); 
		s.pop(); 
	} 
	cout << '\n'; 
}



int priority(char opr){
	if(opr=='*' || opr=='/')return 2;
	else if(opr=='+' || opr=='-')return 1;
	else return 0;
}

void str2PostOrder(char* inputStrPtr){
	stack <char> s ;
	int index = 0;
	char ans[1000];
	for(int i = 0 ; *inputStrPtr != '\0' ;i++){
		char opr = *inputStrPtr;
		//if(opr.length() > 1)i+= (opr.length()-1);
		
		if(opr=='+' || opr=='-' || opr=='*' || opr=='/' || opr=='^' ){
			while(s.size() != 0 && priority(opr) <= priority(s.top())){
				ans[index++] = s.top();
				s.pop();
			}
			s.push(opr);
		}
		else if(opr == '('){
			s.push(opr);
		}
		else if(opr == ')'){
			char  tempS ;
			tempS = s.top();
			s.pop();
			while(s.size() !=  0 && !tempS == '(' ){
				ans[index++] = tempS;
			}
		}
		else if(opr == ' '){

		}
		else{
			ans[index++] =opr;
		}
		inputStrPtr++;
	}
	while(s.size() != 0){
		ans[index++] = s.top();
		s.pop();
	}
	cout << ans;
}

int main(){
	char inputStr[];
	char* inputStrPtr = inputStr;
	while(scanf("%[^\n]",inputStr)!=EOF){
		getchar();
		
		/*
		for(;*inputStrPtr != '\0';){
			printf("%c",*inputStrPtr);
			inputStrPtr++;
		}
		for(int i=0;i<1000;i++){
			inputStr[i] = '\0';
		}
		*/
		//inputStrPtr = inputStr;
		str2PostOrder(inputStrPtr);
		//int result = calculateStack();
	}
	return 0;
}
