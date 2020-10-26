#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

//cdefgabCDEFGAB => 0123...
int c[11]={0,0,1,1,1,0,0,1,1,1,1};
int d[11]={0,0,1,1,1,0,0,1,1,1,0};
int e[11]={0,0,1,1,1,0,0,1,1,0,0};
int f[11]={0,0,1,1,1,0,0,1,0,0,0};
int g[11]={0,0,1,1,1,0,0,0,0,0,0};
int a[11]={0,0,1,1,0,0,0,0,0,0,0};
int b[11]={0,0,1,0,0,0,0,0,0,0,0};
int C[11]={0,0,0,1,0,0,0,0,0,0,0};
int D[11]={0,1,1,1,1,0,0,1,1,1,0};
int E[11]={0,1,1,1,1,0,0,1,1,0,0};
int F[11]={0,1,1,1,1,0,0,1,0,0,0};
int G[11]={0,1,1,1,1,0,0,0,0,0,0};
int A[11]={0,1,1,1,0,0,0,0,0,0,0};
int B[11]={0,1,1,0,0,0,0,0,0,0,0};

int main(){
	int caseNum;
	int* finger[14] = {a,b,c,d,e,f,g,A,B,C,D,E,F,G};


	scanf("%d\n",&caseNum);
	for(int i=0;i<caseNum;i++){		
		char song[200];
		int fingerRecord[11]={0};
		int lastfingerIndex=-1;
		for(int j=0;j<200;j++){
			song[j]='\0';
		}
		scanf("%s\n",song);

//		cout<<song<<endl;

		for(int j=0;j<200;j++){
			if( song[j]>=97 && song[j]<=103  ){
				if(lastfingerIndex == -1){
					for(int k=1;k<11;k++){
						if(finger[song[j]-97][k] == 1){
							fingerRecord[k]++;
						}
					}

					lastfingerIndex = song[j]-97;
				}
				else{
					for(int k=1;k<11;k++){
						if(finger[song[j]-97][k] == 1 && finger[lastfingerIndex][k]==0){
							fingerRecord[k]++;
						}
					}	

					lastfingerIndex = song[j]-97;
				}				
			}
			else if( song[j]>=65 && song[j]<=71 ){
				if(lastfingerIndex == -1){
					for(int k=1;k<11;k++){
						if(finger[song[j]-65+7][k] == 1){
							fingerRecord[k]++;
						}
					}

					lastfingerIndex = song[j]-65+7;
				}
				else{
					for(int k=1;k<11;k++){
						if(finger[song[j]-65+7][k] == 1 && finger[lastfingerIndex][k]==0){
							fingerRecord[k]++;
						}
					}	
					lastfingerIndex = song[j]-65+7;
				}				
			}
		}

		for(int l=1;l<11;l++){
			cout<<fingerRecord[l]<<" ";
		}
		cout<<endl;		
	}
	return 0;
}
