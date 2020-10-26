#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
	int caseNum;
	scanf("%d\n",&caseNum);
	for(int i=0;i<caseNum;i++){
		char str1[31];
		char str2[31];
		for(int j=0;j<31;j++){
			str1[j]='\0';
			str2[j]='\0';
		}
		gets(str1);
		gets(str2);
		int str1Int=0;
		int str2Int=0;
		for(int j=0;j<31;j++){
			if(str1[j] == 48 || str1[j] == 49){
				str1Int = ( str1[j]==48 ? str1Int*2 : str1Int*2+1 );
			}
			if(str2[j] == 48 || str2[j] == 49){
				str2Int = ( str2[j]==48 ? str2Int*2 : str2Int*2+1 );
			}
		}
		int loveFlag=0;
		int strLenMin = min(str1Int,str2Int);
		for(int j = 2;j <= strLenMin;j++){
			if(str1Int%j == 0 && str2Int%j == 0){
				loveFlag=1;			
			}
		}
		/*
		cout<<str1<<" "<<str2<<" "<<endl;
		printf("1:%d 2:%d\n",str1Int,str2Int);
		*/

		printf("Pair #%d: ",i+1);
		if(loveFlag){
			printf("All you need is love!");
		}
		else{
			printf("Love is not all you need!");
		}
		printf("\n");
		
	}

	return 0;
}
