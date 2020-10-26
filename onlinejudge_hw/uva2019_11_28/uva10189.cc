#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
	int N,M;
	while(scanf("%d %d\n",&N,&M)){
		if(N==0&&M==0){break;}
		if(N==0||M==0){continue;}
		
		string aRow;
		int graph[100][100];
		for(int i=0;i<N;i++){
			getline(cin,aRow);
			for(int j=0;j<aRow.length();j++){
				if(aRow[j] == '.'){	
					graph[i][j] = 0;
				}
				else if(aRow[j] == '*'){
					graph[i][j] = -1;
				}
				else{
					printf("graph error not * .\n");
				}
			}
			aRow.clear();
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(graph[i][j] == -1){
					for(int k = i-1;k<=i+1;k++){
						for(int l=j-1;l<=j+1;l++){
							if(k>=0 && k<N && l>=0 && l<M && graph[k][l] != -1){
								graph[k][l]++;
							}
						}

					}

				}
			}
		}

		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				printf("%2d ",graph[i][j]);
			}
			printf("\n");
		}
		
		
	}
	
	return 0;
}
