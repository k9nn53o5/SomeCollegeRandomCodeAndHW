#include <stdlib.h>
#include <stdio.h>

int matrix[1000][1000];
int record[1000][1000];

int main(){
	int row,col;
	int i0,i1,i2;
	int carry(int x,int y){

	}
	int draw(int x,int y){

	}
	
	scanf("%d %d",&row,&col);
	for(i1=0;i1<row;i1++){
		for(i2=0;i2<col;i2++){
			scanf("%d",&matrix[i1][i2]);
		}
	}
	for(i1=0;i1<row;i1++){
		for(i2=0;i2<col;i2++){
			printf("%d",matrix[i1][i2]);
		}
		printf("\n");
	}
	/*
	i0=draw(0,1,matrix,record,row,col);
	printf("%d\n",i0);

	for(i1=0;i1<row;i1++){
		for(i2=0;i2<col;i2++){
			printf("%d",record[i1][i2]);
		}
		printf("\n");
}	*/
return 0;
}
int check(int a,int b,char dir,int **ma,int **rec,int r,int c){			// coner edge middle // l r u d
												//wall or done -1 not yet 0
	if(dir == 'l'){
		if(x-1<0){
			return -1;
		}
		else if(record[x-1][y]==-1 || matrix[x][y] != matrix[x-1][y]){
			return -1;
		}	
	}
	else if(dir == 'r'){
	   	if(x+1>col-1){
			return -1;
		}
		else if( record[x+1][y]==-1 || matrix[x][y] != matrix[x+1][y]){
			return -1;
		}
	}
	else if(dir == 'u'){ 
		if(y-1<0){
			return -1;
		}
		else if(record[x][y-1]==-1 || matrix[x][y] != matrix[x][y-1]){
			return -1;	
		}	
	}
	else if(dir == 'd'){
   		if(y+1>r-1){
			return -1;
		}	
		else if(record[x][y+1]==-1 || matrix[x][y] != matrix[x][y+1]){
			return -1;
		}
	}
	else{
		return 0;
	}
}

int draw(int x,int y,int **mat,int **recd,int R,int C){
	int carry=1;
	recd[x][y]=-1;
	printf("ininin");
	while(check(x,y,'l',mat,recd,R,C)==-1 && check(x,y,'r',mat,recd,R,C)==-1 && 
		   	check(x,y,'u',mat,recd,R,C)==-1 && check(x,y,'d',mat,recd,R,C)==-1){
		printf("a");
		if(check(x,y,'l',mat,recd,R,C)==0){
			carry+=draw(x-1,y,mat,recd,R,C);
			printf("l");
		}
		if(check(x,y,'r',mat,recd,R,C)==0){
			carry+=draw(x+1,y,mat,recd,R,C);
			printf("r");	
		}
		if(check(x,y,'u',mat,recd,R,C)==0){
			carry+=draw(x,y-1,mat,recd,R,C);
			printf("u");
		}
		if(check(x,y,'d',mat,recd,R,C)==0){
			carry+=draw(x,y+1,mat,recd,R,C);
			printf("d");	
		}

//	recd[x][y]=-1;

	
	}
	return carry;
}

































































