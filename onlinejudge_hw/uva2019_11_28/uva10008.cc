#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;


int main(){
	int lineNum=0;
	int alphabArr[26]={0};
	scanf("%d\n",&lineNum);
	//printf("1");
	char sentence[2000];
	for(int i=0;i<lineNum;i++){
		gets(sentence);
		for(int j=0;sentence[j];j++){
			if(sentence[j] >= 'a' && sentence[j] <= 'z'){
				alphabArr[ sentence[j]-97 ]++;
			}
			else if(sentence[j] >= 'A' && sentence[j] <= 'Z'){
				alphabArr[ sentence[j]-65 ]++;
			}
		}
		for(int k=0;k<2000;k++){
			sentence[k]=0;
		}
	}
	//printf("2");
/*	
	for(int i=0;i<26;i++){
		cout<<alphabArr[i]<<" ";
	}
	*/
	int maxIndexInAlp=0;
	int nowMaxNum=0;
	int charOutputAlready[26]={0};
	int l;
	for(int i=0;i<26;i++){
		if(alphabArr[i] > nowMaxNum){
			nowMaxNum = alphabArr[i];
		}
	}
	l=nowMaxNum;
	
	while(l){
		for(int i=0;i<26;i++){
			if(alphabArr[i] == l){
			cout<<(char)(i+65)<<" "<<l<<endl;
			}
		}
		l--;
	}

	//printf("3");
	return 0;
}
