#include <stdlib.h>
#include <stdio.h>

int carry(int x,int y,int **mat,int **rec,int r,int c);
int draw(int x,int y,int **mat,int **recd,int R,int C);

int main(){
	int row,col;
	int i0,i1,i2,j,j1;
	int max=0,com=0;
	scanf("%d %d",&row,&col);
	int **matrix=(int **)malloc(row*sizeof(int));
	int **record=(int **)malloc(row*sizeof(int));
	for(i0=0;i0<row;i0++){
		matrix[i0] = (int*)malloc(col*sizeof(int));
		record[i0] = (int*)malloc(col*sizeof(int));
	}
	for(i1=0;i1<row;i1++){
		for(i2=0;i2<col;i2++){
			scanf("%d",&matrix[i1][i2]);
			record[i1][i2]=0;
		}
	}

	for(i1=0;i1<row;i1++){
		for(i2=0;i2<col;i2++){
			printf("%d",matrix[i1][i2]);
		}
		printf("\n");
	}
	printf("\n");
	for(j=0;j<row;j++){
		for(j1=0;j1<col;j1++){
			if(record[j][j1]==0){
				com = draw(j1,j,matrix,record,row,col);
				//printf("row%dcol%d com%d   ",j,j1,com);
				if(max < com){
					max = com;
					printf("->max:%d    ",max);
				}
			}
		}
	}  

	printf("%d",max);
return 0;
}

int check(int a,int b,char dir,int **ma,int **rec,int r,int c){
												
	if(dir == 'l'){
		if(a-1<0){
			return -1;
		}
		else if(rec[b][a-1]==-1 || ma[b][a] != ma[b][a-1]){
			return -1;
		}	
		else{
			return 0;
		}
	}
	else if(dir == 'r'){
	   	if(a+1>c-1){
			return -1;
		}
		else if( rec[b][a+1]==-1 || ma[b][a] != ma[b][a+1]){
			return -1;
		}
		else{
			return 0;
		}
	}
	else if(dir == 'u'){ 
		if(b-1<0){
			return -1;
		}
		else if(rec[b-1][a]==-1 || ma[b][a] != ma[b-1][a]){
			return -1;	
		}	
		else{
			return 0;
		}
	}
	else if(dir == 'd'){
   		if(b+1>r-1){
			return -1;
		}	
		else if(rec[b+1][a]==-1 || ma[b][a] != ma[b+1][a]){
			return -1;
		}
		else{
			return 0;
		}
	}
}
int draw(int x,int y,int **mat,int **recd,int R,int C){
	int carry=1;
	int u=0;
	recd[y][x]=-1;
	while(!(check(x,y,'l',mat,recd,R,C)==-1 && check(x,y,'r',mat,recd,R,C)==-1 && 
		   	check(x,y,'u',mat,recd,R,C)==-1 && check(x,y,'d',mat,recd,R,C)==-1)){
		if(check(x,y,'l',mat,recd,R,C)==0){
			carry+=draw(x-1,y,mat,recd,R,C);
		}
		if(check(x,y,'r',mat,recd,R,C)==0){
			carry+=draw(x+1,y,mat,recd,R,C);
		}
		if(check(x,y,'u',mat,recd,R,C)==0){
			carry+=draw(x,y-1,mat,recd,R,C);
		}
		if(check(x,y,'d',mat,recd,R,C)==0){
			carry+=draw(x,y+1,mat,recd,R,C);
		}
		u++;
		if(u>500){
			break;
		}
	}
	return carry;
}
