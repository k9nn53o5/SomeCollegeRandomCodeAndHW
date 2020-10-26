#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;


int main(){
	string aLine;

	int isFirstDoubleQuoteFlag=1;
	while(getline(cin,aLine)){

//		cout<<aLine<<endl;
		for(int i=0;i<aLine.length();i++){
			if(aLine[i] == 34){
				if(isFirstDoubleQuoteFlag == 1){
					printf("``");
					isFirstDoubleQuoteFlag=0;
				}
				else if(isFirstDoubleQuoteFlag == 0){
					printf("\'\'");
					isFirstDoubleQuoteFlag=1;
				}
			}
			else{
				printf("%c",aLine.at(i));
			}
		}
		printf("\n");
	}

	return 0;
}
