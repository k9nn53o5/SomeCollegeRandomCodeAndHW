#include <stdio.h>
#include <stdlib.h>

int main(){
	int M,N,i1,i2,i3,temp,max,count=0;
	scanf("%d %d",&M,&N);
	int height[N][M];
	for(i1=0;i1<M;i1++){
		for(i2=0;i2<N;i2++){
			scanf("%d",&height[i2][i1]);			//height[x][y]
		}
	}

	for(i1=0;i1<M;i1++){
		for(i2=0;i2<N;i2++){
			temp=height[i2][i1];
			for(i3=i2;i3<N;i3++){
				if(height[i3][i1] <= height[i2][i1]){
					height[i2][i1]=height[i3][i1];
					max=i3;
				}
			}
			height[max][i1]=temp;
		}
	}

	for(i1=0;i1<M;i1++){
		for(i2=0;i2<N;i2++){
			printf("%d ",height[i2][i1]);			//height[x][y]
		}
		printf("\n");
	}

	printf("\n");
	
	int graph[M][M];

	for(i1=0;i1<M;i1++){
		for(i2=0;i2<M;i2++){
			graph[i2][i1]=0;
		}
	}	
	for(i1=0;i1<M;i1++){	
		for(i2=0;i2<M;i2++){
			for(i3=0;i3<N;i3++){
				if(height[i3][i1] > height[i3][i2] && i1 != i2){
					count++;
				}
			}
			printf("%d ",count);
			if(count==N){
				graph[i2][i1]=1;
			}
			else{
				graph[i2][i1]=0;
			}
			count=0;
		}
	}
	
	printf("\n\n");
	for(i1=0;i1<M;i1++){
		for(i2=0;i2<M;i2++){
			printf("%d ",graph[i2][i1]);
		}
		printf("\n");
	}
	printf("\n");
	
	int visit[M];
	int queue[M],l=0,curV;
	int j,j0,j1,j2,j3,j4,j5,k,s;
	int maxlen=0,MaxLen=0,i=0;
	for(j0=0;j0<M;j0++){
		visit[j0]=0;
		queue[j0]=-1;
	}
	
	for(j1=0;j1<M;j1++){
		if(visit[j1] != 1){
			queue[l]=j1;
			l++;
//			for(j4=0;j4<M;j4++){
//				printf("%d ",queue[j4]);
//			}
			printf("\n");
			visit[j1]=1;
			while(queue[0]!=-1){
				for(s=0;s<M;s++){
					printf("%d",queue[s]);
				}
				printf("\n");
				curV = queue[0];
				for(j2=0;j2<M;j2++){
					if(j2 != M-1){
						queue[j2]=queue[j2+1];
					}
					else{
						queue[j2]=-1;
					}
				}
				l--;
			
				for(j3=0;j3<M;j3++){
					if(graph[j3][curV]==1){
						queue[l]=j3;
						l++;
						visit[j3]=1;
					}
				}
			}

		
		}
		
		for(k=0;k<M;k++){
				visit[k]=0;
		}
	}
	return 0;
}
