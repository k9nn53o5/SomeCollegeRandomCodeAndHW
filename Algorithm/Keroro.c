#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	struct woodinform{
		int starP;
		int endP;
	};
	typedef struct woodinform wInf;
	int woodNum=0;
	int i,i0,i1,i2,i3,k;

	scanf("%d",&woodNum);
	wInf Woods[woodNum];
	for(i=0;i<woodNum;i++){
		scanf("%d %d",&Woods[i].starP,&Woods[i].endP);
	}
	/*
	for(i=0;i<woodNum;i++){
		printf("%d %d %d\n",i,Woods[i].starP,Woods[i].endP);
	}printf("\n");
 	*/
	int WGraph[woodNum][woodNum];
	for(i0=0;i0<woodNum;i0++){
		for(i1=0;i1<woodNum;i1++){
			if(!(Woods[i0].endP <= Woods[i1].starP || Woods[i0].starP >= Woods[i1].endP
						||i1==i0)){
				WGraph[i0][i1] = 1;
			}
			else{
				WGraph[i0][i1] = 0;
			}			
		}
	}	
	/*
	for(i0=0;i0<woodNum;i0++){
		for(i1=0;i1<woodNum;i1++){
			printf("%d",WGraph[i0][i1]);
		}
		printf("\n");

	}
*/
//	printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	
	int minJump=99999;
	int predecessor[woodNum],iP=0;
	int queue[woodNum+1],iQ=0;  //iQ == num of element in queue
	int visit[woodNum];
	int curP;
	int count=0;
	int layer[woodNum],edgenum=0,l=0,s,curlayn;
	int arr[woodNum],y,y1,y2,y3,Lay=0,m=0;
	int lastwoodlayer,k0;
	for(i=0;i<woodNum;i++){
		queue[i]=-1;
		visit[i]=0;
		arr[i]=-2;
	}
	queue[woodNum]=-1;
	/*
	for(i=0;i<woodNum;i++){
		printf("%d ",queue[i]);
	}
	*/
//	printf("\nXXXXXXXXXXXXXXXXXXXXXXXX\n");
	// touch the goal or be the end
	for(i=0;i<woodNum;i++){
		if(visit[i]==0 && i==0){
			queue[iQ]=i;
			iQ++;
			visit[i]=1;
			arr[0]=i;
/*
			for(i2=0;i2<woodNum;i2++){
				printf("%d",queue[i2]);
			}
			printf("\narr is :");
			for(i2=0;i2<woodNum;i2++){
				printf("%d",arr[i2]);
			}
			printf("\nxxxxxxx\n");
*/
			while(iQ!=0){
				curP = queue[0];
				for(k=0;k<iQ;k++){
					queue[k] = queue[k+1];
				}
				iQ--;

				for(k=0;k<woodNum;k++){
					if(WGraph[curP][k] == 1 && visit[k] != 1){
						queue[iQ] = k;
						iQ++;
						visit[k] = 1;
					}
				}
/*	
				for(i3=0;i3<woodNum;i3++){
					printf("%d ",queue[i3]);
				}
*/
				for(y=0;y<woodNum;y++){
					for(y2=0;y2<woodNum;y2++){
						if(arr[y] == queue[y2] || queue[0] == -1){
							m++;
						}
					}
				}
				if(m==0){
					Lay++;
					for(k0=0;k0<woodNum;k0++){
						if(queue[k0] == woodNum-1){
							lastwoodlayer=Lay;
						}
					}
//					printf("LAY:%d\n",Lay);
					for(y3=0;y3<woodNum;y3++){
						if(queue[y3] != -1){arr[y3] = queue[y3];}
						else{arr[y3]=-2;}
					}
				}
				m=0;

//				printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			}
		}
	}
//	printf("\nwoodnum-1=%d\nlastwoodlayer:%d",woodNum-1,lastwoodlayer);
	printf("%d",lastwoodlayer);
	return 0;
}
