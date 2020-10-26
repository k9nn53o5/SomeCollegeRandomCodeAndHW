#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main(){


	while(1){

		char aStr[1000];
		char bStr[1000];		
		int StrMatchPo[1000];
		
		for(int i = 0;i<1000;i++){
			aStr[i]='\0';
			bStr[i]='\0';
			StrMatchPo[i]=0;
		}

		if(!gets(aStr)){
			break;
		}
		gets(bStr);

	//	cout<<aStr<<" "<<bStr<<endl;;
	/*
		for(int i=0;i<1000;i++){
			printf("%c",aStr[i]);
		}
	*/
		for(int i1=0;i1<1000;i1++){
			for(int i2=0;i2<1000;i2++){
				if(aStr[i1] == bStr[i2] && aStr[i1] >= 97 && aStr[i1] <= 122 &&               StrMatchPo[i2] == 0){
					StrMatchPo[i2] = 1;
					break;
				}
			}
		}
		char output[1000];
		for(int k=0;k<1000;k++){
			output[k]='\0';
			if(StrMatchPo[k] == 1){
				output[k] = bStr[k];
			}
		}
		sort(output,output+1000);
		for(int k=0;k<1000;k++){
			printf("%c",output[k]);
		}
		printf("\n");

	}

	return 0;
}
