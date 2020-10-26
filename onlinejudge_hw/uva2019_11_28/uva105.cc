#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int start,h,end;
	int arr[10001]={0};
	while(scanf("%d %d %d",&start,&h,&end)!=EOF){
		for(int i=start+1;i<=end;i++){
			if(h>arr[i]){
				arr[i]=h;
			}
		}
	}
	int curh=0;
	int count=0;
	for(int i=1;i<10001;i++){
		if(arr[i] > curh){
			if(count == 0){
				cout<<i-1<<" "<<arr[i];
				count++;
			}
			else{
				cout<<" "<<i-1<<" "<<arr[i];
			}
			curh=arr[i];
		}
		else if(arr[i] < curh){
			if(count == 0){
				cout<<i-1<<" "<<arr[i];
				count++;
			}
			else{	
				cout<<" "<<i-1<<" "<<arr[i];
			}
			curh=arr[i];
		}

	}
	cout<<"\n";
	return 0;
} 
