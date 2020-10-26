#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

int recordsum[1000][1000];

int recsum(int i1,int j1,int i2,int j2){
	if(i1==0&&j1==0){
		return recordsum[i1][j1];}	
	else if(i1==0 || i1==i2){
		return  recordsum[i1][j1]-recordsum[i2][j2];}
	else if(j1==0 || j1==j2){
		return recordsum[i1][j1]-recordsum[i2][j2];}
	else {			
		return recordsum[i1][j1] - recordsum[i1][j2] - recordsum[i2][j1] + recordsum[i2][j2];}
}




int main(){

	int n,element;
	while(scanf("%d",&n) == 1){
		int arr2d[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&arr2d[i][j]);
			}
		}
		/*
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr2d[i][j]<<" ";
			}
			cout<<"\n";
		}
		*/
		/*
		   int n=4;
		   int arr2d[n][n];

		   for(int i=0;i<n;i++){
		   for(int j=0;j<n;j++){
		   arr2d[i][j]= ( rand()%3-1 ) * (rand()%100);
		   }

		   }

		   for(int i=0;i<n;i++){
		   for(int j=0;j<n;j++){
		   cout<<setw(3)<<arr2d[i][j]<<" ";
		   }
		   cout<<endl;
		   } 
		 */	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==0&&j==0){
					recordsum[i][j] = arr2d[i][j];}	
				else if(i==0){
					recordsum[i][j] = arr2d[i][j] + recordsum[i][j-1];}
				else if(j==0){
					recordsum[i][j] = arr2d[i][j] + recordsum[i-1][j];}
				else {			
					recordsum[i][j] = arr2d[i][j] + recordsum[i][j-1] + recordsum[i-1][j] - recordsum[i-1][j-1];}
			}
		}
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(max<arr2d[i][j]){
					max=arr2d[i][j];
				}
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(max<recordsum[i][j]){
					max=recordsum[i][j];
				}
			}
		}

		for(int i1=0;i1<n;i1++){
			for(int j1=0;j1<n;j1++){
				for(int i2=0;i2<=i1 ;i2++){
					for(int j2=0;j2<=j1 ;j2++){
						if(max < recsum(i1,j1,i2,j2) ){
							max = recsum(i1,j1,i2,j2);
						}
					}
				}
			}
		}

		/*
		   cout<<endl;
		   for(int i=0;i<n;i++){
		   for(int j=0;j<n;j++){
		   cout<<setw(3)<<recordsum[i][j]<<" ";
		   }
		   cout<<endl;
		   }

		   cout<<endl;

		 */
		cout<<max;
	}
	return 0;
} 





