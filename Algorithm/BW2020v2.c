#include<stdio.h>
int M=0;
int N=0;
int dfs(int x ,int y,int g[][1000],int s[][1000]){
	int b1=0;
	int b2=0;
	int b3=0;
	int b4=0;
	if(s[y][x]==0){
		s[y][x]=2; 

		if( g[y][x]==g[y][x+1] && x+1 < M  && s[y][x+1]==0 ){
			b1 =  dfs(x+1,y,g,s); 
		}

		if( g[y][x]==g[y][x-1]  && x-1 >= 0 && s[y][x-1]==0){
			b2 =  dfs(x-1,y,g,s);
		}

		if(g[y][x]==g[y+1][x] && y+1 < N && s[y+1][x]==0){
			b3 =  dfs(x,y+1,g,s);		
		}

		if(g[y][x]==g[y-1][x] &&  y-1 >= 0  && s[y-1][x]==0){
			b4 =  dfs(x,y-1,g,s);

		}	
		return 1 + b1 + b2 + b3 + b4;
	}

	else if(s[y][x]==2){
		return 0;
	}

}

int main(){
	int img[1000][1000]={0};    
	int record[1000][1000]={0};

	scanf("%d %d",&N,&M);
	int i=0;
	int k=0;
	int Max_a=0;
	int new=0;
	for(i=0;i<N;i++){
		for(k=0;k<M;k++){
			scanf("%d",&img[i][k]);
		}
	}	

	for(i=0;i<N;i++){
		for(k=0;k<M;k++){
			new = dfs(k,i,img,record);
			if(new>Max_a){Max_a = new;}  
		}
	}	
	printf("%d",Max_a);
	return 0;
}

