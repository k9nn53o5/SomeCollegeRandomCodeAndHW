#include <iostream>
using namespace std;

int graph[25][25];
int dist[25];

void initg(void);
void initd(void);

inline int  maxldij(int begin,int num,int n){
	int selected[n];
	int max;
	int s;
	int maxout=0;

	for(int i=1;i<=num;i++){
		selected[i]=0;
		dist[i]=graph[begin][i];
	}
	selected[begin]=1;
	dist[begin]=0;

	for(int i=0;i<num;i++){
		max=0;
		for(int j=1;j<num;j++){
			if(max<dist[j]&&selected[j]==0){
				s=j;
				max=dist[j];
				if(maxout<dist[j]){
					maxout=dist[j];
				}
			}

		}
		selected[s]=1;

		for(int j=0;j<num;j++){
			if(selected[j] ==0 && dist[s] + graph[s][j]>dist[j]){
				dist[j] = dist[s] + graph[s][j];
			}
			if(maxout<dist[j]){
				maxout=dist[j];
			}

		}

	}
	return maxout;

}

int main() {
	int n,m,output=0;
	while(scanf("%d %d",&n,&m)!= EOF){
		initg();
		initd();
		if(n==0&&m==0){
			break;
		}
		
		for(int i=0;i<m;i++){
			int node1,node2;
			scanf("%d %d",&node1,&node2);
			graph[node1][node2]++;
			graph[node2][node1]++;
		}

		for(int i=0;i<n;i++){

			if(output<maxldij(i,n,n)){
				output=maxldij(i,n,n);

			}
		}

				cout<<output<<endl;
		
				output=0;
	}

	return 0;
}


void initg(void){
	for(int i=0;i<25;i++){
		for(int j=0;j<25;j++){
			graph[i][j]=0;
		}
	}
	return;
}


void initd(void){
	for(int i=0;i<25;i++){
		dist[i]=0;
	}
	return;
}
