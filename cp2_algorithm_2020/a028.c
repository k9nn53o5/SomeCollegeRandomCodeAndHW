#include <stdio.h>

int ans2po(int ans,int* arr,int n);
void logicTranform(int* arr,int n);

int main(){
	int n;
	int i=0;
	scanf("%d\n",&n);
	int ans[n];
	for(;i<n;i++){
		scanf("%d",&ans[i]);
	}
	logicTranform(ans,n);
	/*
	for(i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	*/
	while(1){
		int stuAns[n];
		int dpArr[n];
		int breakFlag=0;
		for(i=0;i<n;i++){
			if(scanf("%d ",&stuAns[i]) == EOF){breakFlag=1;break;}
			dpArr[i]=1;
		}
		logicTranform(stuAns,n);
		/*
		for(i=0;i<n;i++){
			printf("%d ",stuAns[i]);
		}
		printf("\n");
		*/
		if(breakFlag==1){break;}
		for(i=1;i<n;i++){
			int j;
			for(j=0;j<i;j++){
				if(ans2po(stuAns[i],ans,n) > ans2po(stuAns[j],ans,n) && dpArr[j]+1 > dpArr[i]){
					dpArr[i] = dpArr[j] + 1;
				}
			}	
		}

		int score=-1;
		for(i=0;i<n;i++){
			if(dpArr[i] > score){
				score = dpArr[i];
			}
		}
		printf("%d\n",score);

/*
		for(i=0;i<n;i++){
			printf("%d ",dpArr[i]);
		}
		*/
	//	printf("\n");
	
	}
	
		return 0;
}

int ans2po(int stuans,int* arr,int n){
		int i=0;
		for(;i<n;i++){
			if(arr[i] == stuans){
				return i;
			}
		}
		return -1;
}

void logicTranform(int* arr,int n){
	int tmpArr[n];
	int i;
	for(i=0;i<n;i++){
		tmpArr[arr[i]-1]=ans2po(arr[i],arr,n);
	}
	for(i=0;i<n;i++){
		arr[i]=tmpArr[i];
	}
	return ;
}

