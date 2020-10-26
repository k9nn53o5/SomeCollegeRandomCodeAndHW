#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


int main(){
	int caseNum;
	scanf("%d\n",&caseNum);
	for(int i=0;i<caseNum;i++){
		int daysNum,partysNum;
		scanf("%d\n",&daysNum);
		scanf("%d\n",&partysNum);
		int daysArr[3651]={0};
		int partysArr[100]={0};

		for(int j=0;j<partysNum;j++){
			scanf("%d\n",&partysArr[j]);
		}
		for(int j=0;j<partysNum;j++){
			for(int k=0+1;k<daysNum+1;k++){
				if(k%partysArr[j]==0 && k!=0 && k%7!=6 && k%7!=0){
					daysArr[k]++;
				}
			}
		}
		int loseDay=0;
		for(int j=1;j<daysNum+1;j++){
			if(daysArr[j]>0){
				loseDay++;
			}
		}
		/*
		for(int j=0;j<daysNum;j++){
			cout<<daysArr[j]<<" ";
		}
		*/
		printf("%d\n",loseDay);

	}

	return 0;
}
