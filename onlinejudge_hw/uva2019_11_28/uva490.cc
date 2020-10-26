#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
using namespace std;

int main(){
	char sentence[101][101];
	int sLength[101];
	int maxL=0;
	int sentenceNum=0;
	int l=0;
	char newSentnece[101][101];
	while(gets(sentence[l])){
		sLength[l] = strlen(sentence[l]);
		l++;
	}
	sentenceNum = l;
	for(int i=0;i<101;i++){
		if(maxL < sLength[i]){
			maxL = sLength[i];
		}	
	}
	for(int i=0;i<maxL;i++){
		for(int j=0;j<sentenceNum;j++){
			if(i >= sLength[sentenceNum-1-j] ){
				printf(" ");
			}
			else{
				printf("%c",sentence[sentenceNum-1-j][i]);
			}
		}
		printf("\n");
	}
	return 0;
}
