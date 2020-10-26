#include <stdio.h>
#include <stdlib.h>

/*input a graph that have n edges with max key num

  3               <- n
  3               <- max key number
  0 1             <- edge 0-1
  1 2
  1 3

=>
  0
  |
  1
  |\
  2 3

 */

#define empty -10e8

int* mkqueue(){
	int* arr = (int*)malloc(200*sizeof(int));
	int i;
	for(i=0;i<200;i++){arr[i] = empty;}
	return arr;	
}

void enqueue(int* arr,int val){
	int i=0,length=0;
	while(arr[i] != empty){
		length++;
		i++;
	}
	arr[length]=val;
}

int dequeue(int* arr){
	int i=0,length=0;
	while(arr[i] != empty){
		length++;
		i++;
	}
	int temp = arr[0];
	for(i=0;i<length-1;i++){
		arr[i] = arr[i+1];
	}
	arr[length-1] = empty;
	return temp;
}

void bfs(int** g,int s,int max){
	//in graph 0 means not connect, 1 means connect
	int visitrec[200+1]={0};
	int* Q = mkqueue();
	enqueue(Q,s);
	visitrec[s]=1;

	int i;
	while(Q[0] != empty){
		int v = dequeue(Q);
		printf("%d ",v);

		for(i=0;i<max+1;i++){
			if(g[v][i] == 1 && visitrec[i] == 0){
				enqueue(Q,i);

				visitrec[i] = 1;
			}
		}
	}

	free(Q);
}

int* mkstack(){
	int* arr = (int*)malloc(200*sizeof(int));
	int i;
	for(i=0;i<200;i++){
		arr[i] = empty;
	}
	return arr;
}

void pushstack(int* arr,int val){
	int length=0;
	int i=0;
	while(arr[i] != empty){
		length++;
		i++;
	}
	arr[length] = val;
}

int popstack(int* arr){	
	int length=0;
	int i=0;
	while(arr[i] != empty){
		length++;
		i++;
	}
	int temp = arr[length-1];
	arr[length-1] = empty;
	return temp;
}

void dfs(int** g,int s,int max){
	int visitrec[201]={0};
	int* stack = mkstack();
	pushstack(stack,s);

	int i;
	while(stack[0] != empty){
		int v = popstack(stack);
		if(visitrec[v] == 0){
			visitrec[v] = 1;

			printf("%d ",v);
			for(i=0;i<max+1;i++){
				if(g[v][i]==1){
					pushstack(stack,i);
				}
			}
		}
	}
	free(stack);
}
int main(){

	printf("Input tree will look like this:\n    0\n   /| \\ \n  1 2  3 \n /| |\\ / \n4 5 6 7\n\n");


	int n,i,j,max;
	scanf("%d",&n);
	scanf("%d",&max);

	//intial a 2d array graph with all number is 0
	int** graph = (int** )malloc((max+1)*sizeof(int*));
	for(i=0;i<max+1;i++){
		graph[i] = (int*)malloc((max+1)*sizeof(int));
	}
	for(i=0;i<max+1;i++){
		for(j=0;j<max+1;j++){
			graph[i][j] = 0;
		}
	}

	//put edge into graph
	int start,end;
	for(i=0;i<n;i++){
		scanf("%d %d",&start,&end);
		graph[start][end]=1;
		graph[end][start]=1;
	}


	for(i=0;i<max+1;i++){
		for(j=0;j<max+1;j++){
			printf("%2d ",graph[i][j]);
		}
		printf("\n");
	}
	//bfs the graph
	
	printf("\n\nBFS with source is 0:\n");
	int s=0;
	bfs(graph,s,max);
	//dfs the graph
	
	printf("\n\nDFS with source is 0:\n");
	int s2=0;
	dfs(graph,s2,max);

	printf("\n\n");

	return 0;
}
