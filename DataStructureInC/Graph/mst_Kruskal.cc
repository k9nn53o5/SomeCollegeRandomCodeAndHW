#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

#define inf_p 10e8
#define inf_n -10e8


bool all_connected(vector<int>* set);
int findRoot(vector<int>* set,int x);
void union2p(vector<int>* set,int a,int b);
void mk_mst(int** G,int** mst,int max,int n);



int main(){
	int n,max;
	scanf("%d",&n);
	scanf("%d",&max);	
	cout<<"n:"<<n<<"  max:"<<max<<endl;

	int** G = (int** )malloc((max+1) * sizeof(int*));
	for(int i=0;i<max+1;i++){
		G[i] = (int*)malloc((max+1) * sizeof(int));
	}
	for(int i=0;i<max+1;i++){
		for(int j=0;j<max+1;j++){
			G[i][j] = inf_p;
		}
	}


	int start,end,dis;	
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&start,&end,&dis);
		printf("start end dis:%d %d %d\n",start,end,dis);
		G[start][end] = dis;
	}

	cout<<"Graph:"<<endl;
	for(int i=0;i<max+1;i++){
		for(int j=0;j<max+1;j++){
			if(G[i][j] == inf_p){
				printf(" x ");
				continue;
			}	
			printf("%2d ",G[i][j]);				
		}
		cout<<endl;
	}
	cout<<endl;


	int** mst = (int** )malloc((max+1) * sizeof(int*));
	for(int i=0;i<max+1;i++){
		mst[i] = (int*)malloc((max+1) * sizeof(int));
	}
	for(int i=0;i<max+1;i++){
		for(int j=0;j<max+1;j++){
			mst[i][j] = inf_p;
		}
	}

	mk_mst(G,mst,max,n);



	cout<<"min spanning tree:"<<endl;
	for(int i=0;i<max+1;i++){
		for(int j=0;j<max+1;j++){
			if(mst[i][j] == inf_p){
				printf(" x ");
				continue;
			}	
			printf("%2d ",mst[i][j]);				
		}
		cout<<endl;
	}
	cout<<endl;


	return 0;
}


//bug can't have 2 or more road connect the same points a and b

//some disjoint function forest

bool all_connected(vector<int>* set){
	//all the node in forest are connected into one tree
	for(int i=0;i < set->size()-1;i++){
		if(set[i] != set[i+1]){
			return false;
		}
	}
	return true;
}

int findRoot(vector<int>* set,int x){
	//find the sub min spanning root of the node
	//amortized the findRoot function

	if((*set)[x] == x){
		return (*set)[x];
	}
	else{
		(*set)[x] = findRoot(set ,(*set)[x]);
		return (*set)[x];
	}
}

void union2p(vector<int>* set,int a,int b){
//merge two sub trees that contain a and contain b
//notice that have to connect twoo roots of sub tree
//not other point or the set(forest) array won't be correct
	(*set)[findRoot(set,a)] = findRoot(set,b);	
}

void mk_mst(int** G,int** mst,int max,int n){
	// initialize disjoint set forest to carry sub min spanning tree
	vector<int> forest(max+1,-1);
	for(int i=0;i<max+1;i++){
		forest[i] = i;
	}

	cout<<"forest:"<<endl;
	for(int i=0;i<max+1;i++){
		cout<<forest[i]<<" ";
	}
	cout<<endl;

	// sort the edge  
	// fir row start p
	// sec row end p
	// third row dis
	vector<vector<int> > sortedE(3);

	for(int i=0;i<3;i++){
		sortedE[i] = vector<int>(n);
		for(int j=0;j<n;j++){
			sortedE[i][j] = 0;
		}
	}

	int k=0;
	for(int i=0;i<max+1;i++){
		for(int j=0;j<max+1;j++){

			if(k>n){printf("error:k>n");return;}
			if(G[i][j] != inf_p){
				sortedE[0][k] = i;
				sortedE[1][k] = j;
				sortedE[2][k] = G[i][j];
				k++;
			}


		}	
	}
	cout<<k<<endl;	
	cout<<"unsorted edge:"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			printf("%2d ",sortedE[i][j]);
		}
		cout<<endl;
	}

	//sort the edge in sortedE
	//with bubble sort :-)
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(sortedE[2][j] > sortedE[2][j+1]){
				int temp1 = sortedE[0][j];
				int temp2 =	sortedE[1][j];
				int temp3 = sortedE[2][j];
				sortedE[0][j] = sortedE[0][j+1];
				sortedE[1][j] = sortedE[1][j+1];
				sortedE[2][j] = sortedE[2][j+1];
				sortedE[0][j+1] = temp1;
				sortedE[1][j+1] = temp2;
				sortedE[2][j+1] = temp3;
			}
		}
	}	


	cout<<k<<endl;	
	cout<<"sorted edge:"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			printf("%2d ",sortedE[i][j]);
		}
		cout<<endl;
	}
	// try all the edge in sorted order to find mst
	// (1) if start end points are at different sub min spanning trees
	//	connect start and end point
	//	and there will be a bigger subtree
	// (2) if start end points are at the same sub spanning tree
	// there will be a cycle if connect 2 points
	// so don't connect it

//	while(!all_connected(&forest)){
		printf("forest:");
		for(int k=0;k<max+1;k++){
			cout<<forest[k]<<" ";
		}
		cout<<endl;
		for(int i=0;i<n ;i++){
			if(findRoot(&forest,sortedE[0][i]) != findRoot(&forest,sortedE[1][i])){
				//draw this edge on mst
				mst[ sortedE[0][i] ][ sortedE[1][i] ] = sortedE[2][i];
				//now connect two point(merge 2 sub tree to a bigger one)
				union2p(&forest,sortedE[0][i],sortedE[1][i]);
			}

		printf("forest:");
		for(int k=0;k<max+1;k++){
			cout<<forest[k]<<" ";
		}
		cout<<endl;
		}	
//	}


	return;
}
