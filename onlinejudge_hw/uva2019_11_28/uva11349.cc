#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	int caseNum;
	scanf("%d\n",&caseNum);
	for(int i=0;i<caseNum;i++){
		int nDimension;
		long int Matrix[100][100];
		long int cmpMatrix[100][100];
		for(int j3=0;j3<100;j3++){
			for(int j4=0;j4<100;j4++){
				Matrix[j3][j4] = -1;
				cmpMatrix[j3][j4] = -1;
			}
		}

		scanf("N = %d\n",&nDimension);
		for(int j1=0;j1<nDimension;j1++){
			for(int j2=0;j2<nDimension;j2++){
				scanf("%ld",&Matrix[j1][j2]);
				cmpMatrix[nDimension-1-j1][nDimension-1-j2] = Matrix[j1][j2];
			}
			scanf("\n");
		}

		int SymmFlag = 1;

		for(int j5=0;j5<nDimension;j5++){
			for(int j6=0;j6<nDimension;j6++){
				if(Matrix[j5][j6] != cmpMatrix[j5][j6] || Matrix[j5][j6] < 0){
					SymmFlag=0;
					break;
				}
			}
		}
		
		if(SymmFlag){
			printf("Test #%d: Symmetric.\n",i+1);
		}
		else{
			printf("Test #%d: Non-symmetric.\n",i+1);
		}

/*
		for(int j3=0;j3<nDimension;j3++){
			for(int j4=0;j4<nDimension;j4++){
				cout<<Matrix[j3][j4]<<" ";
			}
			cout<<endl;
		}
*/
	}

	return 0;
}
