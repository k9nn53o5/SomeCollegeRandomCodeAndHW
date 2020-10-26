#include <stdio.h>
#include <stdlib.h>

int main(){
	int Narray[100000]={0};
	int N=0;
	int N2array[100000]={0};
	int N2,n;
	int temp;
	int i,i1,i2=0;
	int j1,j2,j3;
	int Msum=0,tempsum=0;
	
	do{
		scanf("%d",&Narray[N]);
		N++;
	}while(Narray[N] != EOF);
	N++;
	printf("\n");
	temp=Narray[0];
	for(i1=0;i1<N-1;i1++){
		if(Narray[i1] * Narray[i1+1] > 0){
			temp+=Narray[i1+1];
		}
		else if(Narray[i1] * Narray[i1+1] <= 0){
			N2array[i2] = temp;
			temp=Narray[i1+1];
			i2++;
		}
	}
	N2 = i2+1;
	if(N2array[0]==N2array[N2-1]){
		N2array[0]+=N2array[N2-1];
		N2array[N2-1]=0;
		N2-1;
	}

	for(j1=0;j1<N2;j1++){
		for(j2=0;j2<N2;j2++){
			for(j3=0+j2;j3 < N2-j1+j2;j3++){
				tempsum+=N2array[j3%N2];		
			}	
			if(Msum <= tempsum){
				Msum = tempsum;
			}
			tempsum=0;
		}
	}
	printf("%d",Msum);
	return 0;
}
